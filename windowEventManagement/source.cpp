#include <iostream>
#include <string>
#include <functional>
#include "Window.hpp"
using namespace std;

void write(sf::Keyboard::Key button)
{
	cout << "HELLO!" << endl;
}

void write1(sf::Keyboard::Key button)
{
	cout << "hohoho!" << endl;
}

void moving(sf::Event::MouseMoveEvent mouseEvent)
{
	cout << "x: " << mouseEvent.x << " y: " << mouseEvent.y << endl;
}

int main() {

	

	Window port;
	port.addKeyPressFunc(write);
	port.addKeyReleaseFunc(write1);
	port.addMouseMoveFunc(moving);

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