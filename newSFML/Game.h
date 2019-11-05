#ifndef GAME

#include "Window.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();

private:
	void MoveMushroom();
	Window m_window;

	sf::Texture mushroomTexture;
	sf::Sprite mushroom();
	sf::Vector2i increment;

};

#endif GAME