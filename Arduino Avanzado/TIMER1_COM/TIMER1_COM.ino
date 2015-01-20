
/*********************************************************************************************************
**********************************************************************************************************

                                         TIMER1_COM.ino    
                        
                                        Arduino Code  
                           By Miguelo A. Ruiz (2015).Visit: miguelo.me  
                       Creative Commons Attribution-ShareAlike4.0 Internacional License
       
**********************************************************************************************************

     Descripcion: Ejemplo basico de Control de timer0
       
***********************************************************************************************************
     This work is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 
     International License. To view a copy of this license, visit: 
     http://creativecommons.org/licenses/by-nc-sa/4.0/.
**********************************************************************************************************
**********************************************************************************************************/
 
int precarga = 49911;  // pregarga para 1Hz 
// 49911 = (2^16) - 16MHz/1025/1Hz
// 57723.5


/**********************************************************************************************************
 *  Nombre:      Loop
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Loop general.
 **********************************************************************************************************/

int main(void) {
  DDRB = 0b00100000; // bit 5 puerto B como salida
  PORTB = 0b00000000;
  noInterrupts();           // desabilita interrupciones
      TCCR1A = 0;               // configuracion basica
      TCCR1B = 0;               // configuracion basica
      TCNT1 = precarga;  
      OCR1B = 57723 ;        
      ////////////////////////////////////////
      // CS02     CS01     CS00     scale
      //  0         0       0     sin reloj
      //  0         0       1     clk/1 
      //  0         1       0     clk/8
      //  0         1       1     clk/64
      //  1         0       0     clk/256
      //  1         0       1     clk/1024
      //  1         1       0     externo en T1 falling
      //  1         1       1     externo en T1 rising
      ////////////////////////////////////////

      TCCR1B |= (1 << CS12);    
      TCCR1B |= (0 << CS11);    
      TCCR1B |= (1 << CS10); 
      TIMSK1 |= (1 << OCIE1B);   // activa interrupcion por desvordamiento
  interrupts();             // activa interrupciones

  while (1) {
                              
  }                                                 
  return (0);  
}

/**********************************************************************************************************
 *  Nombre:      ISR(TIMER1_OVF_vect) 
 *  Retorna:     Nada
 *  Parametros:  Nada
 *  Descripcion: Se activa cada vez que se desvorda el timer 0
 **********************************************************************************************************/

ISR(TIMER1_COMPB_vect)        
{
  TCNT1 = precarga;  
  PORTB = PINB ^(1 << PINB5);
}

