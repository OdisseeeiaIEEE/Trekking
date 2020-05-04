/* A fazer

sem nada: A fazer
F:        Fazendo
V:        Feito e testado

* [F] Classes primarias de motores
* [ ] Classes primarias de sensores
* [V] freeRTOS
* [ ] Serial
* [ ] Encoder


*https://www.arduino.cc/en/Hacking/libraryTutorial
*https://playground.arduino.cc/Code/Struct/
*https://www.inf.pucrs.br/~pinho/PRGSWB/OO/oocpp.html
*/

/*********************************/
/*           Bibliotecas         */
/*********************************/
#include <Arduino_FreeRTOS.h>



//verificar pinagem!
#define m_Pin_A 11   //pinos de tração dianteira
#define m_Pin_B 12
#define m_Pin_C 13   //pinos de tração traseira
#define m_Pin_D 14
#define m_Pin_E 15   //pinos de direcao
#define m_Pin_F 16

#define traDian true     //tracao dianteira
#define traTras true     //tracao traseira
#define leituraEsquerda true //Sensor Esquerdo(olhando o carrinho de tras)
#define leituraCentral true //Sensor Central
#define leituraDireita true //Sensor Direito


#include "Omnius.h"


void Main( void *pvParameters );


Omnius Erasmus();
/*em Duna. Omnius é a supermente e Eramus é só robô responsável
*por realizar os mais diversos tipos de experimento*/

Motor motor(m_Pin_A, m_Pin_B, m_Pin_C, m_Pin_D, m_Pin_E, m_Pin_F);


void setup ()
{
  xTaskCreate(
    Main
    ,  "Main"   // A name just for humans
    ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  NULL );
}

void loop ()
{
  //nao usar
  //esta aqui por enfeite do copilador
}

void Main(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  for (;;)
  {
    //code here
  }
}
