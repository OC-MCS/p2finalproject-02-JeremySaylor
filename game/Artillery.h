#pragma once
//================================================
// Jeremy Saylor
// 19 Apr 2019
// Final Programming Assignment
// Pragramming II
//================================================
#include "Missile.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Artillery: public Missile 
{
private:
	
	Missile *head;
public:

	Artillery()
	{
		head = nullptr;
	}
	
	 void addWeapon()
	{
		Missile *newNode;  // To point to a new node
		Missile *nodePtr;  // To move through the list

		newNode = new Missile;
		//newNode->value = num;
		/*Texture missileTexture;
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		newNode->getSprite().setTexture(missileTexture);*/

		newNode->setMissPtr(nullptr);

		if (!head)
			head = newNode;
		else  // Otherwise, insert newNode at end.
		{
			nodePtr = head;
			
			while (nodePtr->getMissilePtr())
				nodePtr = nodePtr->getMissilePtr();
			nodePtr->setMissPtr(newNode); 
		}
		
	}


	 void setPos(Vector2f p)
	 {
		 this->setPos(p); 
	 }
	 // Vector2f getPos()
	// {
	//	 Missile node;
	//	 return node.pos;
	// }
	 void setPosition(float s, float t)
	 {
		 this->setPosXY(s,(t-1));
	 }
	 void drawMissile(RenderWindow& win)
	 {
		 Missile *nodePtr;
		 if (head)
		 {
			 nodePtr = head;
			// nodePtr->drawMis(win);
			 win.draw(nodePtr->getSprite());

			 while (nodePtr->getMissilePtr())
				 nodePtr = nodePtr->getMissilePtr();
			// nodePtr->drawMis(win);
			 win.draw(nodePtr->getSprite());
		 }



		 //this->drawMissile(win);
		// win.draw(this->getSprite());

	 }


	//Artillery()
	//{
	//	Texture missileTexture;
	//	if (!missileTexture.loadFromFile("missile.png"))
	//	{
	//		cout << "Unable to load missile texture!" << endl;
	//		exit(EXIT_FAILURE);
	//	}
	//	missPtr->sidewinder.setTexture(missileTexture);

	//}
	//Artillery(Vector2f p)
	//{
	//	missPtr->pos = p;

	//	Texture missileTexture;
	//	if (!missileTexture.loadFromFile("missile.png"))
	//	{
	//		cout << "Unable to load missile texture!" << endl;
	//		exit(EXIT_FAILURE);
	//	}
	//	missPtr->sidewinder.setTexture(missileTexture);
	//}
	// 
	//void setPos(Vector2f p)
	//{
	//	missPtr->pos = p;
	//}
	///*void addTexture(Texture h)
	//{
	//	missPtr->sidewinder.setTexture(h);
	//};*/

	//FloatRect missileBounds()
	//{
	//	return missPtr->sidewinder.getGlobalBounds();
	//}
	////FloatRect missileBounds = missile.getGlobalBounds();

	//bool checkHit(const FloatRect &g) 
	//{
	//	/*FloatRect myMissile = missPtr->sidewinder.getGlobalBounds();
	//	bool temp = false;
	//	if (myMissile.intersects(g))
	//	{
	//		temp = true;
	//	}
	//	return temp;*/
	//}

	//void draw(RenderWindow& win)
	//{
	//	win.draw(missPtr->sidewinder);
	//}



};


