/*
This is the game logic (no user interaction).
The game is a very simple version of the classic snake game.
*/

#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#ifndef FSNAKEGAME_H
#define FSNAKEGAME_H

extern char name[10];
extern char level[1];
extern char pattern[1];
const int MaxWallNumber = 10; 

struct CharPosition 
{
	int x, y;
	CharPosition(int col, int row);
	CharPosition();
};
class fSnakeGame 
{
private:
	int score, del, maxwidth, maxheight;
	char direction, partchar, edgechar, fruitchar, badfruitchar;
	// partchar is the character representing the snake's body
	// edgechar is the character representing the edge of the game window
	// fruitchar is the character representing the fruit
	// del stands for ay
	bool bEatsFruit;
	bool bEatsBadFruit;

	CharPosition fruit; // need to clarify this combination 
	CharPosition badfruit;    

	std::vector<CharPosition> snake; // represent the snake's body
	int wallNumber;
	int vertical[MaxWallNumber];
	int start1[MaxWallNumber];
	int start2[MaxWallNumber];
	int length[MaxWallNumber];
	
	void InitGameWindow();
	void DrawWindow();  
	void DrawWall();
	void DrawSnake();
	void PrintScore();
	void PrintName();

	void PositionFruit();
 	void PositionBadFruit();   
	void Positionaa();   

	bool FatalCollision();
	bool WallCollision();
	void MoveSnake();
	bool GetsFruit();
	bool GetsBadFruit();

public:

	fSnakeGame();
	~fSnakeGame(); // destructor for cleanup and memory deallocation
	void PlayGame();
};

#endif
