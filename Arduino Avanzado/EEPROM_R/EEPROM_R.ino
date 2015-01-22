
/*********************************************************************************************************
**********************************************************************************************************

				     					 EEPROM_R.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejercicio basico de lectura en la EEPROM
			 
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
	byte Byte_bajo = EEPROM.read(addr);
	byte Byte_alto = EEPROM.read(addr+1);
	int volt =((Byte_bajo << 0) & 0xFF) + ((Byte_alto << 8) & 0xFFFF);
	Serial.print("El voljae guardado es: ");
	Serial.print(volt);
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