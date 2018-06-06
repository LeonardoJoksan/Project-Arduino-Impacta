#include <AFMotor.h>
#include <SoftwareSerial.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int buzzer = 12;

SoftwareSerial bluetooth(1, 0);

void setup() 
{
  // put your setup code here, to run once:
  motor1.setSpeed(250); //Velocidade máxima 
  motor2.setSpeed(250);
  motor3.setSpeed(250);
  motor4.setSpeed(250);
  bluetooth.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  if (bluetooth.available()>0) {
    char const incomingByte = bluetooth.read();

    switch (incomingByte) {
      case 'B': // Aciona a buzina
          tone(buzzer,1800);   
          delay(500);
        break;
      case 'W': // Move para frente
          motor1.run(FORWARD);
          motor2.run(BACKWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
        break;
      case 'A': // Move para a esquerda
          motor1.run(RELEASE);
          motor2.run(BACKWARD);
          motor3.run(RELEASE);
          motor4.run(FORWARD);
        break;
      case 'S': // Move para trás.
          motor1.run(BACKWARD);
          motor2.run(FORWARD);
          motor3.run(BACKWARD);
          motor4.run(BACKWARD);
        break;
      case 'D': // Move para direita
          motor1.run(FORWARD);
          motor2.run(RELEASE);
          motor3.run(FORWARD);
          motor4.run(RELEASE);
        break;
      case 'P':
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          motor3.run(RELEASE);
          motor4.run(RELEASE);
        break;
    }
  }
}
