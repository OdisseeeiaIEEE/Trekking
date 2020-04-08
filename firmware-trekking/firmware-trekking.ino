  #define pino_sensor1 A0
  #define pino_sensor2 A1
  #define pino_sensor3 A2
  #define Interrupetor A3
  const int pinoBotao = 12; //PINO DIGITAL UTILIZADO PELO PUSH BUTTON

  
  #define MotorA1 1
  #define MotorA2 2
  #define MotorAvelo 3
  #define MotorB1 4
  #define MotorB2 5
  #define MotorVvelo
  #define MotorC1 6
  #define MotorC2 7
  #define MotorcVelo 9

  #define giroflexA 10
  #define giroflexB 11

//atribuições de portas dos sensores, motores e do giroflex

  int estado_sensor1 = 0;
  int estado_sensor2 = 0;
  int estado_sensor3 = 0;
 
 //inicialização das variáveis de estado de sensor, sendo que quando o sensor está igual a 0 significa que está encontrando um obstáculo, e quando está em 1 signifioca que seu caminho está livre.
void setup() {

   Serial.begin(9600);

    pinMode(pinoBotao, INPUT_PULLUP); //DEFINE O PINO COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
 
    pinMode(pino_sensor1, INPUT);
    pinMode(pino_sensor2, INPUT);
    pinMode(pino_sensor3, INPUT);
    pinMode(Interrupetor,INPUT);
    pinMode(giroflexA,OUTPUT);
    pinMode(giroflexB,OUTPUT);
    pinMode(MotorA1, OUTPUT);
    pinMode(MotorA2, OUTPUT);
    pinMode(MotorB1, OUTPUT);
    pinMode(MotorB2, OUTPUT);
    pinMode(MotorC1, OUTPUT);
    pinMode(MotorC2, OUTPUT);

    digitalWrite(giroflexA, LOW); //Giroflex INICIA DESLIGADO
    digitalWrite(giroflexB, LOW);

//pinos com modo de entrada (sensores) e saidas (outros)
}

void loop() {
 
 
 
 if(digitalRead(pinoBotao) == LOW){
 
 estado_sensor1 = digitalRead(pino_sensor1);
 estado_sensor2 = digitalRead(pino_sensor2);
 estado_sensor3 = digitalRead(pino_sensor3);
 //estado de sensor, sendo lido no pino que esta ligado

    Serial.println ("Sensor 1");
    Serial.println (estado_sensor1);
    Serial.println ("Sensor 2");
    Serial.println (estado_sensor2);
    Serial.println ("Sensor 3");
    Serial.println (estado_sensor3);
    Serial.println ("estado_Interrupetor");
    // impressão na tela de qual o estado atual do sensor

 
    if (estado_sensor1 == 1 && estado_sensor2 == 1 && estado_sensor3 == 1)
    {
    digitalWrite(MotorA1,LOW);
    digitalWrite(MotorA2,HIGH);
    digitalWrite(MotorB1,LOW);
    digitalWrite(MotorB2,HIGH); 
    digitalWrite(MotorC1,LOW);
    digitalWrite(MotorC2,LOW);
    Serial.println("PARA FRENTE");
    digitalWrite(giroflexA,HIGH);
    digitalWrite(giroflexB,LOW); 
     // se todos os sensores estiverem desligados, os motores estão programados pro carro ir pra frente 
    }
    else if ( estado_sensor2 == 0 && estado_sensor3 == 0 && estado_sensor1 == 1)
    {
  digitalWrite(MotorA1,LOW);
  digitalWrite(MotorA2,HIGH);
  digitalWrite(MotorB1,LOW);
  digitalWrite(MotorB2,HIGH);
  digitalWrite(MotorC1,HIGH);
  digitalWrite(MotorC2,LOW); 
  Serial.println("ESQUERDA");
  digitalWrite(giroflexA,HIGH);
  digitalWrite(giroflexB,LOW);
  // se apenas o sensor 1 estiver desligado, o carro vai pra esquerda 
    }
    else if ( estado_sensor1 == 0 && estado_sensor3 == 0 && estado_sensor2 == 1)
    {
    digitalWrite(MotorA1,LOW);
    digitalWrite(MotorA2,HIGH);
    digitalWrite(MotorB1,LOW);
    digitalWrite(MotorB2,HIGH);
    digitalWrite(MotorC1,LOW);
    digitalWrite(MotorC2,HIGH);
    Serial.println("DIREITA");
    digitalWrite(giroflexA,HIGH);
    digitalWrite(giroflexB,LOW);
    // se apenas o sensor 2 estiver desligado, o carro vai pra direita 
  }     
    else if ( estado_sensor1 == 0 && estado_sensor3 == 1 && estado_sensor2 == 1)
   {
    digitalWrite(MotorA1,LOW);
    digitalWrite(MotorA2,HIGH);
    digitalWrite(MotorB1,LOW);
    digitalWrite(MotorB2,HIGH);
    digitalWrite(MotorC1,LOW);
    digitalWrite(MotorC2,HIGH);
    Serial.println("DIREITA");
    digitalWrite(giroflexA,HIGH);
    digitalWrite(giroflexB,LOW);
        // se apenas o sensor 1 estiver ligado, o carro vai pra direita 
}
   else if ( estado_sensor2 == 0 && estado_sensor3 == 1 && estado_sensor1 == 1)
  {
    digitalWrite(MotorA1,LOW);
    digitalWrite(MotorA2,HIGH);
    digitalWrite(MotorB1,LOW);
    digitalWrite(MotorB2,HIGH);
    digitalWrite(MotorC1,HIGH);
    digitalWrite(MotorC2,LOW); 
    Serial.println("ESQUERDA");
    digitalWrite(giroflexA,HIGH);
    digitalWrite(giroflexB,LOW);
  // se apenas o sensor 2 estiver ligado, o carro vai pra esquerda 
  }
  else if ( estado_sensor3 == 0 && estado_sensor1 == 1 && estado_sensor2 == 1)
    {
      digitalWrite(MotorA1,HIGH);
      digitalWrite(MotorA2,LOW);
      digitalWrite(MotorB1,HIGH);
      digitalWrite(MotorB2,LOW); 
      digitalWrite(MotorC1,HIGH);
      digitalWrite(MotorC2,LOW); 
      Serial.println("PARA TRÁS");
  delay (1000);
      digitalWrite(giroflexA,LOW);
      digitalWrite(giroflexB,LOW);
     // se apenas o sensor 3 estiver ligado, o carro vai pra esquerdae para trás ao mesmo tempo 
  }
else {
 digitalWrite(MotorA1,LOW);
 digitalWrite(MotorA2,LOW);
 digitalWrite(MotorB1,LOW);
 digitalWrite(MotorB2,LOW); 
 digitalWrite(MotorC1,LOW);
 digitalWrite(MotorC2,LOW);
 Serial.println("PARAR");
 digitalWrite(giroflexA,HIGH);
 digitalWrite(giroflexB,LOW);
}
 //quando todos os sensores estão ligados ao mesmo tempo, o carrinho para ao mesmo tempo que liga o giroflex
  
}
else { 
 digitalWrite(MotorA1,LOW);
 digitalWrite(MotorA2,LOW);
 digitalWrite(MotorB1,LOW);
 digitalWrite(MotorB2,LOW); 
 digitalWrite(MotorC1,LOW);
 digitalWrite(MotorC2,LOW);
 Serial.println("PARAR");
 digitalWrite(giroflexA,HIGH);
 digitalWrite(giroflexB,LOW);
 //quando todos os sensores estão ligados ao mesmo tempo, o carrinho para ao mesmo tempo que liga o giroflex
}
//em todos os comandos, exceto o último, o giroflex deve permanecer desligado 
}
