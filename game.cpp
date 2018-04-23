//++++++++++++++++++++
//++++++++++++++++++++
//    game.cpp    
//+++++++++++++++++++
//++++++++++++++++++


#include "game.h"





Game::Game(const Point &PointSN, const Point &PointRB):snake(PointSN),rabbit(PointRB){ GST=game_stop; }

Game::~Game() {}

int Game::setGameStatus(GameStatus gst){ GST=gst; }
GameStatus Game::getGameStatus(){ return GST; }


