#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

////////////////////////////////////////////////////КЛАСС ИГРОКА////////////////////////
class Player { // класс Игрока
public:
	float x, y, w, h, dx, dy, speed; //координаты игрока х и у, высота ширина, ускорение (по х и по у), сама скорость
	int dir; //направление (direction) движения игрока
	String File; //файл с расширением
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	Player(String F, float X, float Y, float W, float H) { //Конструктор с параметрами(формальными) для класса Player. При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту
		dx = 0; dy = 0; speed = 0; dir = 0;
		File = F;//имя файла+расширение
		w = W; h = H;//высота и ширина
		image.loadFromFile("images/" + File);//запихиваем в image наше изображение вместо File мы передадим то, что пропишем при создании объекта.
		image.createMaskFromColor(Color(41, 33, 59));
		texture.loadFromImage(image);//закидываем наше изображение в текстуру
		sprite.setTexture(texture);//заливаем спрайт текстурой
		x = X; y = Y;//координата появления спрайта
		sprite.setTextureRect(IntRect(0, 0, w, h)); //Задаем спрайту один прямоугольник для вывода одного льва, а не кучи львов сразу. IntRect - приведение типов
	}
	void update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
	{
		switch (dir)//реализуем поведение в зависимости от направления. (каждая цифра соответствует направлению)
		{
		case 0: dx = speed; dy = 0; break;//по иксу задаем положительную скорость, по игреку зануляем. получаем, что персонаж идет только вправо
		case 1: dx = -speed; dy = 0; break;//по иксу задаем отрицательную скорость, по игреку зануляем. получается, что персонаж идет только влево
		case 2: dx = 0; dy = speed; break;//по иксу задаем нулевое значение, по игреку положительное. получается, что персонаж идет только вниз
		case 3: dx = 0; dy = -speed; break;//по иксу задаем нулевое значение, по игреку отрицательное. получается, что персонаж идет только вверх
		}

		x += dx * time;//наше ускорение на время получаем смещение координат и как следствие движение
		y += dy * time;//аналогично по игреку

		speed = 0;//зануляем скорость, чтобы персонаж остановился.
		sprite.setPosition(x, y); //выводим спрайт в позицию x y , посередине.
	}
};

int main()
{
	RenderWindow window(VideoMode(1920, 1080), "game");
	window.setFramerateLimit(60); // количество кадров в секунду (60)
    //персонажи
	Player p("pers.png", 4, 775, 101, 774); //создаем объект p класса player,задаем "hero.png" как имя файла+расширение, далее координата Х,У, ширина, высота.
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

		///////////////////////////////////////////Управление персонажем с анимацией////////////////////////////////////////////////////////////////////////
		if ((Keyboard::isKeyPressed(Keyboard::Left) || (Keyboard::isKeyPressed(Keyboard::A)))) {
			p.dir = 1; p.speed = 0.2;//dir =1 - направление вверх, speed =0.1 - скорость движения. 
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 559, 103, 103)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Right) || (Keyboard::isKeyPressed(Keyboard::D)))) {
			p.dir = 0; p.speed = 0.2;//направление вправ
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 781, 103, 103)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)
		}

		if ((Keyboard::isKeyPressed(Keyboard::Up) || (Keyboard::isKeyPressed(Keyboard::W)))) {
			p.dir = 3; p.speed = 0.2;//направление вниз
			CurrentFrame += 0.010 * time;
			if (CurrentFrame > 9) CurrentFrame -= 9;
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 662, 103, 103)); //через объект p класса player меняем спрайт, делая анимацию (используя оператор точку)

		}

		if ((Keyboard::isKeyPressed(Keyboard::Down) || (Keyboard::isKeyPressed(Keyboard::S)))) { //если нажата клавиша стрелка влево или англ буква А
			p.dir = 2; p.speed = 0.2;//направление вверх
			CurrentFrame += 0.010 * time; //служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости.
			if (CurrentFrame > 9) CurrentFrame -= 9; //проходимся по кадрам с первого по третий включительно. если пришли к третьему кадру - откидываемся назад.
			p.sprite.setTextureRect(IntRect(103 * int(CurrentFrame), 450, 103, 103)); //проходимся по координатам Х. 

		}
		
		p.update(time);//оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться
		

		window.clear();
		window.draw(p.sprite);//рисуем спрайт объекта p класса player
		window.display();
	}

	return 0;
}