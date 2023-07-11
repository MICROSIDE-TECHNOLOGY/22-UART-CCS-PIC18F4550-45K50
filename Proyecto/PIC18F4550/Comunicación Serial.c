/*
 AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
 FECHA: JUNIO 2019
*/

/*
------------------------------------------------------------------------------
 Implementar comunicación serial para enviar un comando simple para prender y
 apagar un LED incluido en la tarjeta X-TRAINER, y un segundo comando para
 preguntar el estado de un botón.
------------------------------------------------------------------------------
*/

#include <18F4550.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=48Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 
#build(reset=0x02000,interrupt=0x02008)         //Asignación de los vectores de reset e interrupción
#org 0x0000,0x1FFF {}                           //Reserva espacio en la memoria para la versión con bootloader

#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7,STREAM=UART ) //Configuración del puerto UART

#define LED PIN_A1                                              //Pin donde está conectado el LED del X-TRAINER
#define Boton PIN_A2                                            //Pin donde está conectado el BOTON del X-TRAINER

void main ()

  {
   while (1)
  {

   char Caracter = getc ();                         //Guarda el caracter
   if (Caracter == '0')
    {
      output_low (LED);                             //Apaga el LED
    }
    
     else if (Caracter == '1')
    {
     output_HIGH (LED);                             //Enciende el LED
    }
    
     else if (Caracter == '?')
    {
        if (1 == input (Boton))                     //Pregunta el estado del botón
          {                                                                   
            Printf ("0");                           //Envía un 0 si el botón no está presionado
          }
          
          else
         {
           Printf ("1");                            //Envía un 1 si el botón está presionado
         }
      }
   }
}
