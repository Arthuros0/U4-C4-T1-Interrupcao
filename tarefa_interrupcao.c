#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_leds.h"

#define RED 13

#define BUTTON_A 5
#define BUTTON_B 6  

volatile uint8_t cont=0;
const uint8_t intervalo=100;
absolute_time_t tempo_button;


void init_button(uint8_t pin);
void button_irq_callback(uint pin, uint32_t events);


int main(){

    stdio_init_all();
    setup_led_matrix();
    init_led(RED);
    init_button(BUTTON_A);
    init_button(BUTTON_B);

    absolute_time_t tempo_futuro=delayed_by_ms(get_absolute_time(),intervalo);
    tempo_button=delayed_by_ms(get_absolute_time(),intervalo*2);

    gpio_set_irq_enabled_with_callback(BUTTON_A,GPIO_IRQ_EDGE_FALL,true,&button_irq_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B,GPIO_IRQ_EDGE_FALL,true,&button_irq_callback);

    desenha_frame(numeros,cont);

    while (1)
    {
        if(time_reached(tempo_futuro)){
            muda_estado(RED);
            tempo_futuro=delayed_by_ms(get_absolute_time(),intervalo);
        }
        sleep_ms(1);
    }
}

void init_button(uint8_t pin){
    gpio_init(pin);
    gpio_set_dir(pin,GPIO_IN);
    gpio_pull_up(pin);
}

void button_irq_callback(uint pin, uint32_t events){
    if(time_reached(tempo_button)){
        if(pin == BUTTON_A){
            cont++;
        }else if(pin == BUTTON_B){
            cont--;
        }
        if(cont>9)cont=(pin==BUTTON_A) ? 0 : 9;
        desenha_frame(numeros,cont);
        tempo_button=delayed_by_ms(get_absolute_time(),intervalo*2);
    }
}
