#include <avr/io.h>
#include <util/delay.h>

#define GET_BIT(TGT, PIN) ((TGT) & (1 << (PIN))) 
#define SET_BIT(TGT, PIN) do { TGT |= (1 << (PIN)); } while(0)
#define CLEAR_BIT(TGT, PIN) do { TGT &= ~(1 << (PIN)); } while(0)
#define TOGGLE_BIT(TGT, PIN) do { TGT ^= (1 << (PIN)); } while(0)

#define LED0    PB0
#define LED1    PB1
#define LED2    PB2

// Set LED lines as output
void setup_pins(void) {
    SET_BIT(DDRB, PB0);
    SET_BIT(DDRB, PB1);
    SET_BIT(DDRB, PB2);
}

int main(void)
{
    setup_pins();
    while(1) {
        PORTB = LED0 | LED1 | LED2;
        _delay_ms(1);
        PORTB = 0;
        _delay_ms(1);
    }
}
