#include <avr/io.h>
#include <util/delay.h>

#define GET_BIT(TGT, PIN) ((TGT) & (1 << (PIN))) 
#define SET_BIT(TGT, PIN) do { TGT |= (1 << (PIN)); } while(0)
#define CLEAR_BIT(TGT, PIN) do { TGT &= ~(1 << (PIN)); } while(0)
#define TOGGLE_BIT(TGT, PIN) do { TGT ^= (1 << (PIN)); } while(0)

#define LED0    (PB0)
#define LED1    (PB2)

// Set LED lines as output
void setup_pins(void) {
    SET_BIT(DDRB, LED0);
    SET_BIT(DDRB, LED1);
}

int main(void)
{
    setup_pins();
    while(1) {
        PORTB = 0xff;
        _delay_us(600);
        PORTB = 0;
        _delay_us(1200);
    }
}
