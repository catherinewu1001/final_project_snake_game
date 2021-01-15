/*
game logic 
(not user interaction)
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
	// partchar : snake's body
	// edgechar : the edge of the game window
	// del :delay
	bool bEatsFruit;
	bool bEatsBadFruit;

	CharPosition fruit;
	CharPosition badfruit;    

	std::vector<CharPosition> snake; 
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

	bool FatalCollision();
	bool WallCollision();
	void MoveSnake();
	bool GetsFruit();
	bool GetsBadFruit();

public:

	fSnakeGame();
	~fSnakeGame(); 
	void PlayGame();
};

#endif
