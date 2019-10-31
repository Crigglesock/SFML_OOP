#include"SFML/include/SFML/Graphics.hpp"
#include<iostream>



int main()
{
	//Initialize game objects
	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Mushroom");

	sf::Texture mushroomTexture;
	if (!mushroomTexture.loadFromFile("Deps/Images/Mushroom.png")) 
	{
		std::cout << "File failed to load" << std::endl;
	}

	sf::Sprite mushroom(mushroomTexture);
	sf::Vector2u size = mushroomTexture.getSize();

	mushroom.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.1f, 0.1f);


	mushroom.setColor(sf::Color(255, 255, 255, 150));

	while (window.isOpen())
	{
		//handle keyboard events
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		//update game objects

		//X axis bounce
		if((mushroom.getPosition().x + (size.x/2) > window.getSize().x && increment.x > 0)||(mushroom.getPosition().x - (size.x/2) < 0 && increment.x < 0))
		{
			//reverse direction on the x axis
			increment.x = -increment.x;
		}

		//Y axis bounce
		if ((mushroom.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (mushroom.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{
			//reverse direction on the y axis
			increment.y = -increment.y;
		}

		mushroom.setPosition(mushroom.getPosition() + increment);

		window.clear(sf::Color::Blue);

		//render game objects
		window.draw(mushroom);
		
		window.display();


	}
	return 0;
}