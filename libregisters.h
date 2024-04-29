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


void setExibicao( unsigned short *r0, int bit1, int bit2){

    if( bit1 == 0 && bit2 == 0){ 
        //estatico
          *r0 &= ~(0x1 << 2);
           *r0 &= ~(0x1 << 1);
    }

    if( bit1 == 0 && bit2== 1){
        //deslizante
         *r0 &= ~(0x1 << 2);
         *r0 |= (0x1 << 1);
    }

    if( bit1 == 1 && bit2 == 0){
        //piscante
        *r0 |= (0x1 << 2);
         *r0 &= ~(0x1 << 1);
    }

    if( bit1 == 1 && bit2 == 1){
        //deslizante/piscante
        *r0 |= (0x1 << 2);
        *r0 |= (0x1 << 1);
    }
 
}
// criar outro com as especificações acima só que mudando apenas os rgb


//ainda com alguns problemas 
void setVelocidade(unsigned short *r0, int velocidade){

    int velo = (velocidade / 100) -1;

    *r0 &= ~(0x3F << 3);

    *r0 |= (velo & 0x3F) << 3;
} 



// Funções de GET


const char * getEstadoDisplay( unsigned short *r0){

    return (*r0 & ( 0x1 << 0)) == 0 ? "desligado" : "ligado";
}

const char * getEstadoLed( unsigned short *r0){

    return (*r0 & ( 0x1 << 9)) == 0 ? "desligado" : "ligado";
}

const char * getCorLed( unsigned short *r0){

    if ((*r0 & (0x1 << 10)) && (*r0 & (0x1 << 11)) && (*r0 & (0x1 << 12))) {
    return "white";
    }

    if ((*r0 & (0x1 << 10)) && (*r0 & (0x1 << 11)) && !(*r0 & (0x1 << 12))) {
    return "yellow";
    }

    if (!(*r0 & (0x1 << 10)) && (*r0 & (0x1 << 11)) && (*r0 & (0x1 << 12))) {
    return "cian";
    }

    if ((*r0 & (0x1 << 10)) && !(*r0 & (0x1 << 11)) && (*r0 & (0x1 << 12))) {
    return "pink";
    }

    if ((*r0 & (0x1 << 10)) && !(*r0 & (0x1 << 11)) && !(*r0 & (0x1 << 12))) {
    return "red";
    }

    if (!(*r0 & (0x1 << 10)) && (*r0 & (0x1 << 11)) && !(*r0 & (0x1 << 12))) {
    return "green";
    }

    if (!(*r0 & (0x1 << 10)) && !(*r0 & (0x1 << 11)) && (*r0 & (0x1 << 12))) {
    return "blue";
    }

}

const char * getCorDisplay( unsigned short *r1 , unsigned short * r2 ){

    if ((*r1 & (0x1 << 1)) && (*r1 & (0x1 << 8)) && (*r2 & (0x1 << 1))) {
    return "white";
    }

    if ((*r1 & (0x1 << 1)) && (*r1 & (0x1 << 8)) && !(*r2 & (0x1 << 1))) {
    return "yellow";
    }

    if (!(*r1 & (0x1 << 1)) && (*r1 & (0x1 << 8)) && (*r2 & (0x1 << 1))) {
    return "cian";
    }

    if ((*r1 & (0x1 << 1)) && !(*r1 & (0x1 << 8)) && (*r2 & (0x1 << 1))) {
    return "pink";
    }

    if ((*r1 & (0x1 << 1)) && !(*r1 & (0x1 << 8)) && !(*r2 & (0x1 << 1))) {
    return "red";
    }

    if (!(*r1 & (0x1 << 1)) && (*r1 & (0x1 << 8)) && !(*r2 & (0x1 << 1))) {
    return "green";
    }

    if (!(*r1 & (0x1 << 1)) && !(*r1 & (0x1 << 8)) && (*r2 & (0x1 << 1))) {
    return "blue";
    }

}

const char * getBateryLevel( unsigned short * r3){

    if (!(*r3 & (0x1 << 0)) && !(*r3 & (0x1 << 1))) {
    return "critico";
    }

    if (!(*r3 & (0x1 << 0)) && (*r3 & (0x1 << 1))) {
    return "baixo";
    }

    if ((*r3 & (0x1 << 0)) && !(*r3 & (0x1 << 1))) {
    return "médio";
    }

    if ((*r3 & (0x1 << 0)) && (*r3 & (0x1 << 1))) {
    return "alto";
    }
    
}

const char * getModoExibicao( unsigned short *r0){
     if (!(*r0 & (0x1 << 1)) && !(*r0 & (0x1 << 2))) {
        return "estático";
    }
    if (!(*r0 & (0x1 << 1)) && (*r0 & (0x1 << 2))) {
        return "deslizante";
    }
    if ((*r0 & (0x1 << 1)) && !(*r0 & (0x1 << 2))) {
        return "piscante";
    }
    if ((*r0 & (0x1 << 1)) && (*r0 & (0x1 << 2))) {
        return "deslizante/piscante";
    }
}

int  calcularQuantidadeMensagem ( unsigned short *r3){

    int quantidade =0;

    unsigned short bits_relevantes = ( *r3>> 2) & 0xF;

    for(int i = 0; i < 4; i++){

        if(bits_relevantes & (0x1 << i)){
            quantidade += (1<<i);
        }

    }
    return quantidade;
}

int  calcularVelocidade ( unsigned short *r0){

    int quantidade =0;

    unsigned short bits_relevantes = ( *r0>> 3) & 0xF;

    for(int i = 0; i < 6; i++){

        if(bits_relevantes & (0x1 << i)){
            quantidade += (1<<i);
        
        }

    }
    return quantidade*100;
}

float calcularTemperatura(unsigned short *r3) {
    // Extrair os bits relevantes do intervalo [6, 15]
    unsigned short bits_relevantes = (*r3 >> 6) & 0x3FF;

    // Converter para decimal e considerar complemento de dois para valores negativos
    int valor_decimal;
    if (bits_relevantes & 0x200) { // Se o bit mais significativo estiver definido, é negativo
        valor_decimal = -(0x3FF - bits_relevantes + 1);
    } else {
        valor_decimal = bits_relevantes;
    }

    // Calcular a temperatura em graus Celsius
    float temperatura = valor_decimal / 10.0f;
    return temperatura;
}


#endif /* REGISTERS_H */


