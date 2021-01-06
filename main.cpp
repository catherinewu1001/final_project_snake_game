/*
This is the console executable, that makes use of the fSnakeGame class.
This is handling all user interaction. For game logic, please see fSnakeGame.h.
*/
#include "fSnakeGame.h"
#include <stdio.h>
#include <time.h>

// Unreal standards
using int32 = int;

int32 maxheight, maxwidth;
void PlayGame();
int32 IsUserReady();
int32 AskUserName();
int32 AskUserToPlayAgain();
void ClearCentre();
int32 UserInput();
int32 UserInputName();
char name[10];


int32 main ()
{	
	if (IsUserReady() == 'y') // wait for confirmation of the user
	do {
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
 	start_color(); //改顏色
 	init_pair(1, COLOR_RED, COLOR_GREEN);
 	init_pair(2, COLOR_BLACK, COLOR_WHITE);
 	init_pair(3, COLOR_BLUE, COLOR_YELLOW);
 	//attron(COLOR_PAIR(1);
	wbkgd(stdscr, COLOR_PAIR(2)); //可以選擇要第幾個pair（可再新增配色）
	//refresh();
 
 	noecho();
 	getmaxyx(stdscr, maxheight, maxwidth);
 	move((maxheight/y), (maxwidth/x));
}

// receive user confirmation
int32 UserInput()
{
	int32 UserInput = getch();
	refresh();
	endwin();
	clear();

	return UserInput;	
}


// print start menu
int32 IsUserReady() 
{
	ClearCentre(3, 2.5);
	printw("Welcome to the Snake Game. Are you ready? (y/n)");
	return UserInput();
}

int32 AskUserName()
{
	ClearCentre(3, 2.5);
	printw("Please enter your name: ");
	refresh();	
	echo();
	getstr(name);
	noecho();
	endwin();
	clear();
}

// print end of the game menu and ask user to play again
int32 AskUserToPlayAgain()
{
	ClearCentre(3, 2.5);
	printw("Do you want to play again, ");
	printw(name);
	printw("? (y/n)");
	return UserInput();
}
