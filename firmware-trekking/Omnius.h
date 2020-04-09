class motor
{
  public:
    motor(int pinA, int pinB);

    void frente();
    void re();

  private:
    int _pinA, _pinB;
};

motor::motor(int pinA, int pinB)
{
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  _pinA = pinA;
  _pinB = pinB;
}

void motor::frente ()
{

}

void motor::re ()
{

}
