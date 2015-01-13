

/*********************************************************************************************************
**********************************************************************************************************

                                             Pianito.ino    
                          
                                            Arduino Code  
                               By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                    Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejercicio basico de tone() y entradas digitales en PULLUP.
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
// Se definen las constantes
// Se declaran las frecuencia de las notas
const int NOTA_DO  = 262;
const int NOTA_RE  = 294;
const int NOTA_MI  = 330;
const int NOTA_FA  = 349;
const int NOTA_SOL = 392;
const int NOTA_LA  = 440;
const int NOTA_SI  = 494;
const int NOTA_D0  = 523;

// se define las notas en un arreglo
int notas[ ] = {NOTA_DO, NOTA_RE, NOTA_MI, NOTA_FA};
// timpo entre notas
int tiempo = 100;

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/
 void setup() {
  // Se definen los pines como entrada del 2 a 5
  for(int pin=2; pin < 6 ; pin++) {
      pinMode( pin , INPUT_PULLUP);
  } 
}
/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/
void loop() {
  for (int boton = 2; boton < 6; boton++) {
    int boton_actual  = digitalRead(boton); // se lee el estado del boton
    if(boton_actual  == LOW){
      tone(13, notas[ boton -2 ], tiempo);
    }
  }
}