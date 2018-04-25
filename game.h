//++++++++++++++++++++++++
//++++++++++++++++++++++++
//   game.h   
//++++++++++++++++++++++++
//+++++++++++++++++++++++


#ifndef GAME_H
#define GAME_H

#include "unit.h"

typedef enum _game_status{game_exit=0,game_stop,game_on,game_over,game_new} GameStatus;

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
	Snake snake;
	Rabbit rabbit;
	GameStatus GST;	
	Fild GameFild;

	Game();

public:
	Game(const Fild gamefild)/*,
		const Point &SnakePlace,
		const Point &RabbitPlace)*/;
	~Game();	
	int NewGameUnitsSet();
	int setGameStatus(GameStatus gst);
	GameStatus getGameStatus();	

};






#endif


