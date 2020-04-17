/* A fazer
* [ ] Classes primarias de motores
* [ ] Classes primarias de sensores
* [ ] freeRTOS
* [ ] Serial
* [ ] Encoder

*https://www.arduino.cc/en/Hacking/libraryTutorial
*https://playground.arduino.cc/Code/Struct/
*https://www.inf.pucrs.br/~pinho/PRGSWB/OO/oocpp.html
*/

//verificar pinagem!
#define m_Pin_A 11   //pinos de tração dianteira
#define m_Pin_B 12
#define m_Pin_C 13   //pinos de tração traseira
#define m_Pin_D 14
#define m_Pin_E 15   //pinos de direcao
#define m_Pin_F 16

#define traDian true     //tracao dianteira
#define traTras true     //tracao traseira


#include "Omnius.h"


Omnius Erasmus();
/*em Duna. Omnius é a supermente e Eramus é só robô responsável
*por realizar os mais diversos tipos de experimento*/

Motor motor(m_Pin_A, m_Pin_B, m_Pin_C, m_Pin_D, m_Pin_E, m_Pin_F);


void setup ()
{

}

void loop ()
{

}
