#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	ball1.setTexture(&ballTexture);
	ball1.setSize(sf::Vector2f(50, 50));
	ball1.setPosition(50, 400);
	ball1.setVelocity(100, 0);
	ball2.setTexture(&ballTexture);
	ball2.setSize(sf::Vector2f(50, 50));
	ball2.setPosition(700, 400);
	ball2.setVelocity(-100, 0);

	square1.setSize(sf::Vector2f(50, 50)); 
	square1.setCollisionBox(sf::FloatRect(0, 0, 50, 50)); 
	square1.setPosition(0, 200); 
	square1.setVelocity(150, 0); 
	square1.setFillColor(sf::Color::Blue); 
	square2.setPosition(750, 200); 
	square2.setSize(sf::Vector2f(50, 50)); 
	square2.setCollisionBox(sf::FloatRect(0, 0, 50, 50)); 
	square2.setVelocity(-150, 0); 
	square2.setFillColor(sf::Color::Green);

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
}

// Update game objects
void Level::update(float dt)
{
	ball1.update(dt); 
	ball2.update(dt); 
	if (Collision::checkBoundingCircle(&ball1, &ball2)) 
	{ 
		ball1.collisionResponse(NULL); 
		ball2.collisionResponse(NULL); 
	}

	square1.update(dt); 
	square2.update(dt); 
	if (Collision::checkBoundingBox(&square1, &square2)) 
	{ 
		square1.collisionResponse(NULL); 
		square2.collisionResponse(NULL); 
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball1);
	window->draw(ball2);
	window->draw(square1);
	window->draw(square2);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}