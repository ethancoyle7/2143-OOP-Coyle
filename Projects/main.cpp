#include <SFML/Graphics.hpp>
#include < iostream>
using namespace std;

int main()
{
	
	sf::RectangleShape Debris(sf::Vector2f(150.0f, 150.0f));

	sf::Texture DebrisTexture;

	//create the player box to load picture for the player

	DebrisTexture.loadFromFile("evildonkey.png");
	Debris.setTexture(&DebrisTexture);
	Debris.setPosition(500,275);
	

	//first set the screen dimensions 800 by 600
	sf::Vector2i screendimensions(700, 700);
	sf::RenderWindow window;
	window.create(sf::VideoMode(screendimensions.x, screendimensions.y), 
		"Ethan Coyle UML game");
	
	
	//create moving background

	sf::Texture background;
	sf::Sprite bImage;
	if (!background.loadFromFile("background.png"))
	{
		std::cout << "Error loading texture..." << std::endl;
	}


	//cout << " catch the evil donkies" << endl;
	bImage.setTexture(background);
	bImage.setScale(1.0f, (float)screendimensions.y / background.getSize().y);

	

	//create the player box to load picture for the player

	

	sf::RectangleShape player(sf::Vector2f(150.0f, 150.0f));
	
	sf::Texture playerTexture;

	//create the player box to load picture for the player

	playerTexture.loadFromFile("shrek.png");
	player.setTexture(&playerTexture);
	player.setPosition(0, 250);//set the player in the middle of the screen
	

	//in order to traverse over the image to capture the debris
	//we need to create a view feild to go around the background
	//sf::View view;


	//declaration to scroll past edge of screen
	//view.reset(sf::FloatRect(0, 0, screendimensions.x, screendimensions.y));
	//view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));

	sf::Vector2f position(0, 0);
	

	bImage.setTexture(background);
	bImage.setPosition(1, 1);

	sf::Vector2u size;

	size = background.getSize();

	//std::cout << size.x << std::endl;

	float x = 1.0;
	float y = 1.0;

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
			player.move(-0.1f, 0.0f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			// if the player hits the right arrow, then move the character over 
			// to the right
			player.move(0.1f, 0.0f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			// if the player hits the up arrow, then move the character over 
			// up
			player.move(0.0f, -0.1f);
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			// if the player hits the down arrow, then move the character over 
			// down
			player.move(0.0f, 0.1f);
		}

		/*position.x = player.getPosition().x + 10 - (screendimensions.x / 2);
		position.y = player.getPosition().y + 10 - (screendimensions.y / 2);
		
		if (position.y < 0)
			position.y = 0;
		if (position.x < 0)
			position.x = 0;*/

		bImage.setPosition(x, y);

		x -= .0075;

		//std::cout << x << std::endl;

		if (x <= -1440 + 600) {
			x = 1;
		}
		//able to scroll through the whole image after reaching midway point
		//view.reset(sf::FloatRect(position.x, position.y, screendimensions.x, screendimensions.y));
		
		//window.setView(view);// able to move around the image past halfway
		window.draw(bImage);// moving background
		window.draw(Debris);
		window.draw(player);

		window.display();
		window.clear();
	}

	return 0;
}
