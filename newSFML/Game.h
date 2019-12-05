#ifndef GAME

#include "Window.h"
#include "World.h"
#include "Text.h"

class Game
{
public:
	Game();
	~Game();

	void HandleInput();
	void Update();
	void Render();
	Window* GetWindow();
	sf::Time GetElapsed();
	void RestartClock();

private:
	Window m_window;
	World m_world;
	Snake m_snake;
	Textbox m_textbox;

	float m_elapsed;
	sf::Texture m_mushroomTexture;
	sf::Sprite m_mushroom;
	sf::Vector2i m_increment;
	sf::Clock m_clock;
	

};

#endif GAME