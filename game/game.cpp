//================================================
// Jeremy Saylor
// 19 Apr 2019
// Final Programming Assignment
// Pragramming II
//================================================

#include <iostream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf; 
#include "Aliens.h"
#include "Missile.h"
#include "Artillery.h"
#include "GameUI.h"
#include "Martians.h"
#include "GameMgr.h"
#include "Player.h"

void moveShip(Sprite& ship)
{
	const float DISTANCE = 5.0;

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		
		Vector2f pos = ship.getPosition();
		if (pos.x >= 10)
		{
			ship.move(-DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		// right arrow is pressed: move our ship right 5 pixels
		Vector2f pos = ship.getPosition();
		if (pos.x <= 770)
		{
			ship.move(DISTANCE, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		// right arrow is pressed: move our ship right 5 pixels
		Vector2f pos = ship.getPosition();
		if (pos.y >= 450)
		{
			ship.move(0, -DISTANCE);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		// right arrow is pressed: move our ship right 5 pixels
		Vector2f pos = ship.getPosition();
		if (pos.y <= 570)
		{
			ship.move(0, DISTANCE);
		}
	}
}



int main()
{

	//GameUI start;
	//start.gameWindow();


	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	// Limit the framerate to 60 frames per second
	window.setFramerateLimit(60);

	GameUI start;
	GameMgr gameMgr(&start);
	//start.gameWindow();
	//gameMgr.draw(window, start);

	// load textures from file into memory. This doesn't display anything yet.
	// Notice we do this *before* going into animation loop.
	Texture shipTexture;
	if (!shipTexture.loadFromFile("ship.png"))
	{
		cout << "Unable to load ship texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture starsTexture;
	if (!starsTexture.loadFromFile("stars.jpg"))
	{
		cout << "Unable to load stars texture!" << endl;
		exit(EXIT_FAILURE);
	}

	// A sprite is a thing we can draw and manipulate on the screen.
	// We have to give it a "texture" to specify what it looks like
	Texture missileTexture;
	if (!missileTexture.loadFromFile("missile.png"))
	{
		cout << "Unable to load missile texture!" << endl;
		exit(EXIT_FAILURE);
	}
	Texture enemyTexture;
	if (!enemyTexture.loadFromFile("enemy.png"))
	{
		cout << "Unable to load enemy texture!" << endl;
		exit(EXIT_FAILURE);
	}


	Sprite background;
	background.setTexture(starsTexture);
	// The texture file is 640x480, so scale it up a little to cover 800x600 window
	background.setScale(1.5, 1.5);

	// create sprite and texture it
	Sprite ship;
	ship.setTexture(shipTexture);




	/*Sprite missile;
	missile.setTexture(missileTexture);*/
	Artillery missile;




	//Aliens spaceship;
	
	Sprite enemy;

	//spaceship.addSprite(enemyTexture);
	/*Weapons levelOne;
	levelOne.addTexture(missileTexture);*/

	enemy.setTexture(enemyTexture);

	
	//levelOne.getWinSize(window.getSize().x, window.getSize().y);


	// initial position of the ship will be approx middle of screen
	float shipX = window.getSize().x / 2.0f;
	float shipY = window.getSize().y / 1.25f;
	ship.setPosition(shipX, shipY);
	



























	//Artillery sideWinder;









	float enemyX = window.getSize().x / 2.0f;
	//float enemyZ = window.getSize().x / 4.0f;
	float enemyY = window.getSize().y / 8.0f;
	enemy.setPosition(enemyX, enemyY);

	//spaceship.setpos(enemyZ, enemyY);

	bool isMissileInFlight = false;
	bool direction = true;
	bool isHit = false;
	bool isAlienDead = false;

	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		// For now, we just need this so we can click on the window and close it
		Event event;

		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)// && !isMissileInFlight)
				{
					isMissileInFlight = true;
					isHit = true;
					Vector2f pos = ship.getPosition();
					//missile.setPosition(pos);

					//Artilery
					missile.addWeapon();
					missile.setPos(pos);
					//missile.addWeapon();

					//levelOne.setPos(pos.x, pos.y);
					//Player miss;










					//sideWinder.setPos(pos);
					














					//float missileX = ship.x;
					//float missileY = ship.getSize().y / 2.0f;
					//missile.setPosition(shipX, shipY);

					//window.draw(missile);

					// ***Add code to initialize missile position 
				}
			}
		}

		//===========================================================
		// Everything from here to the end of the loop is where you put your
		// code to produce ONE frame of the animation. The next iteration of the loop will
		// render the next frame, and so on. All this happens ~ 60 times/second.
		//===========================================================

		// draw background first, so everything that's drawn later 
		// will appear on top of background
		window.draw(background);

		moveShip(ship);

		// draw the ship on top of background 
		// (the ship from previous frame was erased when we drew background)
		window.draw(ship);
		//window.draw(missile);
		window.draw(enemy);
		//spaceship.getPos;
		Vector2f pos = enemy.getPosition();
		//spaceship.getPos.x;

		if (pos.x == 740)
		{
			direction = false;
		}
		if (pos.x == 10)
		{
			direction = true;
		}
		if (direction)
		{
			enemy.setPosition((pos.x + 1), (pos.y));
			//spaceship.setpos((pos.x + 1), (pos.y));
		}
		if (!direction)
		{
			enemy.setPosition((pos.x - 1), (pos.y));
			//spaceship.setpos((pos.x - 1), (pos.y));
		}




		if (isMissileInFlight)
		{
			// ***code goes here to handle a missile in flight
			//window.draw(missile);
			Vector2f pos = missile.getPos();
			missile.setPosition(pos.x, (pos.y - 1));
			missile.drawMissile(window);

			//window.draw(missile.getSprite);

			if (pos.y <= 0)
			{
				isMissileInFlight = false;
			}
			// don't forget to turn the flag off when the missile goes off screen!
		}










		//FloatRect missileBounds = missile.getGlobalBounds();
		//FloatRect enemyBounds = enemy.getGlobalBounds();







		//bool isGone;
		//isGone = sideWinder.checkHit(enemy.getGlobalBounds());

		//if (missileBounds.intersects(enemyBounds)); //isGone)
		//{
		//	isHit = false;
		//	isAlienDead = true;
		//	cout << "…we hit the enemy…" << endl;
		//}

		//sideWinder.draw(window);




		//levelOne.drawMiss(window);

		//if (pos.x = 10)
		//{
		//	enemy.setPosition((pos.x + 1), (pos.y));
		//}











		if (!isAlienDead)
		{

			window.draw(enemy);
		}




		//if (isMissileInFlight == isHit)
		//{
		//	// ***code goes here to handle a missile in flight
		//	//window.draw(missile);
		//	Vector2f pos = missile.getPosition();
		//	missile.setPosition(pos.x, (pos.y - 1));
		//	window.draw(missile);

		//	if (pos.y <= 0)
		//	{
		//		isMissileInFlight = false;
		//	}
		//	// don't forget to turn the flag off when the missile goes off screen!
		//}









		gameMgr.draw(window, start);
		// end the current frame; this makes everything that we have 
		// already "drawn" actually show up on the screen
		window.display();

		// At this point the frame we have built is now visible on screen.
		// Now control will go back to the top of the animation loop
		// to build the next frame. Since we begin by drawing the
		// background, each frame is rebuilt from scratch.

	} // end body of animation loop

	return 0;
}

