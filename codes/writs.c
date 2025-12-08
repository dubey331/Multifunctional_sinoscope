#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 16000000UL  // 16 MHz clock
#define SERVO_MIN 1000    // 1ms pulse width (0°)
#define SERVO_MAX 2000    // 2ms pulse width (180°)
#define STEP_DEGREE 10
#define BUTTON_CW_PIN  PD4
#define BUTTON_CCW_PIN PD5

volatile uint16_t pulse_width = SERVO_MIN;  // Start at 0°

void timer1_init() {
    // Set Pin 9 (PB1/OC1A) as output
    DDRB |= (1 << PB1);

    // Set Timer1 to Fast PWM, Mode 14 (ICR1 as TOP), non-inverting
    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
    TCCR1B |= (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8

    ICR1 = 20000; // 20ms period (50Hz)
    OCR1A = pulse_width;
}

void update_servo(uint16_t angle) {
    // Map angle (0–180) to pulse width (1000–2000us)
    pulse_width = SERVO_MIN + ((SERVO_MAX - SERVO_MIN) * angle) / 180;
    OCR1A = pulse_width;
}

uint8_t is_pressed(uint8_t pin) {
    return !(PIND & (1 << pin)); // Active LOW
}

int main(void) {
    DDRD &= ~((1 << BUTTON_CW_PIN) | (1 << BUTTON_CCW_PIN)); // Set pins as input
    PORTD |= (1 << BUTTON_CW_PIN) | (1 << BUTTON_CCW_PIN);   // Enable pull-up resistors

    timer1_init();

    uint8_t angle = 0;
    update_servo(angle);

    while (1) {
        if (is_pressed(BUTTON_CW_PIN) && angle <= 170) {
            angle += STEP_DEGREE;
            update_servo(angle);
            _delay_ms(300); // Debounce delay
        }

        if (is_pressed(BUTTON_CCW_PIN) && angle >= 10) {
            angle -= STEP_DEGREE;
            update_servo(angle);
            _delay_ms(300); // Debounce delay
        }
    }

}
