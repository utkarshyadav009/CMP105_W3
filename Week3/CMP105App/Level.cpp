#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(100, 100);
	rect.setFillColor(sf::Color::Red);
	circle.setRadius(15);
	circle.setPosition(200, 200);
	circle.setFillColor(sf::Color::Red);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(2.f);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::D))
	{
	circlespeedx = 200.0;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		circlespeedx = -200.0;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		circlespeedy = 200.0;
	}
	if (input->isKeyDown(sf::Keyboard::W))
	{
		circlespeedy = -200.0;
	}
	if (input->isKeyDown(sf::Keyboard::Add))
	{
		speedx += 10.0;
	}
	if (input->isKeyDown(sf::Keyboard::Subtract))
	{
		speedy -= 10.0;
	}
}

// Update game objects
void Level::update(float dt)
{   
	rect.move(speedx * dt, speedy*dt);
	if (rect.getPosition().x + rect.getSize().x >= window->getSize().x || rect.getPosition().x< 0)
	{
		speedx = -speedx;
		
	}
	if (rect.getPosition().y + rect.getSize().y >= window->getSize().y || rect.getPosition().y < 0)

	{

		speedy = -speedy;

	}

	circle.move(circlespeedx * dt, circlespeedy * dt);
	
	if (circle.getPosition().x + circle.getRadius()*2 >= window->getSize().x || circle.getPosition().x < 0)
	{
		circlespeedx = -circlespeedx;
		circle.move(circlespeedx * dt, 0);
	}
	if (circle.getPosition().y + circle.getRadius() * 2 >= window->getSize().y || circle.getPosition().y < 0)
	{
		circlespeedy = -circlespeedy;
		circle.move(0, circlespeedy * dt);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(rect);
	window->draw(circle);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(0, 0, 0));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}