/*********************************************************************************************************
**********************************************************************************************************

                                               SleepM_WDT.ino    
                            
                                                Arduino Code  
                                   By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                           Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejemplo basico de Modo Sleep con interrupcion de WDT
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/

#include <avr/wdt.h>
#include <avr/sleep.h>
#include <avr/power.h>

volatile int x = 0;
/**********************************************************************************************************
 *  Nombre:      Main
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

int main(void) {
  DDRB = 0b00100000; // bit 5 puerto B como salida
  PORTB = 0b00000000;
  noInterrupts();           // desabilita interrupciones

      MCUSR &= ~(1<<WDRF);  // se limpia la bandera del WDT
      
      // se debe avisar al Watchdog Change Enable y cambiar el Watchdog System Reset Enable a 1
      WDTCSR |= (1<<WDCE) | (1<<WDE); 

      /* Preescala a 8 seg */
      WDTCSR = (1<<WDP0) | (0<<WDP1)| (0<<WDP2)| (1<<WDP3); 

      WDTCSR |= _BV(WDIE); //activa interrupcion

      
  interrupts();             // activa interrupciones

  while (1) {
    if(x == 1){
        PORTB = PINB ^(1 << PINB5); 
        x = 0;
        enterSleep();
    }          
  }                                                 
  return (0);  
}
/**********************************************************************************************************
 *  Nombre:      enterSleep(void)
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Configura y activa el modo Sleep
 **********************************************************************************************************/

void enterSleep(void)
{
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_mode();
  /* Entra al modo sleep hasta que llege una interrupcion */
  /*                          ...                         */
  /*                          ...                         */
  /*                          ...                         */
  /*                          ...                         */
  sleep_disable(); 
  power_all_enable(); // se activa todo
}

/**********************************************************************************************************
 *  Nombre:      ISR(WDT_vect)
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se activa cada vez que se desvorda el WDT
 **********************************************************************************************************/

ISR(WDT_vect){
  if(x == 0)
  {
    x=1;
  }
}