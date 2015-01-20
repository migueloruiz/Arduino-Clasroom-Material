

/*********************************************************************************************************
**********************************************************************************************************

				     					 Botton.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejercicio basico para lectrura y escritura d epuertos con C
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 

/**********************************************************************************************************
 *  Nombre:      main()
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

int main(void) {
	DDRB = 0b00100000;  // Puerto B5 como salida y B4 entrada
	PORTB |= (1 << PORTB4);	// Port B4 con resitencia Pull-UP
	//MCUCR &= (1 << PUD); // Pull-Up Disable en 0

	while (1) {

	  if((PINB & (1<<PINB4)) == 0) { // Lectura del bit 4 en el Puerto B
	  	PORTB &= 0b11011111; // Apaga bit 5 del puerto B
	  } 
	  else {
	  	PORTB |= 0b00100000; // Activa bit 5 del puerto B
	  } 

	}                                                 
	return (0);  
}