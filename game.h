//++++++++++++++++++++++++
//++++++++++++++++++++++++
//   game.h   
//++++++++++++++++++++++++
//+++++++++++++++++++++++


#ifndef GAME_H
#define GAME_H

#include "unit.h"


//=============== for DEBUG 
#include <fstream>
//-------------------------



typedef enum _game_status{game_exit=0,game_stop,game_on,game_over,game_new} GameStatus;
typedef enum _unit_status{unit_is_dead=0,unit_is_alive} UnitStatus;
typedef enum _move_direction{Left=1,Right,Up,Down} MoveDirection;
typedef enum _level{easy=0,midle,hi,master} Level;




struct Fild
{ 
	int border_x_min;
	int border_x_max;
	int border_y_min;
	int border_y_max;
};


class Game
{
private:
	int GameLevel;
	int GameScore;

	Snake snake;
	Rabbit rabbit;
	GameStatus GST;	
	Fild GameFild;
	UnitStatus rabbitStatus,snakeStatus;
	MoveDirection move_flag;
	
	Game();



public:
	Game(const Fild gamefild);
	~Game();	
	int newGameUnitsSet();
	int setGameStatus(GameStatus gst);
	GameStatus getGameStatus();	
	int getSnakeLen();
	int getRabbitLen();
	void RabbitFactory();
	int getRabbitPlace(Point &PointDEST);
	int getSnakeBodyPartsCords(int BodyPartIndex, Point &PointDEST);
	int SnakeControl(MoveDirection md);
	int SnakeMoveToOneStep();
	Fild getGameFild();
	int GameOver();
	int getGameScore();
	int getGameLevel();

	int DBG_f1();
};






#endif

