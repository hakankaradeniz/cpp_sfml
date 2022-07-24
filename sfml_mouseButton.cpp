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
	sf::CircleShape circle(75, 360);
	sf::RectangleShape rectangle(sf::Vector2f(45,45));

	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setOutlineColor(sf::Color::Cyan);

	circle.setFillColor(sf::Color::Red);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(100, 100));

	sf::Vector2f Locating(100, 100);
	Directive FigureDirect = Directive::Right;

	sf::Vector2f beginning;

	float windowTime = 1 / 60.0f;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved)
			{
			
			}

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					beginning = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
					rectangle.setPosition(beginning);
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
						sf::Vector2f last(event.mouseButton.x, event.mouseButton.y);
				        float width = last.x - beginning.x;
				        float height = last.y - beginning.y;
				        rectangle.setSize(sf::Vector2f(width, height));
				}
			}

		}

		float timeSpend = clock.getElapsedTime().asSeconds();

		if (timeSpend >= windowTime)
		{
			window.clear();
			moving(Locating, FigureDirect);

			circle.setPosition(Locating);
			window.draw(circle);
			window.draw(rectangle);
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