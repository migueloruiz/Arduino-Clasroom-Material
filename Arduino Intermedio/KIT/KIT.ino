

/*********************************************************************************************************
**********************************************************************************************************

                                            KIT.ino    
                      
                                         Arduino Code  
                              By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                         Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion:Ejercicio basico del registro de desplazameinto para hacer un KIT (Auto increible).
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
//Pin conectado a ST_CP del 74HC595
int SH_CP_Pin = 11;
//Pin conectado a SH_CP del 74HC595
int ST_CP_Pin = 12;
////Pin conectado a DS del 74HC595
int DS_Pin = 8;
// Tiempo de cambio
int tiempo = 100;

/**********************************************************************************************************
 *  Nombre:      Setup
 *  Retornos:    Nada
 *  Parametros:  Nada
 *  Descripcion: Función de configuración. 
**********************************************************************************************************/

void setup() {
  pinMode(SH_CP_Pin, OUTPUT);
  pinMode(ST_CP_Pin, OUTPUT);
  pinMode(DS_Pin, OUTPUT);
}

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

void loop() {
  int indice = 1;

  for(int i=0; i<2; i++){
    for (int j = 1; j < 8; j++) {
      // Se manteiene en LOW el SH_CP_Pin mientras se este transmitiendo
      digitalWrite(SH_CP_Pin, LOW);
      //shiftOut(DS_Pin, ST_CP_Pin, MSBFIRST o LSBFIRST , indice);  
      //MSBFIRST = 1;
      //LSBFIRST = 0;
      shiftOut(DS_Pin, ST_CP_Pin, i, indice);  
      // cuando se desea guardar de pada a HIGH el SH_CP_Pin
      digitalWrite(SH_CP_Pin, HIGH);
      indice *= 2 ;
      delay(tiempo);
    }
    indice = 1;
  }
} 