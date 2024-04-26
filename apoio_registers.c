// register_utils.c
#include <stdint.h>
#include "apoio_registers.h"

// Função para determinar a cor com base nos bits 8 e 9 do registrador



    void set_color(Register *r0, Register *r1, Register *r2, int bit_10, int bit_11, int bit_12){

        if( bit_10 == 1){
            *r0 |= (0x1 << 10); //ativa o bit de cor RED
           
                *r1 |= 255;//do 0-7 preenche com 255
            
        } else if( bit_10 == 0){
          *r0 &= ~(0x1 << 10);//zera o bit 10
          *r1 &= ~(0xFF);//zera os bit de color em r1 do intervalo de 0-7
        }

        if( bit_11 == 1){
            *r0 |= (0x1 << 11);//seta para 1 o bit 11 no registrador 0 

               *r1 |= (255<<8);// preenche os bits de cor em verde 
              
        } else if( bit_11== 0){
         *r0 &= ~(0x1 << 10);//zera o bit 10
          *r1 &= ~(0xFF00);//zera os bit de color em r1 do intervalo 8-15
        }
        
        if( bit_12 == 1){
         
         *r0 |= (0x1 << 12); // ativa o bit de cor BLUE

          *r2 |= 255;// preenche os bits de cor em verde no registrador

        }   else if( bit_12 == 0){
         *r0 &= ~(0x1 << 12);//zera o bit 12
          *r1 &= ~(0xFF);//zera os bit de color em r1 do intervalo 0-7
        }


        
}

    Color read_color(Register *r1, Register *r2){

        uint8_t red_component = *r1 & 0xFF;
        uint8_t green_component = (*r1 >> 8) & 0xFF;
        uint8_t blue_component = *r2 & 0xFF;


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
// reset de todos os bits analisar mehlro em casa
   void set_fabric(Register *r0,Register *r1, Register *r2, Register *r3, Register *r4, Register *r5,
   Register *r6, Register *r7, Register *r8, Register *r9, Register *r10, Register *r11, Register *r12,
   Register *r13, Register *r14, Register *r15)
   {





   }


   Batery read_bateryLevel(Register *r3){

      int bit0 = (*r3) & 0x01;
      int bit1 = (*r3 >> 1) & 0x01;

      if(bit0 == 0 && bit1 == 0){
         return CRITICO;
      }

      if(bit0 == 0 && bit1 == 1){
         return BAIXO;
      }

      if(bit0 == 1 && bit1 == 0){
         return MEDIO;
      }

      if(bit0 == 1 && bit1 == 1){
         return ALTO;
      }
   }



