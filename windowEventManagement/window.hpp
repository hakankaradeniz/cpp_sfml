#pragma once
#include<SFML/Graphics.hpp>
#include"functionTypes.hpp"

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

	void addKeyPressFunc(keyboardFunction newFunction);

	void addKeyReleaseFunc(keyboardFunction newFunction);

	void addMouseMoveFunc(mouseMoveFunction newFunction);


private:
	keyboardFunctionList	functionsOfKeyPress; 
	keyboardFunctionList	functionsOfKeyRelease;
	mouseMoveFunctionList	functionsOfMouse;
	sf::RenderWindow		sfml_window; 
};