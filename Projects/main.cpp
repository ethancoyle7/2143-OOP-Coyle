
#include <SFML/Graphics.hpp>
#include < iostream>
#include<cstdlib>
#include "SFML/Audio.hpp"
#include<sstream>

#include<vector>// using vectors for debris,enemies and ogreshout

using namespace sf;

int main()
{
	

	sf::RenderWindow window(VideoMode(900, 900), "Ethan's swamp");
	window.setFramerateLimit(40);

	// first we are creating sound files to cope with interactions

	sf::Music funsound;
	
	sf::Music startsound;// this will play an entro sound when the game starts
	startsound.openFromFile("startup.ogg");
	startsound.setVolume(500);
	startsound.play();
	//we want background music to play while game is playing

	sf::Music music;// create instance to play music
	music.openFromFile("Happy.ogg");

	music.setVolume(25);//set volume half way so no eardrums busted
	music.play();// play the music

	sf::Music gameover;// create instance to play music
	gameover.openFromFile("youlose.ogg");

	music.setVolume(20);//set volume half way so no eardrums busted
	

	// next we create a background image texture


	sf::Texture background;//set texture for background
	sf::Sprite bImage;//name the background image
	background.loadFromFile("swamppicture.png");// image for the background
	bImage.setScale(1.2f, 1.3f);// set the background image to fill the screen
	bImage.setTexture(background);//texture will hold the background
	bImage.setPosition(1, 1);//set in the center
	sf::Vector2u size;
	size = background.getSize();// grabe the size to set

	//we are creating a firing material to shoot all the donkies
	
	CircleShape OgreShout;
	OgreShout.setFillColor(Color::White);
	sf::Texture OgreShoutTexture;
	OgreShoutTexture.loadFromFile("ogreshout.png");
	OgreShout.setTexture(&OgreShoutTexture);
	OgreShout.setRadius(50.f);


	//debris is created
	//debris has a shape
	//debris has color
	//debris has different positions
	//debris has a size

	RectangleShape Debris;
	Debris.setFillColor(Color::White);//texture fill is white
	sf::Texture debrisTexture;
	debrisTexture.loadFromFile("evildonkey.png");
	//set the texture to this picture
	Debris.setTexture(&debrisTexture);
	
	Debris.setSize(Vector2f(70.f, 70.f));



	//create a circleshaped player with a picture as the texture
	//player has a size
	//player has a color
	//player has a testure
	//player has a position given by the mouse

	CircleShape player;
	player.setFillColor(Color::White);// set white so can see the image
	sf::Texture playerTexture;
	playerTexture.loadFromFile("shrek.png");
	player.setTexture(&playerTexture);
	player.setRadius(50.f);

	player.setPosition(window.getSize().x / 2 - player.getRadius(),
		window.getSize().y - player.getRadius() * 2 - 10.f);
	Vector2f PlayerLocation;//shoot from the center of the player

	int shoutingTime = 0;

	std::vector<CircleShape> ogreshout;
	ogreshout.push_back(CircleShape(OgreShout));

	std::vector<RectangleShape> donkeydebris;
	
	donkeydebris.push_back(RectangleShape(Debris));
	int debrisSpawnTimer = 0;

	sf::Vector2f position(0, 0);

	

	
	

		//text has a size
		//test has a shaper
		//text has location
		//text has a fill color


		Font text;
		text.loadFromFile("textfont.ttf");

		Text gameOverText;
		gameOverText.setFont(text);
		gameOverText.setCharacterSize(100);
		gameOverText.setFillColor(Color::Green);
		//gameOverText.setColor(Color::Green);
		gameOverText.setPosition(30.f, 75.0f);
		gameOverText.setString("GAME OVER!!!!\n\n MAX POINTS \n \nREACHED!!!!!");
		

		int score = 0;
		std::stringstream scoredisplay;
		//text for the score
		scoredisplay << score;



		Text scoreText;
		
			scoreText.setFont(text);
			scoreText.setCharacterSize(80);
			scoreText.setFillColor(Color::Red);
			scoreText.setPosition(0.0f, 0.0f);
			scoreText.setString("     POINTS : ");
			
			//scoreText.setString(scoredisplay.str());



	while (window.isOpen())
	{
		Event event;//start the event
		while (window.pollEvent(event))// while is open, run the event
		{
			if (event.type == Event::Closed)// while closed event
				window.close();
		}

	//update the player position
		PlayerLocation = Vector2f(player.getPosition().x+player.getRadius(), 
			player.getPosition().y + player.getRadius());

		//player.setPosition(Mouse::getPosition(window).x, player.getPosition().y);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			// if the player hits the left arrow, then move the character over 
			// to the left
			player.move(-4.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			// if the player hits the right arrow, then move the character over 
			// to the right
			player.move(4.0f, 0.0f);
		}
		//ogreshout
		if (shoutingTime < 5)
			shoutingTime++;

		//push the button to fire the ogreshout

		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && shoutingTime >= 5) //Shoot
		{
			if (Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				// if the button is pressed will play sound to say get outta
				//my house
				funsound.openFromFile("getout.ogg");
				funsound.setVolume(100);
				funsound.play();
			}
			
			OgreShout.setPosition(PlayerLocation);

			ogreshout.push_back(CircleShape(OgreShout));
			
			shoutingTime = 0;//no delay in the shout
		}

		for (size_t i = 0; i < ogreshout.size(); i++)
		{
			ogreshout[i].move(0.f, -10.f);

			if(ogreshout[i].getPosition().y <= 0)
				ogreshout.erase(ogreshout.begin() + i);
		}

		//donkeydebris
		if(debrisSpawnTimer < 25)
			debrisSpawnTimer++;

		if (debrisSpawnTimer >= 10)
		{
			Debris.setPosition((rand() % int(window.getSize().x 
				- Debris.getSize().x)), 0.f);
			donkeydebris.push_back(RectangleShape(Debris));

			debrisSpawnTimer = 0;
		}

		for (size_t i = 0; i < donkeydebris.size(); i++)
		{
			donkeydebris[i].move(0.f, 5.f);

			if (donkeydebris[i].getPosition().y > window.getSize().y)
			{
				donkeydebris.erase(donkeydebris.begin() + i);
			}
		}

		//this nexted if statement will demonstrate the collision

		if (!donkeydebris.empty() && !ogreshout.empty())
		{
			for (size_t i = 0; i < ogreshout.size(); i++)
			{
				for (size_t j = 0; j < donkeydebris.size(); j++)
				{
					if (ogreshout[i].getGlobalBounds().intersects(donkeydebris[j].
						getGlobalBounds()))
					{
						score += 2;//get one point per donkey eleminated
						
						//window.draw(scoreText);
						ogreshout.erase(ogreshout.begin() + i);
						donkeydebris.erase(donkeydebris.begin() + j);
						break;
					}
				}
			}
		}
	

		
		//music.play();// play background music
		window.draw(bImage);

		

		window.draw(scoreText);
		
		
		//window.clear();//clear the window
		window.draw(player);//draw the player
		
		for (size_t i = 0; i < donkeydebris.size(); i++)
		{
			window.draw(donkeydebris[i]);//draw the donkey debris
		}

		for (size_t i = 0; i < ogreshout.size(); i++)
		{
			window.draw(ogreshout[i]);// firing the ogre shout
		}

		if (score == 100)
		{
			gameover.play();
		}


		if (score >= 100)// set the score limit to  100
		{
			window.draw(gameOverText);
			// play the music
			
		}
		if (event.key.code == sf::Keyboard::Escape)
		{
			window.close();//if escape key pressed close the game
		}
		window.display();
		window.clear();
	}

	return 0;
}
