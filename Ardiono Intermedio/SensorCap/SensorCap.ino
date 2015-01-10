

/*********************************************************************************************************
**********************************************************************************************************

				     					 SensorCap.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion:Ejercicio basico utilizando libreria externa. Construccion de un sensor 
 		capacitivo con un pedazo de aluminio
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
#include <CapacitiveSensor.h>

CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2); 

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/
 void setup(){
 	
   Serial.begin(9600);

 }

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
void loop(){

	long sensor =  cs_4_2.capacitiveSensor(30);
	Serial.print("Sensor: ");
	Serial.println(sensor);

}
