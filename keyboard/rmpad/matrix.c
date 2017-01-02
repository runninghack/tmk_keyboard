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

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

/* Column pin configuration
 *  col: 0   1   2   3
 *  pin: PB6 PB2 PB2 PB1
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRB  &= ~(1<<PB1 | 1<<PB3 | 1<<PB2 | 1<<PB6);
    PORTB |=  (1<<PB1 | 1<<PB3 | 1<<PB2 | 1<<PB6);
}

/* Column pin configuration
 *  col: 0   1   2   3
 *  pin: PB6 PB2 PB2 PB1
 */
static matrix_row_t read_cols(void)
{
    return (PINB&(1<<PB1) ? 0 : (1<<3)) |
               (PINB&(1<<PB3) ? 0 : (1<<2)) |
               (PINB&(1<<PB2) ? 0 : (1<<1)) |
               (PINB&(1<<PB6) ? 0 : (1<<0));
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: PC6 PD2 PE6 PB4 PB5
 */
static void unselect_rows(void)
{
    DDRD  &= ~0b10000000;
    PORTD &= ~0b10000000;
    
    DDRC  &= ~0b01000000;
    PORTC &= ~0b01000000;
    
    DDRB  &= ~0b00110000;
    PORTB &= ~0b00110000;
    
    DDRE  &= ~0b01000000;
    PORTE &= ~0b01000000;
}

/* Row pin configuration
 * row: 0   1   2   3   4
 * pin: PC6 PD2 PE6 PB4 PB5
 */
static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
    switch (row) {
        case 0:
            DDRC  |= (1<<6);
            PORTC &= ~(1<<6);
            break;
        case 1:
            DDRD  |= (1<<7);
            PORTD &= ~(1<<7);
            break;
        case 2:
            DDRE  |= (1<<6);
            PORTE &= ~(1<<6);
            break;
        case 3:
            DDRB  |= (1<<4);
            PORTB &= ~(1<<4);
            break;
        case 4:
            DDRB  |= (1<<5);
            PORTB &= ~(1<<5);
            break;
    }
}
