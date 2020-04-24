#include "Arduino.h"

/*********************************/
/*              Motores          */
/*********************************/

class Motor
{
  public:
    Motor(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF);

    void frente();
    void re();
    void virarDireita();
    void virarEsquerda();
    void centralizar();

  private:
    int _pinA, _pinB, _pinC, _pinD, _pinE, _pinF;
};

Motor::Motor(int pinA, int pinB, int pinC, int pinD, int pinE, int pinF)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);

  _pinA = pinA;
  _pinB = pinB;
  _pinC = pinC;
  _pinD = pinD;
  _pinE = pinE;
  _pinF = pinF;
}

void Motor::frente ()
{
  if(traDian)
  {
    digitalWrite(_pinA, LOW);
    digitalWrite(_pinB, HIGH);
  }
  if(traTras)
  {
    digitalWrite(_pinC, LOW);
    digitalWrite(_pinD, HIGH);
  }
}

void Motor::re ()
{
  if(traDian)
  {
    digitalWrite(_pinA, HIGH);
    digitalWrite(_pinB, LOW);
  }
  if(traTras)
  {
    digitalWrite(_pinC, HIGH);
    digitalWrite(_pinD, LOW);
  }

}

void Motor::virarDireita ()
{
   digitalWrite(_pinE, LOW);
   digitalWrite(_pinF, HIGH);
}

void Motor::virarEsquerda ()
{
   digitalWrite(_pinE, HIGH);
   digitalWrite(_pinF, LOW);
}

void Motor::centralizar ()
{
  digitalWrite(_pinE, LOW);
  digitalWrite(_pinF, LOW);

}


/*********************************/
/*       Comunicação Serial      */
/*********************************/

/*
A fução vai retornar true or false se encontrar o dado que se procura.
e retornar seu valor.

"tipo"="valor";
*/

class Omnius
{
  public:
    Omnius();

    void serial_baudrate(int baud_rate);
    void serial_reading();
    int serial_return(String procurar);

  private:
    bool stop = false;
    char r; //armazenar char lido
    String reading = ""; //armazenar array char lido
};

Omnius::Omnius()
{
  Serial.begin(115200); //baud_rate padrao
}

void Omnius::serial_baudrate(int baud_rate)
{
  Serial.begin(baud_rate);
}

void Omnius::serial_reading()
{
  reading = "";

  while ((Serial.available() > 0) && !stop) //enquanto tiver informacao para ler e stop == false
  {
    r = Serial.read(); //faz leitura do ultimo char

    if(r == ';') // ; indica que acabou a leitura
      stop = true;
    else
      reading += r;  //preencher a string
  }

  stop = false;
}

int Omnius::serial_return(String procurar)
{
  if(reading.indexOf("procurar") >= 0) //indexOf retorna o indice que começa a string procurar
  {
    String _read = reading.substring(reading.indexOf("=") + 1, reading.indexOf(";"));

    return _read.toInt();
  }
  else
    return -1;
}
