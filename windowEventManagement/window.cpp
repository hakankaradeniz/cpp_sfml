#include "Window.hpp"


void Window::generate(unsigned int width, unsigned int height, const sf::String& title)
{
	sfml_window.create(sf::VideoMode(width,height),title);
}

void Window::draw(sf::Drawable& figure)
{
	sfml_window.draw(figure);
}


void Window::process()
{
	sf::Event event;

	while (sfml_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			sfml_window.close();
		if (event.type == sf::Event::KeyPressed)
		{
			for (auto next:functionsOfKeyPress)
			{
				next(event.key.code);
			}
		}

		if (event.type == sf::Event::KeyReleased)
		{
			for (auto next : functionsOfKeyRelease)
			{
				next(event.key.code);
			}
		}

		if (event.type == sf::Event::MouseMoved)
		{
			for (auto next : functionsOfMouse)
			{
				next(event.mouseMove);
			}
		}
	}
}

bool Window::IsWindowActive()
{
	return sfml_window.isOpen();
}

void Window::cleanWindow()
{
	sfml_window.clear();
}

void Window::displayWindow()
{
	sfml_window.display();
}

void Window::addKeyPressFunc(keyboardFunction newFunction)
{
	functionsOfKeyPress.push_back(newFunction);
}

void Window::addKeyReleaseFunc(keyboardFunction newFunction)
{
	functionsOfKeyRelease.push_back(newFunction);
}

void Window::addMouseMoveFunc(mouseMoveFunction newFunction)
{
	functionsOfMouse.push_back(newFunction);
}
