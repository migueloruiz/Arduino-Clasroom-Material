

/*********************************************************************************************************
**********************************************************************************************************

				     					 BlinkC.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejersicio basico para el manejo de 
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
#include <util/delay.h>  // liberia delay

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
 
int main(void) {

  DDRB = 0b00100000; // bit 5 puerto B como salida

  while (1) {
     PORTB = 0b00100000; // bit 5 puerto B en alto  
     _delay_ms(1000);                                         
   	 PORTB = 0b00000000; // bit 5 puerto B en bajo       
  	 _delay_ms(1000);                                         
  }                                                 
  return (0);  
}



