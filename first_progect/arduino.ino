int pinForward = 13;
int pinBackward = 12;
int gear = 3;
char incomingByte;
void setup() {
 pinMode(pinForward,OUTPUT);
  pinMode(pinBackward,OUTPUT);
 Serial.begin(9600);
}

void loop() {
if (Serial.available() > 0){
  gear = 3;
  incomingByte = Serial.read();

  switch (incomingByte)
  { 
    case 'w':

    analogWrite(pinForward,255);
    delay(20);
    analogWrite(pinForward,0);
    
    break;
    
    case 's':
 
   /* analogWrite(pinBackward,gear*85);
    delay(8);
    analogWrite(pinBackward,0);*/
    analogWrite(pinBackward,0);
    break;
    
    case '1':
    gear = 1;
    break;
    
    case '2':
    gear = 2;
    break;
    
    case '3':
    gear = 3;
    break;
    case ' ':
    gear = 0;
    break;
    
  default:
      break;
  }
  }
}
