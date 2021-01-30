#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 400), "SFML works! Ethan Coyle");
	//controls the size of the black box encompassing the green circle
	// can type different numbers inside of the parameters window size

	// controls size of green the " . f"
	sf::CircleShape shape(200.f);

	//can change to different color
	shape.setFillColor(sf::Color::Green); 

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))// while it is in event
		{
			if (event.type == sf::Event::Closed)
				window.close();// if the event isnt running then close
		}

		window.clear();
		window.draw(shape);// draws the shape
		window.display();// display the circle
		
	}
