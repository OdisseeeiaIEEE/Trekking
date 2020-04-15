#include "Arduino.h"

/*********************************/
/*              Motores          */
/*********************************/

class Motor
{
  public:
    Motor(int pinA, int pinB, int pinC, int pinD);

    void frente();
    void re();

  private:
    int _pinA, _pinB, _pinC, _pinD;
};

Motor::Motor(int pinA, int pinB, int pinC, int pinD)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);

  _pinA = pinA;
  _pinB = pinB;
  _pinC = pinC;
  _pinD = pinD;
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

  private:
    char r; //armazenar char lido
    String reading = ""; //armazenar array char lido
};

serial::serial(int baud_rate)
{
  Serial.begin(baud_rate);
}

void serial::main()
{
  // while(Serial.available)
  // {
  //   r = Serial.read();
  //
  //   //se r for igual a ";" significa que a leitura foi terminada
  // }
}
