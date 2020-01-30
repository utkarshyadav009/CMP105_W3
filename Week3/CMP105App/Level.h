#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();
	sf::RectangleShape rect;
	sf::CircleShape circle;
	float speedx = 100.0;
	float speedy = 100;
	float circlespeedx;
	float circlespeedy;
	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};