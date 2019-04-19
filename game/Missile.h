#pragma once
//================================================
// Jeremy Saylor
// 19 Apr 2019
// Final Programming Assignment
// Pragramming II
//================================================

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Missile
{
private:
	
		Sprite sidewinder;
		Vector2f pos;
		Missile *ptrMnext;
public:
	Missile()
	{}
	Sprite getSprite()
	{
		return sidewinder;
	}
	Vector2f getPos()
	{
		return sidewinder.getPosition();
	}
	void setPos(Vector2f p)
	{
		sidewinder.setPosition(p);
	}
	void setPosXY(float s, float t)
	{
		Vector2f p;
		p.x = s;
		p.y = t;
		sidewinder.setPosition(p);

	}

	void setMissPtr(Missile *m)
	{
		ptrMnext = m;
		Texture missileTexture;
		if (!missileTexture.loadFromFile("missile.png"))
		{
			cout << "Unable to load missile texture!" << endl;
			exit(EXIT_FAILURE);
		}
		sidewinder.setTexture(missileTexture);

	}
	Missile *getMissilePtr()
	{
		return ptrMnext;
	}
	/*void drawMis(RenderWindow& win)
	{
		win.draw(sidewinder);

	}*/


};


