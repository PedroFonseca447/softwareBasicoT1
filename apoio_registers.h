// register_utils.h

#ifndef REGISTER_UTILS_H
#define REGISTER_UTILS_H

#include <stdio.h>

// Define o tipo de dado para representar um registrador de 16 bits
typedef unsigned short Register;

// Define um tipo de enumeração para representar as cores
typedef enum {
    NO_COLOR,
    RED,
    GREEN,
    BLUE,
} Color; 

// Função para determinar a cor com base nos bits 10,11 e 12 do registrador


Color read_color(Register *r1,Register  *r2);



#endif