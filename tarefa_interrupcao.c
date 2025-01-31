#include <stdio.h>
#include "pico/stdlib.h"

#include "matrix_leds.h"

#define RED 13



int main(){
    
    stdio_init_all();
    setup_led_matrix();
    init_led(RED);
    uint8_t cont=0;
    while (1)
    {

    }
    
}