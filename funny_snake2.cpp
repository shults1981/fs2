/*
|*****************************************************************
|*****************************************************************
* Project                        :  <Funny Snake #2>

* Programm name                  :  funny_snake.cpp

* Author                         :  Shults1981

* Data create                    :  01/03/2018

* Purpose                        :  classical game "SNAKE";
								    testing library ncurses #2

|****************************************************************
|****************************************************************
*/
#include <iostream>
#include <ncurses.h>
#include <stdlib.h>


//-----------------------------
#include "game.h"
#include "unit.h"


#define border_x_min (col_max-9*col_max/10)
#define border_x_max (col_max-2*col_max/10)
#define border_y_min (row_max-9*row_max/10)
#define border_y_max (row_max-2*row_max/10)

using namespace std;

//typedef enum _Game_status {game_exit=0, game_menu, game_on, game_over} GameStatus;


void init_scr();
void CreateGameFild();
void destr_scr();
void gameMenuOpen();
void gameMenuClose();


static int row,col;
static int row_max,col_max;
static int ch;
static int GST;
static char str_BUF1[5],str_BUF2[5];
char buf1[2]={'0',0x00};
int level;


WINDOW *MainMenu, *tuneMenu;

	
//============================= MAIN ======================================
		
int main (int argc, char** argv)
{	
	init_scr(); // initialize ncurses;
	
	CreateGameFild();  //---------- Make game fild ----------------------

	//--------------------- main cicle---------------		

	while (ch!='q')
	{
		ch=wgetch(stdscr);
		
		if (ch=='m')
		{
			GST=1;

		}


		if (GST==1)
		{
			if (!MainMenu)
				gameMenuOpen();
			switch (ch)
			{
			case 'e':
				GST=0;
				gameMenuClose();
				ch='q';
				break;
			case 'n':
				GST=2;
				gameMenuClose();
				CreateGameFild();

				break;
			case '1'...'9':
				buf1[0]=ch;
				level=atoi(buf1);
				break;
			case 'c':
				if(1)
				{
					GST=2;
					gameMenuClose();
					CreateGameFild();
				}
				break;
			
			}		
		}	
				
				
		if (GST==game_on)
		{
			switch(ch)
			{
				case KEY_LEFT:	
					break;			
				case KEY_RIGHT:
						break;
				case KEY_UP:	
						break;
				case KEY_DOWN:
						break; 
			
				default : break;
			}
		}
	}


	destr_scr();//-----------delete screen -------------

	return 0;
}	




void init_scr()
{

	//-------------init ncurses -----------------------------------
	initscr();
	start_color();
	nodelay(stdscr,TRUE);
	curs_set(0);
	keypad (stdscr, TRUE);
	noecho();
	init_pair (1,COLOR_WHITE,COLOR_BLUE);
	init_pair (2,COLOR_WHITE,COLOR_BLUE);
	attron(COLOR_PAIR(1));
	getmaxyx(stdscr,row_max,col_max);
}

void destr_scr()
{
	endwin();
}

void CreateGameFild()
{
int row, col;

	for (row=0;row<=row_max;row++)
	{
		for (col=0;col<=col_max;col++)
		{
			move(row,col);
			if ((row>=border_y_min)&&(row<=border_y_max)&&(col>=border_x_min)&&(col<=border_x_max))
			{
				if (row==border_y_min)
					addch('X');
				if ((row>=border_y_min)&&(row<=border_y_max)&&(col==border_x_min))
					addch('X');
				if ((row>=border_y_min)&&(row<=border_y_max)&&(col==border_x_max))
					addch('X');
				if (row==border_y_max)
					addch('X');
			}
			addch(' ');
		}
	}
}


void gameMenuOpen()
{
	MainMenu=newwin(10,20,border_y_max/2,border_x_max/2);
	wbkgd(MainMenu,COLOR_PAIR(2));
	wattron(MainMenu,COLOR_PAIR(2));
	box(MainMenu,ACS_VLINE,ACS_HLINE);
	wmove(MainMenu,0,5);
	waddstr(MainMenu,"MENU");
	wmove(MainMenu,2,1);
	waddstr(MainMenu,"NEW GAME - 'n'");
	wmove(MainMenu,4,1);
	waddstr(MainMenu,"LEVEL - 1...9");
	wmove(MainMenu,6,1);
	waddstr(MainMenu,"CONTINUE - 'C'");
	wmove(MainMenu,8,1);
	waddstr(MainMenu,"EXIT - 'e'");
	wrefresh(MainMenu);
}

void gameMenuClose()
{
	delwin(MainMenu);
	MainMenu=NULL;
}

