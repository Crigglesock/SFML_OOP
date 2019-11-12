#include "Game.h"

Game::Game() : m_window("Bouncy Mushroom", sf::Vector2u(800,600))
{
	m_mushroomTexture.loadFromFile("Deps/Images/Mushroom.png");
	m_mushroom.setTexture(m_mushroomTexture);
	m_increment = sf::Vector2i(1, 1);
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
	return &m_window;
}



void Game::MoveMushroom()
{
	sf::Vector2u l_windSize = m_window.GetWindowSize();
	sf::Vector2u l_textSize = m_mushroomTexture.getSize();
	m_mushroom.setOrigin(l_textSize.x / 2, l_textSize.y / 2);

	//X axis bounce
		if((m_mushroom.getPosition().x + (l_textSize.x/2) > l_windSize.x && m_increment.x > 0)||(m_mushroom.getPosition().x - (l_textSize.x/2) < 0 && m_increment.x < 0))
		{
			//reverse direction on the x axis
			m_increment.x = -m_increment.x;
		}

		//Y axis bounce
		if ((m_mushroom.getPosition().y + (l_textSize.y / 2) > l_windSize.y && m_increment.y > 0) || (m_mushroom.getPosition().y - (l_textSize.y / 2) < 0 && m_increment.y < 0))
		{
			//reverse direction on the y axis
			m_increment.y = -m_increment.y;
		}

	m_mushroom.setPosition(
		m_mushroom.getPosition().x + m_increment.x,
		m_mushroom.getPosition().y + m_increment.y)
	;
}


