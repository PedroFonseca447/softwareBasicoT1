#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// Definições dos registradores
extern uint16_t *R0;
extern uint16_t *R1;
extern uint16_t *R2;
extern uint16_t *R3;
extern uint16_t *R4;
extern uint16_t *R5;
extern uint16_t *R6;
extern uint16_t *R7;
extern uint16_t *R8;
extern uint16_t *R9;
extern uint16_t *R10;
extern uint16_t *R11;
extern uint16_t *R12;
extern uint16_t *R13;
extern uint16_t *R14;
extern uint16_t *R15;

// Funções para leitura e escrita nos registradores
uint16_t read_register(uint16_t *reg);
void write_register(uint16_t *reg, uint16_t value);

// Funções de controle para o hardware
void display_message(const char *message);
void control_status_led(int battery_level);

#endif /* REGISTERS_H */


