#include <iostream>
#include "Window.hpp"

int main() {

	Window port;

	port.generate(800, 800);

	sf::RectangleShape rec(sf::Vector2f(200,200));
	rec.setFillColor(sf::Color::Red);
	rec.setOutlineThickness(2.0f);
	rec.setPosition(sf::Vector2f(50,50));

	while (port.IsWindowActive())
	{
		port.process();

		port.cleanWindow();
		port.draw(rec);
		port.displayWindow();
	}
	return 0;

}