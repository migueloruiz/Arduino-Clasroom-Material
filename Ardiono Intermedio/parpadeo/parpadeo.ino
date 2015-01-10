/*********************************************************************************************************
**********************************************************************************************************

				     					 paradeo.ino	
			      
				   					 	Arduino Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion: Ejercicio para aprender como hacer funciones.
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
int LED1 = 2;
int LED2 = 3;

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/
void setup(){
	pinMode(LED1, OUTPUT);
	pinMode(LED2, OUTPUT);
}
/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
void loop() {
	parpadeo(2,5,100);
	parpadeo(3,2,500);
}

 /**********************************************************************************************************
 *  Nombre:      parpadeo()
 *  Retornos:    Nada
 *  Parametros:  int pin: pin para preder y apadgar
 *				 int numero: veces en en que parpadea
 *				 int tiempo: tiempo entre encendido y apagado
 *  Descripcion: Funcion haca parpadear un led en el pin seleccionado, un numero de veces predeterminado.
**********************************************************************************************************/

void parpadeo(int pin,int numero, int tiempo){
	for(int i=0; i < numero  ; i++){
	    digitalWrite(pin, HIGH);  
	 	delay(tiempo);                  
	 	digitalWrite(pin, LOW);
    	delay(tiempo);
	}
}

