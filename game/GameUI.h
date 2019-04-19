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

class GameUI
{
private:
	RectangleShape squareBtn;

public:
	GameUI()
	{
		Vector2f sqPos(70, 400);
		squareBtn.setPosition(sqPos);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(40, 40));
		squareBtn.setFillColor(Color::White);
	}
	RectangleShape getBttn()
	{
		return squareBtn;
	}
	






	//void gameWindow()
	//{
	//	const int WINDOW_WIDTH = 800;
	//	const int WINDOW_HEIGHT = 600;
	//	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "aliens!");
	//	// Limit the framerate to 60 frames per second
	//	window.setFramerateLimit(60);
	//}

	//void draw(RenderWindow& win, ShapeMgr *mgr);
};

