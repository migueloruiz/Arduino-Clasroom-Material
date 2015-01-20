/*********************************************************************************************************
**********************************************************************************************************

                        KitC.ino    
            
                        Arduino Code  
               By Miguelo A. Ruiz (2015).Visit: miguelo.me  
           Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejemplo basico para manejo de puertos (Kit el auto increible)
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
#include <util/delay.h>   // libreria de delay

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

int main(void) {
  DDRD = 0b11111111; // Todo el puerto D como salida

  while (1) {

    for(int i=0; i<= 7; i++){ 
        PORTD = (1<< i); // Escribe un byte multiplo de 2 en binario 
        _delay_ms(100); 
    }
    for(int i=7; i >= 0; i--){
        PORTD = (1<< i);
        _delay_ms(100); 
    }
  }                                     
  return (0);  
}