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

#include <signal.h>
#include <sys/time.h>


//-----------------------------
#include "game.h"
#include "unit.h"

/*
#define border_x_min (col_max-9*col_max/10)
#define border_x_max (col_max-2*col_max/10)
#define border_y_min (row_max-9*row_max/10)
#define border_y_max (row_max-2*row_max/10)
*/

using namespace std;

//typedef enum _Game_status {game_exit=0, game_menu, game_on, game_over} GameStatus;


void init_scr();
void CreateGameFild();
void destr_scr();
void gameMenuOpen();
void gameMenuClose();
void render(Game *GameController,int FrameFlag);
void GTI(int signom);



static int row,col;
static int row_max,col_max;
static int ch;
static int GST;
static char str_BUF1[5],str_BUF2[5],str_BUF3[5];
char buf1[2]={'0',0x00};
int level;
int GameImpuls=0;
int ImpulsFront=0;
int Watchdog=0;



WINDOW *MainMenu, *tuneMenu;

Fild gameFild;

	
//============================= MAIN ======================================
		
int main (int argc, char** argv)
{	
	struct itimerval tmr1;
	tmr1.it_value.tv_sec=0;
	tmr1.it_value.tv_usec=200000;
	tmr1.it_interval.tv_sec=0;
	tmr1.it_interval.tv_usec=200000;

	signal(SIGALRM,GTI);// registring game timer

	
	init_scr(); // initialize ncurses;
	

	gameFild.border_x_min=col_max-9*col_max/10;
	gameFild.border_x_max=col_max-2*col_max/10;
	gameFild.border_y_min=row_max-9*row_max/10;
	gameFild.border_y_max=row_max-2*row_max/10;

	Game *GameController;
	GameController=new Game(gameFild);


	CreateGameFild();  //---------- Draw game fild ----------------------

	setitimer(ITIMER_REAL,&tmr1,NULL); // start game ciclic timer

	//--------------------- main cicle---------------		

	while (ch!='q')
	{
		ch=wgetch(stdscr);
		
		if (ch=='m')
		{
			GameController->setGameStatus(game_stop);
			ImpulsFront=0;

		}


		if (GameController->getGameStatus()==game_stop)
		{
			if (!MainMenu)
				gameMenuOpen();
			switch (ch)
			{
			case 'e':
				GameController->setGameStatus(game_exit);
				GameController->GameOver();
				gameMenuClose();
				ch='q';
				break;
			case 'n':
				GameController->GameOver();
				gameMenuClose();
				CreateGameFild();				
				GameController->setGameStatus(game_new);
				GameController->newGameUnitsSet();
				GameController->setGameStatus(game_on);
				GameController->SnakeControl(Right);
				
				break;
			case '1'...'9':
				buf1[0]=ch;
				level=atoi(buf1);
				break;
			case 'c':
				if(GameController->getGameStatus()!=game_over)
				{
					GameController->setGameStatus(game_on);
					gameMenuClose();
					CreateGameFild();
				}
				break;
			
			}		
		}	
				
				
		if (GameController->getGameStatus()==game_on)
		{
			switch(ch)
			{
				case KEY_LEFT:
						GameController->SnakeControl(Left);	
						break;			
				case KEY_RIGHT:
						GameController->SnakeControl(Right);
						break;
				case KEY_UP:
						GameController->SnakeControl(Up);
						break;
				case KEY_DOWN:
						GameController->SnakeControl(Down);
						break; 
			
				default : break;
			}
		
			if (GameImpuls!=Watchdog)
			{
				ImpulsFront=1;
				Watchdog=GameImpuls;
			}
			else 
			{
				ImpulsFront=0;
			}

			if (ImpulsFront)
			{
				render(GameController,0);
				GameController->SnakeMove();
				render(GameController,1);
			}
		
			//render(GameController);

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
			if ((row>=gameFild.border_y_min)&&(row<=gameFild.border_y_max)&&(col>=gameFild.border_x_min)&&(col<=gameFild.border_x_max))
			{
				if (row==gameFild.border_y_min)
					addch('X');
				if ((row>=gameFild.border_y_min)&&(row<=gameFild.border_y_max)&&(col==gameFild.border_x_min))
					addch('X');
				if ((row>=gameFild.border_y_min)&&(row<=gameFild.border_y_max)&&(col==gameFild.border_x_max))
					addch('X');
				if (row==gameFild.border_y_max)
					addch('X');
			}
			addch(' ');
		}
	}
}


void gameMenuOpen()
{
	MainMenu=newwin(10,20,gameFild.border_y_max/2,gameFild.border_x_max/2);
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


void render(Game *GameCntrl,int FrameFlag)
{
	Point pen;
	Fild pole;

/*
	sprintf(str_BUF3,"%d",ImpulsFront);
	mvaddstr(gameFild.border_y_max/2,gameFild.border_x_min/2-5,str_BUF3);
*/


	pole=GameCntrl->getGameFild();
		
	if (GameCntrl->getGameStatus()==game_on){
		GameCntrl->getRabbitPlace(pen);
		mvaddch(pen._y,pen._x,'*');

		for (int i=0;i<GameCntrl->getSnakeLen();i++){

			if (GameCntrl->getSnakeBodyPartsCords(i,pen)){
			        if (FrameFlag)
					mvaddch(pen._y,pen._x,'@');
				else
					mvaddch(pen._y,pen._x,' ');
			}
		}
			sprintf(str_BUF1,"%d",GameCntrl->getGameScore());
			mvaddstr(pole.border_y_max+3,pole.border_x_min,"Score-");			
			mvaddstr(pole.border_y_max+3,pole.border_x_min+7,str_BUF1);		
			sprintf(str_BUF2,"%d",GameCntrl->getGameLevel());
			mvaddstr(pole.border_y_max+4,pole.border_x_min,"Level-");			
			mvaddstr(pole.border_y_max+4,pole.border_x_min+7,str_BUF2);			
	
	}

	if (GameCntrl->getGameStatus()==game_over){
		mvaddstr(pole.border_y_max/2,pole.border_x_max/2-5,"G A M E   O V E R !!!!");
	}

	wrefresh(stdscr);

}

void GTI (int signom)
{
	sprintf(str_BUF2,"%d",GameImpuls);
	mvaddstr(gameFild.border_y_max+2,gameFild.border_x_min,str_BUF2);
	GameImpuls++;
}

