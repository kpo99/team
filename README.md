#BotiCar:

Рік випуску: 2016<br/>
Розробник: DreamTeam<br/>
Платфома: Windows<br/>

<h4>Необхідні компоненти:</h4>
1.)Arduino Leonardo<br/>
2.)Driver Module L298N<br/>
3.)Ultrasonic Distance Module(HC-SR04)<br/>
4.)Bluetooth module(HC-06)<br/>
5.)Power Supply (!!! less then 12V, because of direct supplying Motor Driver logical chain and Arduino Motor Driver Pin)<br/>
6.)Lots of 1 pin cables (M-M, M-F)<br/>

<h4>Інструкція підключення:</h4>
1.) Connect Arduino Pin 3 to ENB Motor Driver Pin<br/>
2.) Connect Arduino Pin 4 to IN4 Motor Driver Pin<br/>
3.) Connect Arduino Pin 5 to IN3 Motor Driver Pin<br/>
4.) Connect Arduino Pin 6 to IN2 Motor Driver Pin<br/>
5.) Connect Arduino Pin 7 to IN1 Motor Driver Pin<br/>
6.) Connect Arduino Pin 9 to ENA Motor Driver Pin<br/>
Note: ENB and ENA use to control car speed due PWM<br/>
7.)Connect Power Supply to Motor Driver<br/>
8.)Connect all grounds into one line<br/>
9.)Connect Vin on Arduino to 5v Motor Driver to supply Arduino<br/>
10.)Connect Arduino Pin 11 to Stop Led <br/>
11.)Connect Arduino Pin 13 to Led <br/>
11.)Connect Arduino Pin 12 to Emergency Led <br/>
12.)Connect 5V Arduino output to HC-06 in<br/>
13.)Connect Arduino Ground to HC-06 Ground<br/>
14.)Connect RX Arduino to HC-06 TX<br/>
15.)Connect TX Arduino to HC-06 RX<br/>
16.)Connect HC-SR04 Ground to Arduino Ground<br/>
17.)Connect HC-SR04 Vcc to Arduino Pin 2<br/>
18.)Connect HC-SR04 Echo to Arduino Pin 9<br/>
19.)Connect HC-SR04 Triger to Arduino Pin 10<br/>
20.)Compile and Upload sketch to Arduino<br/>
21.)Run application on your Windows PC from .exe file<br/>
<h4>Використання:</h4>
Use WASD to control car moving<br/>
Use L key to turn on/off lightning<br/>
Use Q key to turn on/off autopilot<br/>  
