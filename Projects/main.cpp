#include <SFML/Graphics.hpp>
#include < iostream>
using namespace std;

int main()
{
	//first set the screen dimensions 800 by 600
	sf::Vector2i screendimensions(700, 700);
	sf::RenderWindow window;
	window.create(sf::VideoMode(screendimensions.x, screendimensions.y), "Ethan Coyle UML game");
	
	//sf::Texture background;
	//background.loadFromFile("scrolling.png");
	sf::Texture bTexture;
	sf::Sprite bImage;
	if (!bTexture.loadFromFile("background.png"))// load a background image
	{
		cout << " could not load image" << endl;
	}


	//cout << " catch the evil donkies" << endl;
	bImage.setTexture(bTexture);
	bImage.setScale(1.0f, (float)screendimensions.y / bTexture.getSize().y);

	//sf::RectangleShape Debris(sf::Vector2f(100.0f, 100.0f));
	//Debris.setFillColor(sf::Color::White);
	//sf::Texture DebrisTexture;

	////create the player box to load picture for the player

	//DebrisTexture.loadFromFile("evildonkey.png");
	//Debris.setTexture(&DebrisTexture);

	sf::RectangleShape player(sf::Vector2f(200.0f, 200.0f));
	player.setFillColor(sf::Color::White);
	sf::Texture playerTexture;

	//create the player box to load picture for the player

	playerTexture.loadFromFile("shrek.png");
	player.setTexture(&playerTexture);
	

	//in order to traverse over the image to capture the debris
	//we need to create a view feild to go around the background
	sf::View view;
	view.reset(sf::FloatRect(0, 0, screendimensions.x, screendimensions.y));
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f position(0, 0);

	while (window.isOpen())// while the window is open start the event
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// below moniters the players key strokes to see which button they press

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			// if the player hits the left arrow, then move the character over 
			// to the left
			player.move(-1.0f, 0.0f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			// if the player hits the right arrow, then move the character over 
			// to the right
			player.move(1.0f, 0.0f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			// if the player hits the up arrow, then move the character over 
			// up
			player.move(0.0f, -1.0f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			// if the player hits the down arrow, then move the character over 
			// down
			player.move(0.0f, 1.0f);
		}

		position.x = player.getPosition().x + 10 - (screendimensions.x / 2);
		position.y = player.getPosition().y + 10 - (screendimensions.y / 2);
		
		if (position.y < 0)
			position.y = 0;
		if (position.x < 0)
			position.x = 0;

		view.reset(sf::FloatRect(position.x, position.y, screendimensions.x, screendimensions.y));

		window.setView(view);
		window.draw(bImage);
		//window.draw(background);
		//window.draw(Debris);
		window.draw(player);

		window.display();
		window.clear();
	}

	return 0;
}
