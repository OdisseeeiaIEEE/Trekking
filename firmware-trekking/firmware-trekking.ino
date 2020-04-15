/* A fazer
* Classes primarias de motores
* Classes primarias de sensores
* freeRTOS

*https://www.arduino.cc/en/Hacking/libraryTutorial
*https://playground.arduino.cc/Code/Struct/
*https://www.inf.pucrs.br/~pinho/PRGSWB/OO/oocpp.html
*/

//verificar pinagem!
#define m_Pin_A 11   //pinos de tração dianteira
#define m_Pin_B 12
#define m_Pin_C 13   //pinos de tração traseira
#define m_Pin_D 14

#define traDian true     //tracao dianteira
#define traTras true     //tracao traseira


#include "Omnius.h"


Motor motor(m_Pin_A, m_Pin_B, m_Pin_C, m_Pin_D);


void setup ()
{

}

void loop ()
{

}
