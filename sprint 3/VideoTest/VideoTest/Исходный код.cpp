//#include <opencv\cv.h>   // This is the original code, but I couldn't get VideoCapture work correctly.
#include <opencv2/opencv.hpp>
#include <opencv\highgui.h>
#include <SFML/Graphics.hpp>

int main() {
	cv::VideoCapture cap(0); // open the video file for reading
	if (!cap.isOpened())
	{
		return 0;
	}

	sf::RenderWindow window(sf::VideoMode(1280, 720), "RenderWindow");
	cv::Mat frameRGB, frameRGBA;
	sf::Image image;
	sf::Texture texture;
	sf::Event event;
	sf::Sprite sprite;
	
	while (window.isOpen())
	{  
		cap >> frameRGB;

		if (frameRGB.empty())
		{
			break;
		}

		cv::cvtColor(frameRGB, frameRGBA, cv::COLOR_BGR2RGBA);
		cv::Size size(640, 480);
		cv::resize(frameRGBA, frameRGBA, size);
		image.create(frameRGBA.cols, frameRGBA.rows, frameRGBA.ptr());


		if (!texture.loadFromImage(image))
		{
			break;
		}

		sprite.setTexture(texture);
		sprite.setPosition(100, 200);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.draw(sprite);
		window.display();
	}
	return 0;
}