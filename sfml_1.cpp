#include<SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "Hello!");
	sf::CircleShape daire(150);
	daire.setFillColor(sf::Color::Red);
	daire.setOutlineThickness(2.0f);
	daire.setOutlineColor(sf::Color::Blue);
	daire.setPosition(sf::Vector2f(100,100));
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(daire);
		window.display();

	}

}