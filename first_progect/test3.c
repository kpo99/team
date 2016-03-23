struct MOTOR
{
int in1; // INPUT1
int in2; // INPUT2
int enable; // ENABLE1
};

MOTOR MOTOR1 = { 13, 12, 11 };
MOTOR MOTOR2 = { 7, 8, 9 };

void setup()
{
Serial.begin(9600);
pinMode(MOTOR1.in1, OUTPUT);
pinMode(MOTOR1.in2, OUTPUT);
pinMode(MOTOR2.in1, OUTPUT);
pinMode(MOTOR2.in2, OUTPUT);
}

void loop()
{
forward1();
forward2();
delay(3000);
back2();
delay(500);
forward2();
}

void forward1()
{
digitalWrite(MOTOR1.in1, HIGH);
digitalWrite(MOTOR1.in2, LOW);
analogWrite(MOTOR1.enable, 254);
}

void forward2()
{
digitalWrite(MOTOR2.in1, HIGH);
digitalWrite(MOTOR2.in2, LOW);
analogWrite(MOTOR2.enable, 254);
}

void back1()
{
digitalWrite(MOTOR1.in1, LOW);
digitalWrite(MOTOR1.in2, HIGH);
analogWrite(MOTOR1.enable, 254);
}

void back2() {
digitalWrite(MOTOR2.in1, LOW);
digitalWrite(MOTOR2.in2, HIGH);
analogWrite(MOTOR2.enable, 254);
}
