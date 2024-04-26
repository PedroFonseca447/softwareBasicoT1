#include "registers.h"

// Implementação dos registradores
uint16_t R0_data;
uint16_t R1_data;
uint16_t R2_data;
uint16_t R3_data;
uint16_t R4_data;
uint16_t R5_data;
uint16_t R6_data;
uint16_t R7_data;
uint16_t R8_data;
uint16_t R9_data;
uint16_t R10_data;
uint16_t R11_data;
uint16_t R12_data;
uint16_t R13_data;
uint16_t R14_data;
uint16_t R15_data;

// Função para ler do registrador
uint16_t read_register(uint16_t *reg) {
    switch ((uintptr_t)reg) {
        case (uintptr_t)&R0:
            return R0_data;
        case (uintptr_t)&R1:
            return R1_data;
        case (uintptr_t)&R2:
            return R2_data;
        case (uintptr_t)&R3:
            return R3_data;
        case (uintptr_t)&R4:
            return R4_data;
        case (uintptr_t)&R5:
            return R5_data;
        case (uintptr_t)&R6:
            return R6_data;
        case (uintptr_t)&R7:
            return R7_data;
        case (uintptr_t)&R8:
            return R8_data;
        case (uintptr_t)&R9:
            return R9_data;
        case (uintptr_t)&R10:
            return R10_data;
        case (uintptr_t)&R11:
            return R11_data;
        case (uintptr_t)&R12:
            return R12_data;
        case (uintptr_t)&R13:
            return R13_data;
        case (uintptr_t)&R14:
            return R14_data;
        case (uintptr_t)&R15:
            return R15_data;
        default:
            return 0; // Registro não encontrado
    }
}

// Função para escrever no registrador
void write_register(uint16_t *reg, uint16_t value) {
    switch ((uintptr_t)reg) {
        case (uintptr_t)&R0:
            R0_data = value;
            break;
        case (uintptr_t)&R1:
            R1_data = value;
            break;
        case (uintptr_t)&R2:
            R2_data = value;
            break;
        case (uintptr_t)&R3:
            R3_data = value;
            break;
        case (uintptr_t)&R4:
            R4_data = value;
            break;
        case (uintptr_t)&R5:
            R5_data = value;
            break;
        case (uintptr_t)&R6:
            R6_data = value;
            break;
        case (uintptr_t)&R7:
            R7_data = value;
            break;
        case (uintptr_t)&R8:
            R8_data = value;
            break;
        case (uintptr_t)&R9:
            R9_data = value;
            break;
        case (uintptr_t)&R10:
            R10_data = value;
            break;
        case (uintptr_t)&R11:
            R11_data = value;
            break;
        case (uintptr_t)&R12:
            R12_data = value;
            break;
        case (uintptr_t)&R13:
            R13_data = value;
            break;
        case (uintptr_t)&R14:
            R14_data = value;
            break;
        case (uintptr_t)&R15:
            R15_data = value;
            break;
        default:
            break; // Registro não encontrado
    }
}




