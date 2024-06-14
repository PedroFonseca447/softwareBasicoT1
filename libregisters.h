#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdint.h>

// Definições dos registradores



// Funções de configuração
void set_colorLed(unsigned short *r0, int bit10, int bit11, int bit12);
void set_colorDisplay(unsigned short *r1, unsigned short *r2, int red, int green, int blue);
void setOnOff(unsigned short *r0, int bit);
void setOnOff_Operacao(unsigned short *r0, int bit);
void setPadraoFabrica(unsigned short *r0, int bit);
void setExibicao(unsigned short *r0, int bit1, int bit2);
void setVelocidade(unsigned short *r0, int velocidade);
void setPalavras(unsigned short *reg, char letra, char letra2);

// Funções de mapeamento de caracteres
unsigned char mapearLetra(unsigned char letra);
char mapearCaractere(unsigned char valor);

// Funções de GET
const char *getEstadoDisplay(unsigned short *r0);
const char *getEstadoLed(unsigned short *r0);
const char *getCorLed(unsigned short *r0);
const char *getCorDisplay(unsigned short *r1, unsigned short *r2);
const char *getBateryLevel(unsigned short *r3);
const char *getModoExibicao(unsigned short *r0);
int calcularQuantidadeMensagem(unsigned short *r3);
int calcularVelocidade(unsigned short *r0);
float calcularTemperatura(unsigned short *r3);
char getLetra(unsigned short *reg, int pos);

#endif /* REGISTERS_H */
