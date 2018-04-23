//++++++++++++++++++++++++
//++++++++++++++++++++++++
//   game.h   
//++++++++++++++++++++++++
//+++++++++++++++++++++++


#ifndef GAME_H
#define GAME_H

#include "unit.h"

typedef enum _game_status{game_exit=0,game_stop,game_on,game_over} GameStatus;

class Game
{
private:
	Snake snake;
	Rabbit rabbit;
	GameStatus GST;	


	Game();

public:
	Game(const Point &PointSN, const Point &PointRB);
	~Game();	
	int setGameStatus(GameStatus gst);
	GameStatus getGameStatus();	

};






#endif


