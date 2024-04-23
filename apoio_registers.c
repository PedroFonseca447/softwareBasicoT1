// register_utils.c

#include "apoio_registers.h"

// Função para determinar a cor com base nos bits 8 e 9 do registrador
Color get_color(Register *reg) {
    // Verifica se o registrador é válido
    if (reg == NULL) {
        fprintf(stderr, "Error: Invalid register\n");
        return NO_COLOR;
    }

    // Obtém os valores dos bits 8 e 9
    int bit_8 = (*reg >> 8) & 0x01;
    int bit_9 = (*reg >> 9) & 0x01;

    // Determina a cor com base nos valores dos bits
    if (bit_8 == 0 && bit_9 == 0) {
        return NO_COLOR;
    } else if (bit_8 == 1 && bit_9 == 0) {
        return RED;
    } else if (bit_8 == 0 && bit_9 == 1) {
        return GREEN;
    } else if(bit_8 == 1 && bit_9 == 1){
        return BLUE;
    }
}   