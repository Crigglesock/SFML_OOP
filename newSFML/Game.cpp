#include "Game.h"

Game::Game()
{
	m_mushroomTexture.loadFromFile("Mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(4, 4);
}

Game::~Game()
{

}

void Game::HandleInput()
{

}

void Game::Update()
{
	m_window.Update(); //Update Window events
	MoveMushroom();
}

void Game::Render()
{
	m_window.BeginDraw(); // clear the window
	m_window.Draw(m_mushroom); //Draw mushroom
	m_window.EndDraw(); // display
}

Window * Game::GetWindow()
{
	return nullptr;
}

void Game::MoveMushroom()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroom.GetSize();

	if ((!mushroom.getPosition().x > l_windSize.x - l_textSize && m_increment.x > 0) || (mushroom.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}

	if ((!mushroom.getPosition().y > l_windSize.y - l_textSize && m_increment.y > 0) || (mushroom.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}

	m_mushroom.setPosition(
		m_mushroom.getPosition().x + m_increment.x
		m_mushroom.getPosition().y + m_increment.y
	);
}
