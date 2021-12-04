#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

static void isr() {
    static uint8_t led_state = 0;
    gpio_put(PICO_DEFAULT_LED_PIN, led_state);
    led_state ^= 1;
}

// how quickly should the scheduler be called
#define SHEDULER_FREQ (1000000 / 10)

static void timer_init() {
    static struct repeating_timer timer;
    // register the ist as an repeating timer
    add_repeating_timer_us(SHEDULER_FREQ, isr, NULL, &timer);
}

int main() {
    // init the gpio for the built in led
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    // init usb serial stdio
    stdio_init_all();
    printf("hello, world");

    // init our timers
    timer_init();

    for(;;);
}