#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_leds.h"

#define RED 13

int main(){    
    stdio_init_all();
    setup_led_matrix();
    init_led(RED);

    volatile uint8_t cont=0;
    const uint8_t intervalo=100;
    absolute_time_t tempo_futuro=delayed_by_ms(get_absolute_time(),intervalo);

    while (1)
    {
        if(time_reached(tempo_futuro)){
            muda_estado(RED);
            tempo_futuro=delayed_by_ms(get_absolute_time(),intervalo);
        }
        sleep_ms(1);
    }
}