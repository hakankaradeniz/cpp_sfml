#pragma once
#include<SFML/Graphics.hpp>

class Window
{
public:
	void generate(unsigned int width,
		unsigned int height,
		const sf::String& title = "SFML");

	void draw(sf::Drawable& figure);

	void process();

	bool IsWindowActive();

	void cleanWindow();

	void displayWindow();

private:
	sf::RenderWindow sfml_window;
};