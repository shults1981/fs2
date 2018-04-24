//++++++++++++++++++++
//++++++++++++++++++++
//    game.cpp    
//+++++++++++++++++++
//++++++++++++++++++


#include "game.h"





Game::Game(const Fild game_fild,const Point &SnakePlace, const Point &RabbitPlace):
				snake(SnakePlace),rabbit(RabbitPlace)
{
	GST=game_stop; 
	GameFild=game_fild;
}

Game::~Game() {}

int Game::setGameStatus(GameStatus gst){ GST=gst; }
GameStatus Game::getGameStatus(){ return GST; }


