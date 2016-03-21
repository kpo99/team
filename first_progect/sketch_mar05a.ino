#define ENB 3
#define ENA 9
#define IN1 7
#define IN2 6
#define IN3 5
#define IN4 4
int stopLed = 11;
int Led = 13;
int avariyka = 12;

int pinLed = 13;
char incomingByte;
int dspeed = 20;
int nowspeed = 0;
int peredacha = 0;

void setup() {
  pinMode(blut,OUTPUT);
  pinMode(Led, OUTPUT);
  pinMode(stopLed, OUTPUT);
  pinMode(avariyka, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void go(int nowspeed)
{
  analogWrite(ENA, nowspeed);
  analogWrite(ENB, nowspeed);
}

void loop() {
  digitalWrite(blut,HIGH);
  if (Serial.available() > 0) {

    incomingByte = Serial.read();
    Serial.println(incomingByte);

    switch (incomingByte)
    {
      case 'w':
        nowspeed += dspeed;
lable:
        if (nowspeed > 85 + 85 * peredacha)
          nowspeed = 85 + 85 * peredacha;
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        go(nowspeed);
        break;

      case 's':
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        go(150);
        digitalWrite(stopLed, HIGH);
        break;

      case '1':
        peredacha = 0;
        goto lable;
        break;

      case '2':
        peredacha = 1;
        goto lable;
        break;

      case '3':
        peredacha = 2;
        goto lable;
        break;
    }
  }
}
