/*********************************************************************************************************
**********************************************************************************************************

				     					 TablaMagica.pde		
			      
				   					 	Processing Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion:Juego clásico de la Tabla Magica, ejemplo de cominicaccion serial y conecon 
 		con arduino.
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 import processing.serial.*;

 Serial myPort;       

 PImage bcg;

 int ancho = 600, alto = 400;
 int x = 0  ,y = 0;

/******************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
 ******************************************************************************************************/
 void setup(){
 	size(ancho, alto);

 	bcg = loadImage("bcg.png");

	println(Serial.list());
    myPort = new Serial(this, Serial.list()[7], 9600);
    myPort.bufferUntil(' ');

    background(bcg);
 }

/******************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 ******************************************************************************************************/
void draw(){
	fill(0);
	ellipse(x, y, 3,3);
}

/******************************************************************************************************
 *  Nombre:      mousePressed
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se aumenta la posicion en "y" del brid y se reinicia el juego
******************************************************************************************************/

void keyPressed() {
	if(key == ' ') {
		background(bcg);
	}
} 

/******************************************************************************************************
 *  Nombre:      mousePressed
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se aumenta la posicion en "y" del brid y se reinicia el juego
******************************************************************************************************/

void serialEvent( Serial port) {
	String val = port.readStringUntil(' ');
	if (val != null) {
		val = trim(val);
		String[] lista = split(val,','); 
		x = int(lista[0]);
		y = int(lista[1]);
		println("x: "+x);
		println("y: "+y);
	}
}


