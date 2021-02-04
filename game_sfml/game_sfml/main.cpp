#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1920, 1080), "game");
	window.setFramerateLimit(60); // количество кадров в секунду (60)
    //персонаж
	Image heroimage;
	heroimage.loadFromFile("images/pers.png");


	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(4,775,101,774));
	herosprite.setPosition(10, 5);
	//
	
	
	float CurrentFrame = 0; //Хранит текущий кадр
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

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //если нажата клавиша стрелка влево или англ буква А
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости
			if (CurrentFrame > 9) CurrentFrame -= 9; // если пришли к 9 кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), 559, 1020, 100)); //проходимся по координатам Х.
			herosprite.move(-0.2 * time, 0);//происходит само движение персонажа влево
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { //если нажата клавиша стрелка влево или англ буква D
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости.
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //проходимся по координатам Х.
			herosprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { //если нажата клавиша стрелка влево или англ буква W
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. 
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //проходимся по координатам Х. 
			herosprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква S
			CurrentFrame += 0.005 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. 
			if (CurrentFrame > 3) CurrentFrame -= 3; // если пришли к третьему кадру - откидываемся назад.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //проходимся по координатам Х. 
			herosprite.move(-0.1 * time, 0);//происходит само движение персонажа влево
		}

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}