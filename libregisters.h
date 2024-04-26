#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// Definições dos registradores


// Funções para leitura e escrita nos registradores
uint16_t read_register(uint16_t *reg);
void write_register(uint16_t *reg, uint16_t value);


void set_color(uint16_t *r0, uint16_t *r1, uint16_t *r2, int bit10, int bit11, int bit12) {
    if (bit10 == 1) {
        *r0 |= (0x1 << 10); // Ativa o bit de cor RED
        *r1 |= 255;         // Preenche os bits de cor em r1 do intervalo de 0-7
    } else if (bit10 == 0) {
        *r0 &= ~(0x1 << 10); // Zera o bit 10
        *r1 &= ~(0xFF);      // Zera os bits de cor em r1 do intervalo de 0-7
    }
    
    if (bit11 == 1) {
        *r0 |= (0x1 << 11); // Seta para 1 o bit 11 no registrador 0
        *r1 |= 0xFF00;      // Preenche os bits de cor em r1 do intervalo 8-15
    } else if (bit11 == 0) {
        *r0 &= ~(0x1 << 11); // Zera o bit 11
        *r1 &= ~(0xFF00);    // Zera os bits de cor em r1 do intervalo 8-15
    }
        
    if (bit12 == 1) {
        *r0 |= (0x1 << 12); // Ativa o bit de cor BLUE
        *r2 |= 255;         // Preenche os bits de cor em r2
    } else if (bit12 == 0) {
        *r0 &= ~(0x1 << 12); // Zera o bit 12
        *r2 &= ~(0xFF);      // Zera os bits de cor em r2
    }
}

// Funções de controle para o hardware

#endif /* REGISTERS_H */


