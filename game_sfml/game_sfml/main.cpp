#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

////////////////////////////////////////////////////����� ������////////////////////////
class Player { // ����� ������
public:
	float x, y, w, h, dx, dy, speed; //���������� ������ � � �, ������ ������, ��������� (�� � � �� �), ���� ��������
	int dir; //����������� (direction) �������� ������
	String File; //���� � �����������
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	Player(String F, float X, float Y, float W, float H) { //����������� � �����������(�����������) ��� ������ Player. ��� �������� ������� ������ �� ����� �������� ��� �����, ���������� � � �, ������ � ������
		dx = 0; dy = 0; speed = 0; dir = 0;
		File = F;//��� �����+����������
		w = W; h = H;//������ � ������
		image.loadFromFile("images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������.
		image.createMaskFromColor(Color(41, 33, 59));
		texture.loadFromImage(image);//���������� ���� ����������� � ��������
		sprite.setTexture(texture);//�������� ������ ���������
		x = X; y = Y;//���������� ��������� �������
		sprite.setTextureRect(IntRect(0, 0, w, h)); //������ ������� ���� ������������� ��� ������ ������ ����, � �� ���� ����� �����. IntRect - ���������� �����
	}
	void update(float time) //������� "���������" ������� ������. update - ����������. ��������� � ���� ����� SFML , ���������� ���� �������� ����������, ����� ��������� ��������.
	{
		switch (dir)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
		{
		case 0: dx = speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
		case 1: dx = -speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
		case 2: dx = 0; dy = speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
		case 3: dx = 0; dy = -speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
		}

		x += dx * time;//���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
		y += dy * time;//���������� �� ������

		speed = 0;//�������� ��������, ����� �������� �����������.
		sprite.setPosition(x, y); //������� ������ � ������� x y , ����������.
	}
};

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "game");
	window.setFramerateLimit(60); // ���������� ������ � ������� (60)
    //���������
	Player p("pers.png", 4, 775, 101, 774); //������� ������ p ������ player,������ "hero.png" ��� ��� �����+����������, ����� ���������� �,�, ������, ������.
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

		///////////////////////////////////////////���������� ���������� � ���������////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed = 0.2;//dir =1 - ����������� �����, speed =0.1 - �������� ��������. 
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 559, 103, 103)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed = 0.2;//����������� �����
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 781, 103, 103)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; p.speed = 0.2;//����������� ����
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 662, 103, 103)); //����� ������ p ������ player ������ ������, ����� �������� (��������� �������� �����)

		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //���� ������ ������� ������� ����� ��� ���� ����� �
			p.dir = 2; p.speed = 0.2;//����������� �����
			CurrentFrame += 0.010 * time; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������.
			if (CurrentFrame > 9) CurrentFrame -= 9; //���������� �� ������ � ������� �� ������ ������������. ���� ������ � �������� ����� - ������������ �����.
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 450, 103, 103)); //���������� �� ����������� �. 

		}
		
		p.update(time);//�������� ������ p ������ Player � ������� ������� sfml, ��������� ����� � �������� ��������� ������� update. ��������� ����� �������� ����� ���������
		

		window.clear();
		window.draw(p.sprite);//������ ������ ������� p ������ player
		window.display();
	}

	return 0;
}