#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// Definições dos registradores


// Funções para leitura e escrita nos registradores
uint16_t read_register(uint16_t *reg);
void write_register(uint16_t *reg, uint16_t value);

//esse vai mudar o led do status
void set_colorLed(unsigned short*r0, int bit10,  int bit11,  int bit12) {
    if (bit10 == 1) {
        *r0 |= (0x1 << 10); // Ativa o bit de cor RED
        
               
    } else if (bit10 == 0) {
        *r0 &= ~(0x1 << 10); // Zera o bit 1        
    }
    if (bit11 == 1) {
        *r0 |= (0x1 << 11); // Seta para 1 o bit 11 no registrador 0
          
    } else if (bit11 == 0) {
        *r0 &= ~(0x1 << 11); // Zera o bit 11   
    }
    if (bit12 == 1) {
        *r0 |= (0x1 << 12); // Ativa o bit de cor BLUE   
    } else if (bit12 == 0) {
        *r0 &= ~(0x1 << 12); // Zera o bit 12
    }
    
}

void set_colorDisplay(unsigned short*r1, unsigned short *r2, int red,  int green,  int blue) {
    if (red == 1) {
        *r1 |= 255; // Ativa o bit de cor RED
        
               
    } else if (red == 0) {
        *r1 &= ~(0xFF); // Zera o bit 1        
    }
    if (green == 1) {
        *r1 |= (255 << 8); // Seta para 1 o bit 11 no registrador 0
          
    } else if (green == 0) {
        *r1 &= ~(0xFF00); // Zera o bit 11   
    }
    if (blue == 1) {
        *r2 |= 255; // Ativa o bit de cor BLUE   
    } else if (blue == 0) {
        *r2 &= ~(0xFF); // Zera o bit 12
    }
    
}

void setOnOff(unsigned short *r0, int bit){

    if(bit == 1 ){
        *r0 |= (0x1 << 0);
    }
    else if(bit == 0){
        *r0 &= ~(0x1 << 0);
    }
}

void setOnOff_Operacao(unsigned short *r0, int bit){

    if(bit == 0 ){
        *r0 |= (0x1 << 9);
    }
    else if(bit == 1){
        *r0 &= ~(0x1 << 9);
    }
}
// criar outro com as especificações acima só que mudando apenas os rgb


// Funções de controle para o hardware

#endif /* REGISTERS_H */


