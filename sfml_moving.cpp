#include<SFML/Graphics.hpp>

int main()
{
		
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(600, 600), "Hello!");
	sf::CircleShape circle(150,360);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineThickness(2.0f);
	circle.setOutlineColor(sf::Color::Blue);
	circle.setPosition(sf::Vector2f(100,100));

	sf::Vector2f moving(100,100);

	float windowTime = 1 / 60.0f;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		float timeSpend = clock.getElapsedTime().asSeconds();

		if (timeSpend >= windowTime)
		{
			window.clear();
			circle.setPosition(sf::Vector2f(moving));
			window.draw(circle);
			window.display();

			moving.x += 1.0f;

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