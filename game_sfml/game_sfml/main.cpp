#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1920, 1080), "game");
	window.setFramerateLimit(60); // количество кадров в секунду
    //персонаж
	Image heroimage;
	heroimage.loadFromFile("images/pers.jpg");


	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(0, 0, 362, 364));
	herosprite.setPosition(10, 5);
	//
	
	//Игровое время
	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::A)) { herosprite.move(-0.1 * time, 0); }
		if (Keyboard::isKeyPressed(Keyboard::D)) { herosprite.move(0.1 * time, 0); }
		if (Keyboard::isKeyPressed(Keyboard::W)) { herosprite.move(0, -0.1 * time); }
		if (Keyboard::isKeyPressed(Keyboard::S)) { herosprite.move(0, 0.1 * time); }

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}