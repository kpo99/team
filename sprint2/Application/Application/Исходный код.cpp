#include <SFML/Graphics.hpp>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_SPEED 200

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(900, 675), "BotiCar");
	int status = 0;

	Image fon; 
	fon.loadFromFile("images/background.png");
	Image left;
	left.loadFromFile("images/left.png");
	Image right;
	right.loadFromFile("images/right.png");
	Image led;
	led.loadFromFile("images/led.png");
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
			if (status != 1)
			{
				window.draw(leftsprite);
				window.display();
				Sleep(150);

				window.draw(fonsprite);
				window.display();
				Sleep(150);
			}
			else
			{
				window.draw(leftsprite);
				window.display();
				Sleep(150);

				window.draw(ledsprite);
				window.display();
				Sleep(150);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			if (status != 1)
			{
				window.draw(rightsprite);
				window.display();
				Sleep(150);

				window.draw(fonsprite);
				window.display();
				Sleep(150);
			}
			else
			{
				window.draw(rightsprite);
				window.display();
				Sleep(150);

				window.draw(ledsprite);
				window.display();
				Sleep(150);
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::L))
		{
			status++;
			status = status % 2;
			Sleep(150);
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{

		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{

		}
		else if (Keyboard::isKeyPressed(Keyboard::Num1))
		{

		}
		else if (Keyboard::isKeyPressed(Keyboard::Num2))
		{

		}
		else if (Keyboard::isKeyPressed(Keyboard::Num3))
		{

		}
		else
		{

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

	return 0;
}
