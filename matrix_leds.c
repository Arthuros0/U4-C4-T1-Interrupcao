#include "pico/stdlib.h"
#include "pio_matrix.pio.h"

#define NUM_PIXELS 25

uint8_t obter_index(uint8_t i) {
    uint8_t x = i % 5;  // Coluna
    uint8_t y = i / 5;  // Linha
    return (y % 2 == 0) ? 24-(y * 5 + x) : 24-(y * 5 + (4 - x));
}

void desenha_frame(uint32_t matriz[10][25],uint8_t frame,uint sm){

    for (uint8_t i = 0; i < NUM_PIXELS; i++)
    {
        uint8_t pos=obter_index(i);
        pio_sm_put_blocking(pio0,sm,matriz[frame][pos]);
    }
    
}