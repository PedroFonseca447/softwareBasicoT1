#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// Definições dos registradores


// Funções para leitura e escrita nos registradores
uint16_t read_register(uint16_t *reg);
void write_register(uint16_t *reg, uint16_t value);

// Funções de controle para o hardware
void display_message(const char *message);
void control_status_led(int battery_level);

#endif /* REGISTERS_H */


