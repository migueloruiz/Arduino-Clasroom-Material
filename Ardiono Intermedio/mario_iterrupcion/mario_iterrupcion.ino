

/*********************************************************************************************************
**********************************************************************************************************

                                          sketch_super_mario_theme.ino    
                              
                                          Arduino Code  
                                 By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                             Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejercicio basico de buzzer para una melodia y prender y apagar un led sin interrupmir 
     la melodia (interrupciones).
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
int speakerPin = 8;
int Led = 13;

char notas_mario[] = "EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb  GNFR E uaC aCD GNFR E 1 11   GNFR E uaC aCD L  D C   CC C CD EC ag  CC C CDE  CC C CD EC ag  EE E CE G  g  C  g e  a b ia gEGA FG E CDb C  g e  a b ia gEGA FG E CDb EC g u aF Fa  bAAAGFEC ag  EC g u aF Fa  bF FFEDCe ec  "; // a space represents a rest
float ritmos_mario[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 1
                2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 2, 4, //Page 2
                1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 2, //Page4
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, //Page 5
                1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1.3, 1.3, 1.3, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1.3, 1.3, 1.3, 1, 1, 1, 1, 1, 1, 2 }; //Page 6
                
int tiempo = 95;

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, inter , FALLING);
  digitalWrite(Led, HIGH);
}

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
void loop() {
  for (int i = 0; i < sizeof(notas_mario); i++) {
    if (notas_mario[i] == ' ') {
      delay(ritmos_mario[i] * tiempo); 
    } else {

      playNote( speakerPin, notas_mario[i], ritmos_mario[i] * tiempo);
    }
    delay(tiempo / 2); 
  }
}

 /**********************************************************************************************************
 *  Nombre:      Inter
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Funcion de interrupcion, permite prender y apagar un led sin afectar la musica
**********************************************************************************************************/

 void inter( )
{
  digitalWrite(Led, (digitalRead(Led))^1);

}

/**********************************************************************************************************
 *  Nombre:      playNote
 *  Retorna:     Nada
 *  Parametros:  int pin: pin donde se conecta el speaker
 *               char nota_char: nombre de la nota
 *               int duracion: beats en que la nota permanece activa
 *  Descripcion: Toca la nota segun el nombre y el tiempo dado
 **********************************************************************************************************/

void playNote(int pin ,char nota_char, int duracion) {
//                    do   do/s  re  re/s  mi  fa   fa/s sol sol/s la   la/s  do
  char nombres[] = { ' ',  '!', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'i', 'N', 'R', 'u',  '1', 'L', 'k'}; // [i = b flat] [N = G flat] [R = D#] [u = g#] [1 = C oct. 5] [L = E flat]
  int notas[] =  {   0, 1046, 138, 146, 155, 164, 174, 184, 195, 207, 220, 233, 246, 261, 293, 329, 349, 391, 440, 493, 523, 587, 659, 698, 783, 880, 987, 466, 740, 622, 415, 1046, 622u, 227};
    
  for (int i = 0; i < 34; i++) {
    if (nombres[i] == nota_char) {
        tone(pin, notas[i]);
        delay(duracion);
        noTone(pin);
    }
  }
}



