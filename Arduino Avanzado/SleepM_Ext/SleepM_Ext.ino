/*********************************************************************************************************
**********************************************************************************************************

                                               SleepM_Ext.ino    
                            
                                                Arduino Code  
                                   By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                           Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejemplo basico de Modo Sleep con interupcion externa en el PD2
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/

#include <avr/sleep.h>
//#include <avr/power.h>

int seg =0;

/**********************************************************************************************************
 *  Nombre:      setup()
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Configuracion inicial.
 **********************************************************************************************************/

void setup()
{
  DDRD = 0b00000000; // PD2 como entrada
  PORTD |= 0b00000100; // PD2 a pull-up
  //attachInterrupt(0, pin2Interrupt, FALLING);
  Serial.begin(9600);
  Serial.println("Serial Activo");
}

/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

void loop()
{
  delay(1000);
  seg ++;
  
  Serial.print("Despierto por ");
  Serial.print(seg );
  Serial.println(" segundos");
  
  if(seg  == 3)
  {
    Serial.println("Entrando a Sleep");
    delay(200);
    seg  = 0;
    enterSleep();
  }
}

/**********************************************************************************************************
 *  Nombre:      pin2Interrupt(void)
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se activa al llegar un bajo al PD2
 **********************************************************************************************************/

void pin2Interrupt(void)
{
 detachInterrupt(0); // se desactiva la interrupcion para evitar multiples entradas
 Serial.println("Interrupcion");
}

/**********************************************************************************************************
 *  Nombre:      enterSleep(void)
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Configura y activa el modo Sleep
 **********************************************************************************************************/

void enterSleep(void)
{
  attachInterrupt(0, pin2Interrupt, FALLING); // se cativa la intrrupcion
  delay(100); // delay para asegurar la entrada de la inerrupcion
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_mode();
  /* Entra al modo sleep hasta que llege una interrupcion */
  /*                          ...                         */
  /*                          ...                         */
  /*                          ...                         */
  /*                          ...                         */
  sleep_disable(); 
  Serial.println("Sale de Sleep");
}