#include<SFML/Graphics.hpp>
#include<iostream>

enum class Directive
{
	Left,
	Right,
	Up,
	Down
};

void moving(sf::Vector2f& Location, Directive directive)
{
	switch (directive)
	{
	case Directive::Left:
		Location.x -= 5;
		break;
	case Directive::Right:
		Location.x += 5;
		break;
	case Directive::Up:
		Location.y -= 5;
		break;
	case Directive::Down:
		Location.y += 5;
		break;
	default:
		break;
	}

}

int main()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Hello!");
	sf::CircleShape circle(75,360);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(100,100));

	sf::Vector2f Locating(100,100);
	Directive FigureDirect = Directive::Right;

	float windowTime = 1 / 60.0f;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
			
			}
		
			if (event.type == sf::Event::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					std::cout << "Realased Left!" << std::endl;
				}

				if (event.key.code == sf::Keyboard::Right)
				{
					std::cout << "Realased Right!" << std::endl;
				}

				if (event.key.code == sf::Keyboard::Up)
				{
					std::cout << "Realased Up!" << std::endl;
				}

				if (event.key.code == sf::Keyboard::Down)
				{
					std::cout << "Realased Down!" << std::endl;
				}
			}
		}
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			std::cout << "hoho" << std::endl;
			FigureDirect = Directive::Left;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			FigureDirect = Directive::Right;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			FigureDirect = Directive::Up;	
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			FigureDirect = Directive::Down;
		}

		float timeSpend = clock.getElapsedTime().asSeconds();

		if (timeSpend >= windowTime)
		{
			window.clear();
			moving(Locating, FigureDirect);

			circle.setPosition(Locating);
			window.draw(circle);
			window.display();

			int fps = 1 / timeSpend;

			window.setTitle(std::to_string(fps));
			clock.restart();

		}
		else
		{
			sf::sleep(sf::seconds(windowTime - timeSpend));
		}
	
	}

}