
/****************************************************************************
*
*    Author:    Ethan Coyle 
*    Project:   Program 01 - Game
*    Course:    CMPS 2143
*    Semester:  Spring 2021
*    Description:
*
*  In this program i have created a program that runs a game using some
*     of the conepts discused in Object Oriented Programming     
*
*    How to play:
*
*		    - spacebar to fire
*		 	- left arrow button =>  To go left.
*			- right arrow button =>  To go right
*		 	- Up arrow button =>  To go UP.
*		 	- down arrow =>  To go Down
*           - esc to exit the game
*
*    Files:
*
*         	    1 - main.cpp           this is the main program
*
*		   2 - shrek.png	      this is the picture texture for player
*										//SHREK WASOWSKI
*		   3 - evildonkey.png	  this is the texture for debris // donkeykongs
*
*		   4 - ogreshout.png		displays texture for firing from player
*										// get outta my swamp
*		   5 - swamppicture.png   this is the background texture// shreks swamp
*								      
*		   6 - youlose.ogg;      this plays a clip whenever gameover max points
*									are reached willy wonka u lose good day
*
*		   7 - textfont.ttf      this is the font for the score and gameover
*									display
*
*		   8- startup.ogg	     this plays intro music when starting up
*										//whatre you doing in my swamp
*		   9 - Happy.ogg         this plays the background music// gandalf sax
*                 
*                  10- getout.ogg       plays firing sout get outta my house
****************************************************************************/
#include <SFML/Graphics.hpp>
#include < iostream>
#include<cstdlib>
#include "SFML/Audio.hpp"
#include<sstream>

#include<vector>// using vectors for debris,enemies and ogreshout

using namespace sf;

int playerScore{ 0 };// universal global variable to hold the current score

int main()
{
	

	sf::RenderWindow window(VideoMode(900, 900), "Ethan's swamp");
	window.setFramerateLimit(40);

	// first we are creating sound files to cope with interactions

	sf::Music funsound;
	
	sf::Music startsound;// this will play an entro sound when the game starts
	startsound.openFromFile("startup.ogg");
	startsound.setVolume(500);// want this to be loud 

	startsound.play();// start the play up song with the background music

	//we want background music to play while game is playing

	sf::Music music;// create instance to play music
	music.openFromFile("Happy.ogg");
	music.setVolume(25);//set volume half way so no eardrums busted
	music.play();// play the music

	sf::Music gameover;// create instance to play music
	gameover.openFromFile("youlose.ogg");
	music.setVolume(20);//set volume half way so no eardrums busted
	// we will play this inside of the event loop

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

	RectangleShape Debris;// debris objects
	Debris.setFillColor(Color::White);//texture fill is white
	sf::Texture debrisTexture;
	debrisTexture.loadFromFile("evildonkey.png");
	//set the texture to this picture
	Debris.setTexture(&debrisTexture);// reference to texture
	
	Debris.setSize(Vector2f(70.f, 70.f));// size of the debris



	//create a circleshaped player with a picture as the texture
	//player has a size
	//player has a color
	//player has a testure
	//player has a position given by the mouse

	CircleShape player; // creation of player
	player.setFillColor(Color::White);// set white so can see the image
	sf::Texture playerTexture;// we need a texture for the player
	playerTexture.loadFromFile("shrek.png");// pull image from the file location
	player.setTexture(&playerTexture);// set the texture box to that of the 
									  // file image
	player.setRadius(50.f);// control the radius of the circle for size


	//determine the player location to debris

	player.setPosition(window.getSize().x / 2 - player.getRadius(),
		window.getSize().y - player.getRadius() * 2 - 10.f);
	Vector2f PlayerLocation;//shoot from the center of the player

	int shoutingTime = 0;
	
	
	//instances of ogre shout
	std::vector<CircleShape> ogreshout;
	ogreshout.push_back(CircleShape(OgreShout));

	//instances of donkies
	std::vector<RectangleShape> donkeydebris;// donkey debris texture rectangles
	//creating more donkey debris
	donkeydebris.push_back(RectangleShape(Debris));
	int debrisSpawnTimer = 0;

	sf::Vector2f position(0, 0);

		//text has a size
		//test has a shaper
		//text has location
		//text has a fill color

		
                 // words for game over sequence to display to the screen
		Font text;
		text.loadFromFile("textfont.ttf");

		Text gameOverText;// create instance of text message
		gameOverText.setFont(text);
		gameOverText.setCharacterSize(100);
		gameOverText.setFillColor(Color::Green);
		gameOverText.setPosition(30.f, 75.0f);
		gameOverText.setString("GAME OVER!!!!\n\n MAX POINTS \n \nREACHED!!!!!");
		

		
		
                 // initialization for scoring board and text font 
		//creating a score for the game
		//has a size
		//has a location
		// has a color: white
		Text playerTextScore;
		sf::Font words;
		words.loadFromFile("textfont.ttf");
		playerTextScore.setFont(words);
		playerTextScore.setCharacterSize(72);
		//playerTextScore.setColor(Color::Red);
		playerTextScore.setPosition(sf::Vector2f(125, 0));
		playerTextScore.setString("0");// display the score
		
	

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
			player.move(-6.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			// if the player hits the right arrow, then move the character over 
			// to the right
			player.move(6.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			// iff the player hits the up move up 6 frams
			player.move(0.0f, -6.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			// if the player hits the down  arrow button, move down 6 frames
			player.move(0.0f, 6.0f);
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
		// debris spawner
		if (debrisSpawnTimer >= 10)
		{
			Debris.setPosition((rand() % int(window.getSize().x 
				- Debris.getSize().x)), 0.f);
			donkeydebris.push_back(RectangleShape(Debris));

			debrisSpawnTimer = 0;
		}

		for (size_t i = 0; i < donkeydebris.size(); i++)// start the donkey debris
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
						++playerScore;//increment the score
						std::string playerScoreText = std::to_string(playerScore);
						playerTextScore.setString(playerScoreText);
						if (playerScore == 50)// if the score is 50
						{
							//display the scoreboard
							//update the game over sequence
							gameover.play();
							playerTextScore.setCharacterSize(20);
							playerTextScore.setPosition(sf::Vector2f(0, 0));
							playerTextScore.setString("YOU WIN!!!!");
							window.draw(gameOverText);



						}
					
						ogreshout.erase(ogreshout.begin() + i);
						donkeydebris.erase(donkeydebris.begin() + j);
						break;
					}
				}
			}
		}	
		window.draw(bImage);//display the background image
		window.draw(player);//draw the player
		window.draw(playerTextScore);// display the scoreboard
		
		for (size_t i = 0; i < donkeydebris.size(); i++)
		{
			window.draw(donkeydebris[i]);//draw the donkey debris
		}

		for (size_t i = 0; i < ogreshout.size(); i++)
		{
			window.draw(ogreshout[i]);// firing the ogre shout
		}
		if (playerScore >= 50)// if it is past the max limit
		{
			window.draw(gameOverText);// display the game over words
		}

		
		if (event.key.code == sf::Keyboard::Escape)
		{
			window.close();//if escape key pressed close the game
		}
		window.display();
		window.clear();//clear the window
	}

	return 0;//cancel out of program
}
  
