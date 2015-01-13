

/*********************************************************************************************************
**********************************************************************************************************

				     					 AnalogRef.ino		
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejercicio basico para entender la referencia analogica.
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
 
int pinAnalogico = 0; 


/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/
 void setup(){
 	
	Serial.begin(9600);
	//analogReference(EXTERNAL); // use AREF for reference voltage

 }

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
void loop()
{
  int valorAnalogico = analogRead(pinAnalogico);
  //float voltaje = valorAnalogico * 0.003222; // referencia a 3.3V
  float voltaje = valorAnalogico * 0.0049; // referencia a 5V
  float percentaje = valorAnalogico * 0.097;
  Serial.print(" Porsentaje ADC: ");
  Serial.println(percentaje);
  Serial.print(" mV: ");
  Serial.println(voltaje );
  delay(400);
}
