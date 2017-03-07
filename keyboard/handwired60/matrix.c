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
 *  col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 *  pin: PD7 PB4 PB5 PB6 PF7 PC6 PD3 PD2 PD1 PD0 PB7 PB3 PB2 PB1
 */
static void  init_cols(void)
{
    // Input with pull-up(DDR:0, PORT:1)
    DDRB  &= ~(1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTB |=  (1<<7 | 1<<6 | 1<<5 | 1<<4 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    DDRC  &= ~(1<<6);
    PORTC |=  (1<<6);
    DDRD  &= ~(1<<7 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    PORTD |=  (1<<7 | 1<<3 | 1<<2 | 1<<1 | 1<<0);
    DDRF  &= ~(1<<7);
    PORTF |=  (1<<7);
}

/* Column pin configuration
 *  col: 0   1   2   3   4   5   6   7   8   9   10  11  12  13
 *  pin: PD7 PB4 PB5 PB6 PF7 PC6 PD3 PD2 PD1 PD0 PB7 PB3 PB2 PB1
 */
static matrix_row_t read_cols(void)
{
    return (PIND&(1<<7) ? 0 : (1<<0)) |
      (PINB&(1<<4) ? 0 : (1<<1)) |
      (PINB&(1<<5) ? 0 : (1<<2)) |
      (PINB&(1<<6) ? 0 : (1<<3)) |      
      (PINF&(1<<7) ? 0 : (1<<4)) |
      (PINC&(1<<6) ? 0 : (1<<5)) |
      (PIND&(1<<3) ? 0 : (1<<6)) |
      (PIND&(1<<2) ? 0 : (1<<7)) |
      (PIND&(1<<1) ? 0 : (1<<8)) |
      (PIND&(1<<0) ? 0 : (1<<9)) |
      (PINB&(1<<7) ? 0 : (1<<10)) |
      (PINB&(1<<3) ? 0 : (1<<11)) |
      (PINB&(1<<2) ? 0 : (1<<12)) |
      (PINB&(1<<1) ? 0 : (1<<13)) |
      (PINB&(1<<0) ? 0 : (1<<14));
}

/* Row pin configuration
 * row: 0   1   2   3   4  
 * pin: PF0 PF1 PF4 PF5 PF6
 */
static void unselect_rows(void)
{
    DDRF  &= ~0b01110011;
    PORTF &= ~0b01110011;
}


/* Row pin configuration
 * row: 0   1   2   3   4  
 * pin: PF0 PF1 PF4 PF5 PF6
 */
static void select_row(uint8_t row)
{
    // Output low(DDR:1, PORT:0) to select
        switch (row) {
            case 0:
              DDRF  |= (1<<0);
              PORTF &= ~(1<<0);
              break;
            case 1:
              DDRF  |= (1<<1);
              PORTF &= ~(1<<1);
              break;
            case 2:
              DDRF  |= (1<<4);
              PORTF &= ~(1<<4);
              break;
            case 3:
              DDRF  |= (1<<5);
              PORTF &= ~(1<<5);
              break;
            case 4:
              DDRF  |= (1<<6);
              PORTF &= ~(1<<6);
              break;
    }
}
