#include <stdio.h>
#include "pico/stdlib.h"
#include "matrix_leds.h"

//Autor: Arthur de Oliveira Moreira
//Repositório no GitHub: https://github.com/Arthuros0/U4-C4-T1-Interrupcao.git

#define RED 13 //GPIO do LED vermelho

#define BUTTON_A 5
#define BUTTON_B 6  

volatile uint8_t cont=0;        //Váriavel de controle do número exibido na matriz de leds
const uint8_t intervalo=100;    //Intervalo usado para debounce dos botões e pisca do led.
absolute_time_t tempo_button;   //Váriavel de debounce do botão


void init_button(uint8_t pin);                          //Função de inicialização dos botões
void button_irq_callback(uint pin, uint32_t events);    //Função de callback para os botões


int main(){

    //Inicialização dos perifericos
    stdio_init_all();   
    setup_led_matrix();
    init_led(RED);
    init_button(BUTTON_A);
    init_button(BUTTON_B);

    absolute_time_t tempo_futuro=delayed_by_ms(get_absolute_time(),intervalo);
    tempo_button=delayed_by_ms(get_absolute_time(),intervalo*2);

    //Configuração da interrupcao dos botões
    gpio_set_irq_enabled_with_callback(BUTTON_A,GPIO_IRQ_EDGE_FALL,true,&button_irq_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_B,GPIO_IRQ_EDGE_FALL,true,&button_irq_callback);

    //Inicia a matriz de leds com o 0 impresso.
    desenha_frame(numeros,cont);

    while (1)
    {
        //Verifica se o intervalo entre a ultima piscagem do led foi atendido
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
        //Caso o número sofra underflow no decremento ou fique maior que zero, 
        //será atribuido 0 ou 9 a denpender do botão pressionado.
        if(cont>9)cont=(pin==BUTTON_A) ? 0 : 9; 

        desenha_frame(numeros,cont);                                    //Atualiza a matriz de leds com o novo número.
        tempo_button=delayed_by_ms(get_absolute_time(),intervalo*2);    //Atualiza o tempo do debounce.
    }
}
