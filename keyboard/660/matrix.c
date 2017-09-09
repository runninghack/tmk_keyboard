/*
 * scan matrix
 */
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#ifdef PS2_MOUSE_ENABLE
#include "ps2.h"
#endif


#ifndef DEBOUNCE
#   define DEBOUNCE	5
#endif
static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static matrix_row_t read_cols(void);
static void init_cols(void);
static void unselect_rows(void);
static void select_row(uint8_t row);

#ifdef PS2_MOUSE_ENABLE
static uint8_t ps2_mouse_detected;

uint8_t ps2_enabled(void)
{
    return ps2_mouse_detected;
}
#endif

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // disable JTAG
    MCUCR = (1<<JTD);
    MCUCR = (1<<JTD);

    // initialize row and col
    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);
#ifdef HYBRID_MATRIX
        init_cols();
#endif
        _delay_us(30);  // without this wait read unstable value.
        matrix_row_t cols = read_cols();
        if (matrix_debouncing[i] != cols) {
            matrix_debouncing[i] = cols;
            if (debouncing) {
                debug("bounce!: "); debug_hex(debouncing); debug("\n");
            }
            debouncing = DEBOUNCE;
        }
        unselect_rows();
    }

    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

/* Column pin configuration
 * pin: F5  F4  F1  F0  B0  B4  D0  D1  D2  D3  D5  D4  D6  D7  
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRF  &= ~(1<<PF5 | 1<<PF4 |1<<PF1 | 1<<PF0);
    PORTF |=  (1<<PF5 | 1<<PF4 |1<<PF1 | 1<<PF0);
    DDRD  &= ~(1<<PD7 | 1<<PD6 | 1<<PD5 | 1<<PD4 | 1<<PD3 | 1<<PD2 | 1<<PD1 | 1<<PD0);
    PORTD |=  (1<<PD7 | 1<<PD6 | 1<<PD5 | 1<<PD4 | 1<<PD3 | 1<<PD2 | 1<<PD1 | 1<<PD0);
    DDRB  &= ~(1<<PB4 | 1<<PB0);
    PORTB |=  (1<<PB4 | 1<<PB0);
}

/* Column pin configuration
 * col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 * pin: F5  F4  F1  F0  B0  B4  D0  D1  D2  D3  D5  D4  D6  D7  
 */
static matrix_row_t read_cols(void)
{
    return (PINF & (1<<5) ? 0 : (1<< 0)) |
            (PINF & (1<<4) ? 0 : (1<< 1)) |
            (PINF & (1<<1) ? 0 : (1<< 2)) |
            (PINF & (1<<0) ? 0 : (1<< 3)) |
            (PINB & (1<<0) ? 0 : (1<< 4)) |
            (PINB & (1<<4) ? 0 : (1<< 5)) |
            (PIND & (1<<0) ? 0 : (1<< 6)) |
            (PIND & (1<<1) ? 0 : (1<< 7)) |
            (PIND & (1<<2) ? 0 : (1<< 8)) |
            (PIND & (1<<3) ? 0 : (1<< 9)) |
            (PIND & (1<<5) ? 0 : (1<<10)) |
            (PIND & (1<<4) ? 0 : (1<<11)) |
            (PIND & (1<<6) ? 0 : (1<<12)) |
            (PIND & (1<<7) ? 0 : (1<<13));
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: E6  B3  B2  B1  B5
 */
static void unselect_rows(void)
{
    // Hi-Z(DDR:0, PORT:0) to unselect
    DDRE  &= ~0b01000000;
    PORTE &= ~0b01000000;
    DDRB  &= ~0b00101110;
    PORTB &= ~0b00101110;
}

static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRE  |= (1<<6);
            PORTE &= ~(1<<6);
            break;
        case 1:
            DDRB  |= (1<<3);
            PORTB &= ~(1<<3);
            break;
        case 2:
            DDRB  |= (1<<2);
            PORTB &= ~(1<<2);
            break;
        case 3:
            DDRB  |= (1<<1);
            PORTB &= ~(1<<1);
            break;
        case 4:
            DDRB  |= (1<<5);
            PORTB &= ~(1<<5);
            break;
    }
}
