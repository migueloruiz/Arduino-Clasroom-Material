
/*********************************************************************************************************
**********************************************************************************************************

				     					 EEPROM_W.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejercicio basico de escritura en la EEPROM
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
#include <EEPROM.h>
int addr= 0x00; // Dirección inicial donde guardaré datos

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/
void setup(){
	Serial.begin(9600);
	int volt = analogRead(0); //Toma los datos del sensor
	Serial.println(volt); 
	byte Byte_alto = highByte(volt); // Descompongo el valor entero en 2 bytes y los guardo
	byte Byte_bajo = lowByte(volt);
	EEPROM.write(addr, Byte_bajo);
	EEPROM.write(addr+1, Byte_alto);
}

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

void loop(){
	//Nada
}