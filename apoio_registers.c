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
    int bit_10 = (*reg >> 10) & 0x01;
    int bit_11 = (*reg >> 11) & 0x01;
    int bit_12 = (*reg >> 12) & 0x01;

    // Determina a cor com base nos valores dos bits
    if (bit_10 == 0 && bit_11 == 0 && bit_12 == 0 ) {
        return NO_COLOR;
    } else if (bit_10 == 1) {
        return RED;
    } else if (bit_11 == 1) {
        return GREEN;
    } else if(bit_12 == 1){
        return BLUE;
    }
}   