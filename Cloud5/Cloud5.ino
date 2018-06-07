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
  motor1.setSpeed(500); //Velocidade máxima 
  motor2.setSpeed(500);
  motor3.setSpeed(500);
  motor4.setSpeed(500);
  bluetooth.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  if (bluetooth.available()>0) {
    char const incomingByte = bluetooth.read();

    switch (incomingByte) {
      case 'V': // Aciona a buzina
          tone(buzzer,1800);   
          delay(500);
        break;
      case 'F': // Move para frente
          motor1.run(FORWARD);
          motor2.run(BACKWARD);
          motor3.run(FORWARD);
          motor4.run(FORWARD);
        break;
      case 'L': // Move para a esquerda
          motor1.run(RELEASE);
          motor2.run(BACKWARD);
          motor3.run(RELEASE);
          motor4.run(FORWARD);
        break;
      case 'B': // Move para trás.
          motor1.run(BACKWARD);
          motor2.run(FORWARD);
          motor3.run(BACKWARD);
          motor4.run(BACKWARD);
        break;
      case 'R': // Move para direita
          motor1.run(FORWARD);
          motor2.run(RELEASE);
          motor3.run(FORWARD);
          motor4.run(RELEASE);
        break;
      case 'S':
          motor1.run(RELEASE);
          motor2.run(RELEASE);
          motor3.run(RELEASE);
          motor4.run(RELEASE);
        break;
      case 10:
          motor1.setSpeed(500); //Velocidade máxima 
          motor2.setSpeed(500);
          motor3.setSpeed(500);
          motor4.setSpeed(500);
        break;
      case 9:
          motor1.setSpeed(450); //Velocidade máxima 
          motor2.setSpeed(450);
          motor3.setSpeed(450);
          motor4.setSpeed(450);
        break;
     case 8:
          motor1.setSpeed(400); //Velocidade máxima 
          motor2.setSpeed(400);
          motor3.setSpeed(400);
          motor4.setSpeed(400);
        break;
     case 7:
          motor1.setSpeed(350); //Velocidade máxima 
          motor2.setSpeed(350);
          motor3.setSpeed(350);
          motor4.setSpeed(350);
        break;
     case 6:
          motor1.setSpeed(300); //Velocidade máxima 
          motor2.setSpeed(300);
          motor3.setSpeed(300);
          motor4.setSpeed(300);
        break;
     case 5:
          motor1.setSpeed(250); //Velocidade máxima 
          motor2.setSpeed(250);
          motor3.setSpeed(250);
          motor4.setSpeed(250);
        break;
     case 4:
          motor1.setSpeed(200); //Velocidade máxima 
          motor2.setSpeed(200);
          motor3.setSpeed(200);
          motor4.setSpeed(200);
        break;
     case 3:
          motor1.setSpeed(150); //Velocidade máxima 
          motor2.setSpeed(150);
          motor3.setSpeed(150);
          motor4.setSpeed(150);
        break;
     case 2:
          motor1.setSpeed(100); //Velocidade máxima 
          motor2.setSpeed(100);
          motor3.setSpeed(100);
          motor4.setSpeed(100);
        break;
     case 1:
          motor1.setSpeed(50); //Velocidade máxima 
          motor2.setSpeed(50);
          motor3.setSpeed(50);
          motor4.setSpeed(50);
        break;
     case 0:
          motor1.setSpeed(0); //Velocidade máxima 
          motor2.setSpeed(0);
          motor3.setSpeed(0);
          motor4.setSpeed(0);
        break;
    }
  }
}
