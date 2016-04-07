#include <SFML/Graphics.hpp>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#define MAX_SPEED 200

using namespace sf;


class Images {
public:
    int positionX;
    int positionY;
    int originX;
    int originY;
    String File;
	Image image;
	Texture texture;
	Sprite sprite;

	Images(String F, int positionX = 0, int positionY = 0, int originX = 0, int originY = 0) {  //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		File = F;
		image.loadFromFile(File);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
        sprite.setPosition(positionX, positionY);
        sprite.setOrigin(Vector2f(originX, originY));
	}
};

int main()
{
    RenderWindow window(VideoMode(900, 675), "BotiCar");
    int speed = 97;
    int status = 0;
    double i = 0;

    HANDLE Port = CreateFile("\\\\.\\COM25", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    char com[10] = "";
    DWORD numbytes = sizeof(char), numbytes_ok;

    COMMTIMEOUTS CommTimeOuts;
    CommTimeOuts.ReadIntervalTimeout = 5;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
    CommTimeOuts.ReadTotalTimeoutConstant = 0;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(Port, &CommTimeOuts);

    if (Port == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, "        Unable to open the serial port", "Error", MB_OK);
        ExitProcess(1);
    }

    Images background("background.png");
    Images left("left.png");
    Images leftLed("left-led.png");
    Images right("right.png");
    Images rightLed("right-led.png");
    Images led("led.png");
    Images arrow("arrow.png", 138, 540, 77, 29);

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
                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(left.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.3);
                    window.draw(left.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }

                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(background.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.2);
                    window.draw(background.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }
            }
            else
            {
                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(leftLed.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.3);
                    window.draw(leftLed.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }

                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(led.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.2);
                    window.draw(led.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            com[0] = 'd';
            if(status == 0)
            {
                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(right.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.3);
                    window.draw(right.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }

                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(background.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.2);
                    window.draw(background.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }
            }
            else
            {
                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(rightLed.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.3);
                    window.draw(rightLed.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }

                if (i > 3) i -= 0.2;
                arrow.sprite.setRotation(i);
                window.draw(led.sprite);
                window.draw(arrow.sprite);
                    WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                window.display();

                for(int j = 0; j < 300; j++) {
                    if (i > 3) arrow.sprite.setRotation(i -= 0.2);
                    window.draw(led.sprite);
                    window.draw(arrow.sprite);
                    window.display();
                }
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
            com[0] = 'l';
            if(status == 0)
                com[0] = 'n';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);

            status++;
            status = status % 2;
            Sleep(150);
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            if (i < speed) i += 0.2;
            com[0] = 'w';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if (i < 97) i += 0.2;
            com[0] = 's';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            speed = 97;
            com[0] = '1';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num2))
        {
            speed = 170 + 1;
            com[0] = '1';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num3))
        {
            speed = 260 + 3;
            com[0] = '1';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else
        {
            if (i > 3) i -= 0.2;
            com[0] = ' ';
            for(int i = 0; i < 10; i++)
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            }
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
        window.display();
    }

    PurgeComm(Port, PURGE_RXCLEAR);
    PurgeComm(Port, PURGE_TXCLEAR);

    CloseHandle(Port);
    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_SPEED 200

using namespace sf;

int main()
{
    HANDLE Port = CreateFile("\\\\.\\COM25", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    char com[10] = "";
    DWORD numbytes = sizeof(char), numbytes_ok;
    int status = 0;

    COMMTIMEOUTS CommTimeOuts;
    CommTimeOuts.ReadIntervalTimeout = 5;
    CommTimeOuts.ReadTotalTimeoutMultiplier = 0;
    CommTimeOuts.ReadTotalTimeoutConstant = 0;
    CommTimeOuts.WriteTotalTimeoutMultiplier = 0;
    CommTimeOuts.WriteTotalTimeoutConstant = 0;
    SetCommTimeouts(Port, &CommTimeOuts);

    if (Port == INVALID_HANDLE_VALUE)
    {
        MessageBox(NULL, "        Unable to open the serial port", "Error", MB_OK);
        ExitProcess(1);
    }

    RenderWindow window(VideoMode(900, 675), "BotiCar");

    Image fon, left, right, led;
    fon.loadFromFile("background.png");
    left.loadFromFile("left.png");
    right.loadFromFile("right.png");
    led.loadFromFile("led.png");

    Texture fontexture, lefttexture, righttexture, ledtexture;
    fontexture.loadFromImage(fon);
    lefttexture.loadFromImage(left);
    righttexture.loadFromImage(right);
    ledtexture.loadFromImage(led);

    Sprite fonsprite, leftsprite, rightsprite, ledsprite;
    fonsprite.setTexture(fontexture);
    leftsprite.setTexture(lefttexture);
    rightsprite.setTexture(righttexture);
    ledsprite.setTexture(ledtexture);

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

            if(status != 1)
            {
                window.draw(leftsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);

                window.draw(fonsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);
            }
            else
            {
                window.draw(leftsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);

                window.draw(ledsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            com[0] = 'd';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);

            if(status != 1)
            {
                window.draw(rightsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);

                window.draw(fonsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);
            }
            else
            {
                window.draw(rightsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);

                window.draw(ledsprite);
                window.display();
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
                Sleep(150);
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
            com[0] = 'l';
            status++;
            status = status % 2;
            if(status == 0)
                com[0] = 'n';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            Sleep(150);
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            com[0] = 'w';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            com[0] = 's';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num1))
        {
            com[0] = '1';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num2))
        {
            com[0] = '2';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Num3))
        {
            com[0] = '3';
            WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
        }
        else
        {
            com[0] = ' ';
            for(int i = 0; i < 10; i++)
            {
                WriteFile(Port, com, numbytes, &numbytes_ok, NULL);
            }
        }

        if (status == 1)
        {
            window.draw(ledsprite);
        }
        else
        {
            window.draw(fonsprite);
        }
        window.display();
    }

    PurgeComm(Port, PURGE_RXCLEAR);
    PurgeComm(Port, PURGE_TXCLEAR);

    CloseHandle(Port);
    return 0;
}*/
