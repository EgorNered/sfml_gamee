#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;


int main()
{
	RenderWindow window(VideoMode(1920, 1080), "game");
	window.setFramerateLimit(60); // ���������� ������ � ������� (60)
    //��������
	Image heroimage;
	heroimage.loadFromFile("images/pers.png");


	Texture herotexture;
	herotexture.loadFromImage(heroimage);

	Sprite herosprite;
	herosprite.setTexture(herotexture);
	herosprite.setTextureRect(IntRect(4,775,101,774));
	herosprite.setPosition(10, 5);
	//
	
	
	float CurrentFrame = 0; //������ ������� ����
	//������� �����
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

		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������
			if (CurrentFrame > 9) CurrentFrame -= 9; // ���� ������ � 9 ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), 559, 1020, 100)); //���������� �� ����������� �.
			herosprite.move(-0.2 * time, 0);//���������� ���� �������� ��������� �����
		}
		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) { //���� ������ ������� ������� ����� ��� ���� ����� D
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������.
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //���������� �� ����������� �.
			herosprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����
		}
		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) { //���� ������ ������� ������� ����� ��� ���� ����� W
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. 
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //���������� �� ����������� �. 
			herosprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����
		}
		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� S
			CurrentFrame += 0.005 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. 
			if (CurrentFrame > 3) CurrentFrame -= 3; // ���� ������ � �������� ����� - ������������ �����.
			herosprite.setTextureRect(IntRect(100 * int(CurrentFrame), #, #, #)); //���������� �� ����������� �. 
			herosprite.move(-0.1 * time, 0);//���������� ���� �������� ��������� �����
		}

		window.clear();
		window.draw(herosprite);
		window.display();
	}

	return 0;
}