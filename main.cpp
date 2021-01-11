/*
This is the console executable, that makes use of the fSnakeGame class.
This is handling all user interaction. For game logic, please see fSnakeGame.h.
*/
#include "fSnakeGame.h"
#include <stdio.h>
#include <time.h>
extern int color;

int maxheight, maxwidth;
void PlayGame();
int IsUserReady();
int ChooseSpeed();
int ChooseBody();
int AskUserName();
int AskUserToPlayAgain();
void ClearCentre();
int UserInput();
//int UserInputName();
char name[10];
char level[1];
char pattern[1];

int main ()
{	
	if (IsUserReady() == 'y') // wait for confirmation of the user
	do {
		ChooseSpeed();		
		refresh();
		ChooseBody();
		//refresh();
		AskUserName();
		{
			fSnakeGame NewSnake;
			NewSnake.PlayGame();
		}
	}
	while (AskUserToPlayAgain() == 'y');
	return 0;
}

// clear the screen and centre the cursor
void ClearCentre(float x, float y)
{
	clear(); // clear the screen if the game is played for the 2nd time	
	initscr(); 
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_BLUE, COLOR_YELLOW);
	init_pair(4, COLOR_WHITE, COLOR_BLUE);
	init_pair(5, COLOR_WHITE, COLOR_RED);
	init_pair(6, COLOR_BLACK, COLOR_WHITE);
	init_pair(7, COLOR_WHITE, COLOR_RED);
	int color = rand() % 7 + 1;
	wbkgd(stdscr, COLOR_PAIR(color));
 
 	noecho();
 	getmaxyx(stdscr, maxheight, maxwidth);
 	move((maxheight/y), (maxwidth/x));
	move(x,y);
}

// receive user confirmation
int UserInput()
{
	int UserInput = getch();
	refresh();
	endwin();
	clear();

	return UserInput;	
}


// print start menu
int IsUserReady() 
{
	ClearCentre(10, 5);
	printw("Welcome to the Snake Game. Are you ready? (y/n)");
	return UserInput();
}

int AskUserName()
{
	move(10, 5);
	printw("Please enter your name: ");
	//refresh();	
	echo();
	getstr(name);
	noecho();
	endwin();
	clear();
}

int ChooseSpeed()
{
	move(10, 5);
	printw("Choose the speed (0 for slowest, 9 for fastest): ");
	//refresh();	
	echo();
	getstr(level);
	noecho();
	endwin();
	clear();
}

int ChooseBody()
{
	move(10, 5);
	printw("Choose snake body's pattern: ");
	//refresh();	
	echo();
	getstr(pattern);
	noecho();
	endwin();
	clear();
}

// print end of the game menu and ask user to play again
int AskUserToPlayAgain()
{
	ClearCentre(10, 5);
	printw("Do you want to play again, ");
	printw(name);
	printw("? (y/n)");
	return UserInput();
}
