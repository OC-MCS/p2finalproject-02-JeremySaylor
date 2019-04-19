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

class GameMgr
{
private:

public:
	GameMgr(GameUI *m)
	{

	}



	void handleMouseUp(Vector2f mouse, GameUI m)
	{
		////6.	How to determine if the mouse is over something

		/*if (blueBtn.getGlobalBounds().contains(mouse))
		{
			mgr1->setCurColor(Color::Blue);
		}
		if (redBtn.getGlobalBounds().contains(mouse))
		{
			mgr1->setCurColor(Color::Red);
		}
		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			mgr1->setCurColor(Color::Green);
		}*/
		if (m.getBttn().getGlobalBounds().contains(mouse))
		{
			//mgr1->setCurShape(SQUARE);
		}
	/*	if (circleBtn.getGlobalBounds().contains(mouse))
		{
			mgr1->setCurShape(CIRCLE);
		}*/
		//settingsMgr.getCurShape(), settingsMgr.getCurColor()
		//CIRCLE, SQUARE

			// mouse is a vector2f
//	// mouse is currently over colorBtn
	}

	void die(string msg)
	{
		cout << msg << endl;
		exit(-1);
	}

	void draw(RenderWindow& win, GameUI m)
	{

		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
		{
			die("couldn't load font");
		}
		
		// title 1
		Text title("Lives Left: ", font, 15);
		title.setPosition(15, 15);
		win.draw(title);

		// title 2
		Text title2("Alien Ships Killed: ", font, 15);
		title2.setPosition(400, 15);
		win.draw(title2);

		/*win.draw(blueBtn);

		win.draw(redBtn);

		win.draw(greenBtn);*/

		win.draw(m.getBttn());

		//win.draw(circleBtn);
	}

};

