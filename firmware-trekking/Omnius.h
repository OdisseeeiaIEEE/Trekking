#include "Arduino.h"

/*********************************/
/*              Motores          */
/*********************************/

class Motor
{
  public:
    Motor(int pinA, int pinB);

    void iniciar(int pinA, int pinB);
    void frente();
    void re();

  private:
    int _pinA, _pinB; //precisa dessas var?
};

Motor::Motor(int pinA, int pinB)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
}

void Motor::iniciar(int pinA, int pinB)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
}

void Motor::frente ()
{

}

void Motor::re ()
{

}


/*********************************/
/*       Comunicação Serial      */
/*********************************/

/*
A fução vai retornar true or false se encontrar o dado que se procura.
e retornar seu valor.

"tipo"="valor";
*/

class serial
{
  public:
    serial(int baud_rate);

    void main();
    char r; //armazenar char lido
    string reading; //armazenar array char lido

  private:
};

serial::serial(int baud_rate)
{
  Serial.begin(baud_rate);
}

serial::main()
{
  whilea(Serial.available > 0)
  {
    r = Serial.read();

    //se r for igual a ";" significa que a leitura foi terminada
  }
}
