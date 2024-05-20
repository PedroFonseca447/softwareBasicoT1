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

unsigned char mapearLetra(unsigned char letra) {
    
    switch (letra)
     {
        case 'A': return 0b01000001;
        case 0xC0: return 0b11000000; //À
        case 0xC1: return 0b11000001;    // Á
        case 0xC2: return 0b11000010;   // Â
        case 0xC3: return 0b11000011; // Ã
        case 'B': return 0b01000010;
        case 'C': return 0b01000011;
        case 0xC7: return 0b11000111; //Ç
        case 'D': return 0b01000100;
        case 'E': return 0b01000101;
        case 0xC9: return 0b11001001; //É
        case 0xCA: return 0b11001010; // Ê
        case 'F': return 0b01000110;
        case 'G': return 0b01000111;
        case 'H': return 0b01001000;
        case 'I': return 0b01001001;
        case 0xCD: return 0b11001101; //Í
        case 'J': return 0b01001010;
        case 'K': return 0b01001011;
        case 'L': return 0b01001100;
        case 'M': return 0b01001101;
        case 'N': return 0b01001110;
        case 'O': return 0b01001111;
        case 0xD3: return 0b11010011; //Ó
        case 0xD4: return 0b11010100; //Ô
        case 0xD5: return 0b11010101; //Õ
        case 'P': return 0b01010000;
        case 'Q': return 0b01010001;
        case 'R': return 0b01010010;
        case 'S': return 0b01010011;
        case 'T': return 0b01010100;
        case 'U': return 0b01010101;
        case 0xDA: return 0b11011010; //Ú
        case 'V': return 0b01010110;
        case 'W': return 0b01010111;
        case 'X': return 0b01011000;
        case 'Y': return 0b01011001;
        case 'Z': return 0b01011010;

        //minúsculas
        case 'a': return 0b01100001;
        case 0xE0: return 0b11100000; //à
        case 0xE1: return 0b11100001; //á
        case 0xE2: return 0b11100010; //â
        case 0xE3: return 0b11100011; //ã
        case 'b': return 0b01100010;
        case 'c': return 0b01100011;
        case 0xE7: return 0b11100111; //ç
        case 'd': return 0b01100100;
        case 'e': return 0b01100101;
        case 0xE9: return 0b11101001; // é
        case 0xEA: return 0b11101010; // ê 
        case 'f': return 0b01100110;
        case 'g': return 0b01100111;
        case 'h': return 0b01101000;
        case 'i': return 0b01101001;
        case 0xED: return 0b11101101; //í 
        case 'j': return 0b01101010;
        case 'k': return 0b01101011;
        case 'l': return 0b01101100;
        case 'm': return 0b01101101;
        case 'n': return 0b01101110;
        case 'o': return 0b01101111;
        case 0xF3: return 0b11110011; //ó
        case 0xF4: return 0b11110100; //ô
        case 0xF5: return 0b11110101; //õ 
        case 'p': return 0b01110000;
        case 'q': return 0b01110001;
        case 'r': return 0b01110010;
        case 's': return 0b01110011;
        case 't': return 0b01110100;
        case 'u': return 0b01110101;
        case 0xFA: return 0b11111010; //ú
        case 'v': return 0b01110110;
        case 'w': return 0b01110111;
        case 'x': return 0b01111000;
        case 'y': return 0b01111001;
        case 'z': return 0b01111010;
            default:
             printf("Letra inválida! Forneça uma letra válida.\n");
             return 0;
    }
    }


void setPalavras( unsigned short *reg, char letra, char letra2 ){

   unsigned char valor1 = mapearLetra(letra);
   unsigned char valor2 = mapearLetra(letra2);


   if(valor1 && valor2){

    *reg &= 0x0000;
    *reg |= valor1;
    *reg |= (valor2 << 8);

    
   } else{

    printf("Erro");
   }

}

#endif /* REGISTERS_H */


