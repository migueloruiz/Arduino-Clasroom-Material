import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class PTablaMagica extends PApplet {

/*********************************************************************************************************
**********************************************************************************************************

				     					 TablaMagica.pde		
			      
				   					 	Processing Code  
						   By Miguelo A. Ruiz (2015).Visit: miguelo.me	
	 			  Creative Commons Attribution-ShareAlike4.0 Internacional License
			 
**********************************************************************************************************

 		Descripcion:Juego cl\u00e1sico de la Tabla Magica, ejemplo de cominicaccion serial y conecon 
 		con arduino.
			 
***********************************************************************************************************
 		This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
 		International License. To view a copy of this license, visit: 
 		http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 

 Serial myPort;       

 PImage bcg;

 int ancho = 600, alto = 400;
 int x = 0  ,y = 0;

/******************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Funci\u00f3n de configuraci\u00f3n. 
 ******************************************************************************************************/
 public void setup(){
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
public void draw(){
	fill(0);
	ellipse(x, y, 3,3);
}

/******************************************************************************************************
 *  Nombre:      mousePressed
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se aumenta la posicion en "y" del brid y se reinicia el juego
******************************************************************************************************/

public void keyPressed() {
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

public void serialEvent( Serial port) {
	String val = port.readStringUntil(' ');
	if (val != null) {
		val = trim(val);
		String[] lista = split(val,','); 
		x = PApplet.parseInt(lista[0]);
		y = PApplet.parseInt(lista[1]);
		println("x: "+x);
		println("y: "+y);
	}
}


  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "PTablaMagica" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
