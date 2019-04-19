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


class Aliens
{
	struct ListNode
	{
		int value;           // The value in this node

		//Sprite enemy;

		struct ListNode *next;  // To point to the next node
	};

	ListNode *head;            // List head pointer

	struct alien
	{
	Sprite enemy;
	Vector2f pos;
	//Vector2f *posPtr;
	};
	alien *posPtr;

public:

	Aliens()
	{
		head = nullptr;
	}
	/*NumberList operator = (const NumberList &other);*/

	~Aliens();
	//int getXpos()
	//{
	//	int temp;
	//	temp = posPtr->pos.x;



	//	return temp;
	//}


	void setpos(float x, float y)
	{
		posPtr->pos.x = x;
		posPtr->pos.y = y;
	}
	Vector2f getPos()
	{
		return posPtr->pos;
	}

	Sprite getSprite()
	{
		return posPtr->enemy;
	}
	/*Sprite getEnemy();*/
	
	void addSprite(Texture);
	//void addPosition();
	// Linked list operations
	void appendNode(int);
	void insertNode(int);
	void deleteNode(int);
	void displayList() const;
};

