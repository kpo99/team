int pinLed = 13;
char incomingByte;
int dspeed=20;
int nowspeed=0;
int peredacha;
void setup() {
pinMode(13,OUTPUT);
Serial.begin(9600);
}

void loop() {
if (Serial.available() >= 0){

incomingByte = Serial.read();
Serial.println(incomingByte);

switch (incomingByte)
{
case 'w':
nowspeed+=dspeed;
lable:
if(nowspeed>85+85*peredacha)
nowspeed=85+85*peredacha;
analogWrite(pinLed,nowspeed);
break;

case 's':
nowspeed-=dspeed;
if(nowspeed<=0)
nowspeed=0;
analogWrite(pinLed,nowspeed);
break;

case '1':
peredacha=0;
goto lable;
break;

case '2':
peredacha=1;
goto lable;
break;

case '3':
peredacha=2;
goto lable;
break;
default:
analogWrite(pinLed,0);
break;
}



}
}
