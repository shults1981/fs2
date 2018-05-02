//++++++++++++++++++++
//++++++++++++++++++++
//    game.cpp    
//+++++++++++++++++++
//++++++++++++++++++


#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>




Game::Game(const Fild game_fild)
		/*,const Point &SnakePlace, 
		const Poiint &RabbitPlace)*/
		:snake(),rabbit()
{
	GST=game_stop; 
	GameFild=game_fild;
	rabbitStatus=unit_is_dead;		

	srand(time(0));
}

Game::~Game() {}


int Game::newGameUnitsSet()
{
	if((GST==game_new)){
		Point bufVar;
		bufVar._x=(GameFild.border_x_max-GameFild.border_x_min)/2;
		bufVar._y=(GameFild.border_y_max-GameFild.border_y_min)/2;
		bufVar._d=1;
		snake.addNewElementInUnitBody(bufVar);		
	
	rabbitStatus=unit_is_dead;
	RabbitFactory();
	return 1;
	}
	else
		return 0;
}
int Game::setGameStatus(GameStatus gst){ GST=gst; }
GameStatus Game::getGameStatus(){ return GST; }


int Game::getSnakeLen()
{
	return snake.getBodyLen();
}

int Game::getRabbitLen()
{
	return rabbit.getBodyLen();
}

void Game::RabbitFactory()
{
	if (!rabbitStatus){
		Point bufVar;
		bufVar._x=GameFild.border_x_min+rand()%(GameFild.border_x_max-GameFild.border_x_min-1)+1;
		bufVar._y=GameFild.border_y_min+rand()%(GameFild.border_y_max-GameFild.border_y_min-1)+1;
		bufVar._d=0;
		rabbit.setBodyElement(0,bufVar);
		rabbitStatus=unit_is_alive;
	}	
		
}

		
int Game::getRabbitPlace(Point &PointDEST)
{
	return rabbit.getBodyCords(0,PointDEST);
}

int  Game::getSnakeBodyPartsCords(int BodyPartIndex, Point &PointDEST)
{
	if ((BodyPartIndex>=0)&&(BodyPartIndex<(snake.getBodyLen()))){
		snake.getBodyCords(BodyPartIndex,PointDEST);		
		return 1;
	}
	else
		return 0;
}


int Game::SnakeMove(int move_flag)
{
	if (GST==game_on){
		Point tempPoint1,tempPoint2,tempPoint3;
		snake.getBodyCords(0,tempPoint1);
		rabbit.getBodyCords(0,tempPoint2);
//-------------body control and manage-------------
		if ((tempPoint1._x==tempPoint2._x)&&(tempPoint1._y==tempPoint2._y)){
			snake.addNewElementInUnitBody(tempPoint2);
			rabbitStatus==unit_is_dead;	
		}
//

		if (tempPoint1._d!=move_flag){
			tempPoint1._d=move_flag;
			if((snake.getBodyLen()>1) && 
			   (snake.getBodyTPANum()<=snake.getBodyLen()-1))
				snake.addNewElementInBodyTPA(tempPoint1);
		}


	}





	return 1;


}


