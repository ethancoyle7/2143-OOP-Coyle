
/****************************************************************************
*
*    Author:    Ethan Coyle
*    Project:   Program 01 - Game
*    Course:    CMPS 2143
*    Semester:  Spring 2021
*    What does it do?:
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
* -> main.cpp           this is the main program
*
* -> shrek.png	      this is the picture texture for player
*					//SHREK WASOWSKI
* -> evildonkey.png	  this is the texture for debris // donkeykongs
*
* -> ogreshout.png		displays texture for firing from player
*										// get outta my swamp
* -> swamppicture.png   this is the background texture// shreks swamp
*
* -> youlose.ogg;      this plays a clip whenever gameover max points
*						are reached willy wonka u lose good day
*
*-> textfont.ttf      this is the font for the score and gameover
*									display
*
* -> startup.ogg	     this plays intro music when starting up
*										//whatre you doing in my swamp
*
* -> Happy.ogg         this plays the background music// gandalf sax
*
* -> getout.ogg        this sound file hagrid shouting getout when fire
*********************************************************************/

#include <SFML/Graphics.hpp>// to display graphics
#include < iostream>// in and outfile stream
#include<cstdlib>
#include "SFML/Audio.hpp"// for music 
#include<sstream>// for string streaming

using namespace std;// using starndar namespace
using namespace sf;// sfml documentation

int PlayerScore = { 0 }; // start the PlayerScore at 0 global variable

/*
*    Class Name: ogreshout
*
*What does it do?:
*
* -> this class creates ogreshout with a sprite using picture from 
* -> our file folder
*
* Public Methods:
*
* -> ogreshout()  Default Constructor
* -> ~ogreshout() Destructor
*
* Private Methods:
*
*_> have no private methods
*
*/
class OgreShout
{
public:
	Sprite shape;  // create sprite shape to hold ogre shout                              

	OgreShout(Texture *texture, Vector2f pos);// ogreshout texture

	~OgreShout();// destructor for ogreshout
};

/**
 * Public :  ogreshout
 *
 * What does it do?:
 *
 *-> Has Default Constructor to create ogreshout
 *
 * Parameteres:
 *
 * ->this class contains pointer to texture for ogreshouts
 * ->as well as a vector to poisiont those shouts
 *          
 *
 * What does it Return?:
 *
 * -> returns a nul value        
 */
OgreShout::OgreShout(Texture *texture, Vector2f pos)
{
	this->shape.setTexture(*texture);// initialize shape            

	this->shape.setScale(0.7f, 0.7f);// set the size 

	this->shape.setPosition(pos); // set the position pointer of 
	                             //this to poistion
}

/**
 * Public :  ~ogreshout
 *
 * What does it do?:
 *   -has a  Destructor
 *
 * Parameteres:
 * -> there are no parameter
 *
 * What does it Return?:
 * 
 * -> Returns a nul value
 */
OgreShout::~OgreShout()// desturctor
{
	//cout << "ogreshout destructor" << endl;
};

class Player // class named player
{

public:
	Sprite shape;  // sprite to hold shape of player and shout
	Texture *texture;// texture reference

	
	vector<OgreShout> ogreshout;// vector of ogreshouts at
									 // our disposal
	Player(Texture *texture);// set the texture from picture
	
	~Player();//destructor of player
};

/**
 * Public :  Player
 *
 * What does it do?:
 * -> has Default Constructor to create instance of player
 *
 * Parameteres:
 * _-> has Texture pointer for file to player picture
 *
 * What does it Return?:
 * 
 *-> returns NULL value
 */
Player::Player(Texture *texture)// dot operator for player
{
	this->texture = texture;// initialize texture for player                     
	this->shape.setTexture(*texture);// reference texture of player
	this->shape.setScale(0.1f, 0.1f);;   //set the size of player        
}

Player::~Player()
{
	//cout << "I am shrek get outta me swamp" << endl;
};

class DonkeyDebris
{
public:
	Sprite shape; 
	DonkeyDebris(Texture *texture, Vector2u windowSize);

	~DonkeyDebris();
};

// dot operator for donkey class
DonkeyDebris::DonkeyDebris(Texture *texture, Vector2u windowSize)
{
	

	this->shape.setTexture(*texture);// setting the texture

	this->shape.setScale(0.05f, 0.05f); //set scale of the debris


	// Setting the position of our DonkeyDebris in window at random
	// positions indsied the main window
	this->shape.setPosition(windowSize.x - this->
		shape.getGlobalBounds().width,rand() % (int)(windowSize.y
			- this->shape.getGlobalBounds().height));
}

// dot operator for donkey debris destructor cout<<
DonkeyDebris::~DonkeyDebris()
{
	
}; // default constructor


// main function now
int main()
{
	// set the window frame sizes 
	RenderWindow window(VideoMode(900, 900), "Ethan Coyle's swamp ", 
		Style::Default);

	window.setFramerateLimit(40);


	// setting still background
	sf::Texture background;//set texture for background
	sf::Sprite bImage;//name the background image
	background.loadFromFile("swamppicture.png");// image for the background
	bImage.setScale(1.2f, 1.3f);// set the background image to fill the screen
	bImage.setTexture(background);//texture will hold the background
	bImage.setPosition(1, 1);//set in the center
	sf::Vector2u size;
	size = background.getSize();// grabe the size to set
	

	// creting instance of sound to start a startup sound
	sf::Music startsound;// this will play an entro sound when the game starts
	startsound.openFromFile("startup.ogg"); // whatre you doing in me swamp
	startsound.setVolume(500);// want this to be loud 
	startsound.play();// start the play up song with the background music


	// instance created to start background music to play through the game
	// gandalf sax
	sf::Music music;// create instance to play music
	music.openFromFile("Happy.ogg");
	music.setVolume(25);//set volume half way so no eardrums busted
	music.play();// play the music


	// another instance of sound playing to play when the game is over
	// willy wonka you lose
	sf::Music gameover;// create instance to play music
	gameover.openFromFile("youlose.ogg");
	music.setVolume(20);//set volume half way so no eardrums busted


	// firing sounds from shrek wazowski
	sf::Music funsound;
	
	
	
	
	// load text font from file
	Font text;
	text.loadFromFile("textfont.ttf");

	Text gameOverText;// create instance of text message
	gameOverText.setFont(text);
	gameOverText.setCharacterSize(100);
	gameOverText.setFillColor(Color::Green);
	gameOverText.setPosition(30.f, 75.0f);
	gameOverText.setString("GAME OVER!!!!\n\n MAX POINTS \n \nREACHED!!!!!");
	// Initialize and Display the ScoreBoard text.
	

	// create a PlayerScore counter to calculate the PlayerScore
	sf::Font words;
	words.loadFromFile("textfont.ttf");
	Text playerTextScore;
	playerTextScore.setFont(words);// set the PlayerScore font to words
	playerTextScore.setCharacterSize(72);// set the size of the PlayerScore
	//playerTextScore.setColor(Color::Red);
	playerTextScore.setPosition(sf::Vector2f(125, 0));// set the position
	//top left x 125, y 0
	playerTextScore.setString("0");// display the PlayerScore
	

	// fiel for player texture
	Texture playertexture;
	playertexture.loadFromFile("shrek.png");// load from file

	// picture file for derbis
	Texture Flyingdebris;
	Flyingdebris.loadFromFile("evildonkey.png");// load texture from file

	// texture picture for ogreshout
	Texture shouting;
	shouting.loadFromFile("ogreshout.png");// load shout from file

	Player Player(&playertexture); // initialize the player with texture
	float ogreshout = 20.f;		               

	float Donkey_Debris = 0.0f;	 // float variable to hold donkey debris
	vector<DonkeyDebris> donkeydebris; // DonkeyDebris initialize.

	
	//create while loop to star the event
	while (window.isOpen())  // while window is open run event command                                
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)// if event closed, close         
				window.close();
		}
		// using control commansds to move player

			//if up is pressed move up
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			Player.shape.move(0.f, -6.f);
		}
		//if left pressed, move left
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			Player.shape.move(-6.f, 0.f);
		}
		// if down is pressed , move down
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			Player.shape.move(0.f, 6.f);
		}

		// if right is pressed , move right
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			Player.shape.move(6.f, 0.f);
		}

		// we need to create bounds for player

		if (Player.shape.getPosition().x <= 0)
		{// Left
			Player.shape.setPosition(0.f, Player.shape.getPosition().y);
		}

		if (Player.shape.getPosition().x >= window.getSize().x -
			Player.shape.getGlobalBounds().width)
		{
			Player.shape.setPosition(window.getSize().x - Player.shape.
				getGlobalBounds().width, Player.shape.getPosition().y);
		}
		if (Player.shape.getPosition().y <= 0)
		{
			Player.shape.setPosition(Player.shape.getPosition().x, 0.f);
		}
		if (Player.shape.getPosition().y >= window.getSize().y - Player.
			shape.getGlobalBounds().height)
		{// Bottom
			Player.shape.setPosition(Player.shape.getPosition().x,
				window.getSize().y - Player.shape.getGlobalBounds().height);
		}
		// Update Controls
		if (ogreshout < 5)
			ogreshout ++;
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) &&
			ogreshout >= 5)
		{ // if the spacebar is pressed
			if (Keyboard::isKeyPressed(sf::Keyboard::Space))// ogre shout 
				//increases the speed of travelling
			{
				// if the button is pressed will play sound to say get outta
				//my house
				
				funsound.openFromFile("getout.ogg");
				funsound.setVolume(100);
				funsound.play();
			}

			// Calling the vector  ogreshouts to shoot
			Player.ogreshout.push_back(OgreShout(&shouting, Player.
				shape.getPosition()));

			ogreshout = 0;// reset the shout meter
		}

		// shouting at debris
		for (unsigned int i = 0; i < Player.ogreshout.size(); i++)
		{
			Player.ogreshout[i].shape.move(10.f, 0.f);
			if (Player.ogreshout[i].shape.getPosition().x >
				window.getSize().x)
			{
				// Whenever the shout goes out of bounds, delete
				Player.ogreshout.erase(Player.ogreshout.begin() + i);
				break;
			}
			// loops for collision
			for (unsigned int j = 0; j < donkeydebris.size(); j++)
			{	// This if statement handle the the collision
				// with the DonkeyDebris.
				if (Player.ogreshout[i].shape.getGlobalBounds().
					intersects(donkeydebris[j].shape.getGlobalBounds()))
				{
					++PlayerScore;// increment the PlayerScore by one
					string playerScoreText = std::to_string
					(PlayerScore);
					playerTextScore.setString(playerScoreText);
					if (PlayerScore == 50)
					{

						//update the gameover
						gameover.play();
						playerTextScore.setCharacterSize(20);
						playerTextScore.setPosition(sf::Vector2f(0, 0));
						playerTextScore.setString("YOU WIN!!!!");
						window.draw(gameOverText);

					}
					donkeydebris.erase(donkeydebris.begin() + j);
					// get rid of the debris	   
					//get rid of the ogrshout and get read for next 
					Player.ogreshout.erase(Player.ogreshout.begin() + i);
					break;
				}

			}


			if (Donkey_Debris < 25)  // when less than 25, create debris                                         
				Donkey_Debris++;

			if (Donkey_Debris >= 25)// spawn donkey debris
			{
				donkeydebris.push_back(DonkeyDebris(&Flyingdebris,
					window.getSize()));

				Donkey_Debris = 0; // reset so can start more invasive 
								   //donkies
			}

			for (unsigned int i = 0; i < donkeydebris.size(); i++)
			{
				donkeydebris[i].shape.move(-6.0f, 0.0f);
				// Using this to handle the DonkeyDebris movements.

				if (donkeydebris[i].shape.getPosition().x <= 0 -
					donkeydebris[i].shape.getGlobalBounds().width)
				{
					donkeydebris.erase(donkeydebris.begin() + i);
					// If DonkeyDebris is out of the window delete that 
					//DonkeyDebris.
					break;
				}

				if (donkeydebris[i].shape.getGlobalBounds().intersects(
					Player.shape.getGlobalBounds()))
				{
					//if we get hit by donkey debris
					donkeydebris.erase(donkeydebris.begin() + i);
					--PlayerScore;// decrement the PlayerScore by one

					break;
				}
			}
		}

		window.clear(); //clear the window for drawing to screen
		window.draw(bImage);// draw the background
		window.draw(Player.shape); //draw the player to the screen

		for (unsigned int i = 0; i < Player.ogreshout.size(); i++)// create
														//ogre shout		   
		{
			window.draw(Player.ogreshout[i].shape);
		}

		// Using this for loop to Display the DonkeyDebris
		for (unsigned int i = 0; i < donkeydebris.size(); i++)
		{
			window.draw(donkeydebris[i].shape);// create the debris
		}

		//window.draw(PlayerScoreText); // display the PlayerScore
		window.draw(playerTextScore);// draw the scoreboard

		if (PlayerScore >= 50)// set the limit of the score
		{
			window.draw(gameOverText);// whenever max points reached
										//display gameover
		}

		window.display(); // display event to the window

		if (event.key.code == sf::Keyboard::Escape)
		{
			window.close();//if escape key pressed close the game
		}
	}

return 0;// close out of the program
}
