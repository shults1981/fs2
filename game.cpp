//++++++++++++++++++++
//++++++++++++++++++++
//    game.cpp    
//+++++++++++++++++++
//++++++++++++++++++


#include "game.h"
#include <stdlib.h>
#include <time.h>





Game::Game(const Fild game_fild)
		/*,const Point &SnakePlace, 
		const Poiint &RabbitPlace)*/
		:snake(),rabbit()
{
	GST=game_stop; 
	GameFild=game_fild;

		

	srand(time(0));
}

Game::~Game() {}


int Game::NewGameUnitsSet()
{
	if(GST==game_stop){
//	 Snake.addNewElementInUnitBody();
		
		
	}

	return 1;
}


int Game::setGameStatus(GameStatus gst){ GST=gst; }
GameStatus Game::getGameStatus(){ return GST; }


