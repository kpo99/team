#include <SFML/Graphics.hpp>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace sf;
int main()
{
	RenderWindow window(VideoMode(900, 675), "App");

	Image fon;
	fon.loadFromFile("images/background.png");

	Texture fontexture;
	fontexture.loadFromImage(fon);

	Sprite fonsprite;
	fonsprite.setTexture(fontexture);
	fonsprite.setPosition(0, 0);

	Image left;
	left.loadFromFile("images/left.png");
	left.createMaskFromColor(Color(255,255,255));

	Texture lefttexture;
	lefttexture.loadFromImage(left);

	Sprite leftsprite;
	leftsprite.setTexture(lefttexture);

	Image right;
	right.loadFromFile("images/right.png");
	right.createMaskFromColor(Color(255, 255, 255));

	Texture righttexture;
	righttexture.loadFromImage(right);

	Sprite rightsprite;
	rightsprite.setTexture(righttexture);

	Image led;
	led.loadFromFile("images/led.png");
	led.createMaskFromColor(Color(255, 255, 255));

	Texture ledtexture;
	ledtexture.loadFromImage(led);

	Sprite ledsprite;
	ledsprite.setTexture(ledtexture);
	int status = 0;
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
				window.close();
		}
	if (Keyboard::isKeyPressed(Keyboard::A)) {
			for (int i = 0; i < 1500; i++){
				window.draw(leftsprite);
				window.display();
			}
			for (int i = 0; i < 1500; i++){
				window.draw(fonsprite);
				window.display();
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::D)){
			for (int i = 0; i < 100; i++){
				window.draw(rightsprite);
				window.display();
			}
		}
		else if (Keyboard::isKeyPressed(Keyboard::L)){
			status++;
			status = status % 2;
	
				}

		window.draw(fonsprite);
		window.display();
	}
	return 0;
}