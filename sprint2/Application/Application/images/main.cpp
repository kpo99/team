#include <SFML/Graphics.hpp>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#define MAX_SPEED 80
#define MIN_ANGLE 4

using namespace sf;


class Images
{
public:
    int positionX;
    int positionY;
    int originX;
    int originY;
    String File;
    Image image;
    Texture texture;
    Sprite sprite;

    Images(String F, int positionX = 0, int positionY = 0, int originX = 0, int originY = 0)    //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
    {
        File = F;
        image.loadFromFile(File);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setPosition(positionX, positionY);
        sprite.setOrigin(Vector2f(originX, originY));
    }
};

void Draw(RenderWindow * window, int i, Images * arrow, Images * left)
{
    arrow->sprite.setRotation(i);
    window->draw(left->sprite);
    window->draw(arrow->sprite);
}

int main()
{
    char * gear = "1";
    int speed = 97;
    int status = 0, check = 0;
    double i = 4;

    char com[5] = "";
    DWORD numbytes = sizeof(char), numbytes_ok;

    char * COM = "\\\\.\\COM";
    char ComPort[20];
    int ComNum = 1;
    char  PortOpen[5];

    HANDLE Port = INVALID_HANDLE_VALUE;

    while (Port == INVALID_HANDLE_VALUE)
    {
        if(ComNum < 50)
        {
            sprintf(ComPort, "%s", COM);
            sprintf(PortOpen, "%i", ComNum);
            strcat(ComPort,PortOpen);
            Port = CreateFile(ComPort, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
            ComNum++;
        }
        else
            return 0;
    }

    COMMTIMEOUTS CommTimeOuts;
    CommTimeOuts.ReadIntervalTimeout = 5;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
    CommTimeOuts.ReadTotalTimeoutConstant = 0;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(Port, &CommTimeOuts);


    RenderWindow window(VideoMode(900, 675), "BotiCar");

    Images background("background.png");
    Images left("left.png");
    Images leftLed("left-led.png");
    Images right("right.png");
    Images rightLed("right-led.png");
    Images led("led.png");
    Images arrow("arrow.png", 138, 540, 77, 29);

    Font font;
    font.loadFromFile("CyrilicOld.ttf");
    Text text("", font, 20);
    text.setColor(Color::White);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            com[0] = 'a';
            if(status == 0)
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < 4) i = 4;
                    Draw(&window, i, &arrow, &left);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }
                for( int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i-= 0.5;
                    if(i < 4) i = 4;
                    Draw(&window, i, &arrow, &background);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }
            }
            else
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < 4) i = 4;
                    Draw(&window, i, &arrow, &leftLed);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }

                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < 4) i = 4;
                    Draw(&window, i, &arrow, &led);;

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }
            }
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            com[0] = 'd';
            if(status == 0)
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < MIN_ANGLE) i = MIN_ANGLE;
                    Draw(&window, i, &arrow, &right);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }

                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < MIN_ANGLE) i = MIN_ANGLE;
                    Draw(&window, i, &arrow, &background);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }
            }
            else
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < MIN_ANGLE) i = MIN_ANGLE;
                    Draw(&window, i, &arrow, &rightLed);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }

                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                for(int j = 0; j < MAX_SPEED; j++)
                {
                    if (i > MIN_ANGLE) i -= 0.5;
                    if(i < MIN_ANGLE) i = MIN_ANGLE;
                    Draw(&window, i, &arrow, &led);

                    text.setString(gear);
                    text.setPosition(135, 610);
                    window.draw(text);

                    window.display();
                }
            }
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
            if(check==0)
            {
            com[0] = 'n';
            if(status == 0)
                com[0] = 'l';

            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);

            status++;
            status = status % 2;
            check = 1;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (i < speed) i += (speed - 3) / 470.0;
            else i -= 1,5;
            com[0] = 'w';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (i < 97) i += 0.2;
            else i -= 1,5;
            com[0] = 's';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            gear = "1";
            speed = 97;
            com[0] = '1';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num2))
        {
            gear = "2";
            speed = 170 + 1;
            com[0] = '2';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num3))
        {
            gear = "3";
            speed = 260 + 3;
            com[0] = '3';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }
        else
        {
            if (i > MIN_ANGLE) i -= 2;
            com[0] = ' ';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            check = 0;
        }

        if (status == 1)
        {
            window.draw(led.sprite);
        }
        else
        {
            window.draw(background.sprite);
        }

        arrow.sprite.setRotation(i);
        window.draw(arrow.sprite);

        text.setString(gear);
        text.setPosition(135, 610);
        window.draw(text);

        window.display();
    }

    PurgeComm(Port, PURGE_RXCLEAR);
    PurgeComm(Port, PURGE_TXCLEAR);

    CloseHandle(Port);
    return 0;
}
