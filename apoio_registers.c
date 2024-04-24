// register_utils.c

#include "apoio_registers.h"

// Função para determinar a cor com base nos bits 8 e 9 do registrador



    void set_color(Register *r0, Register *r1, Register *r2, int bit){

        if( bit == 10){
            *r0 |= (0x1 << 10); //ativa o bit de cor RED
            *r0 &= ~(0x1 << 11);//zera o bit 11
            *r0 &= ~(0x1 << 12);//zera o bit 12

            //a parte que muda no r1
                *r1 &= ~(0xFFFF);//zera os bit de color em r1
                *r2 &= (0xFFFF);//zera os bit de color em r2
                *r1 |= 255;//do 0-7 preenche com 255
            
        }
        else if(bit == 11){
            *r0 |= (0x1 << 11); //ativa o bit de cor verde
            *r0 &= ~(0x1 << 10);//zera o bit 10
            *r0 &= ~(0x1 << 12);//zera o bit 12

            //a parte que muda no r1 ou r2
            *r1 &= ~(0xFFFF);//zera os bit de color em r1
            *r2 &= (0xFFFF);//zera os bit de color em r2
            *r1 |= (255<< 8);//ativa os bits de cor verde 
           
        }
         else if(bit == 12){
            *r0 |= (0x1 << 12); //ativa o bit de cor BLUE
            *r0 &= ~(0x1 << 10);//zera o bit 10
            *r0 &= ~(0x1 << 11);//zera o bit 12
            
            *r1 &= ~(0xFFFF);//zera os bit de color em r1
            *r2 |= 255;// seta os bits de 0-7 no r2 para azul 
        }
        
}

    Color read_color(Register *r1, Register *r2){

        unit8_t red_component = *r1 & 0xFF;
        unit8_t green_component = (*r1 >> 8) & 0xFF;
        unit8_t blue_component = *r2 & 0xFF;


     if(red_component == 255 && green_component == 0 && blue_component == 0){
        return RED;
     }else if(red_component == 0 && green_component == 255 && blue_component == 0){
        return GREEN;
     } else if(red_component == 0 && green_component == 0 && blue_component == 255){
        return BLUE;
     } else {
        return NO_COLOR;
     }

}



