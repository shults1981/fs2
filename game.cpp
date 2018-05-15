//++++++++++++++++++++
//++++++++++++++++++++
//    game.cpp    
//+++++++++++++++++++
//++++++++++++++++++


#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>




Game::Game(const Fild game_fild):snake(),rabbit()
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
//
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


int Game::SnakeMove()
{
	int i,j,turn_flag;

	if (GST==game_on){
		Point tempPoint1,tempPoint2,tempPoint3;
		snake.getBodyCords(0,tempPoint1);
		rabbit.getBodyCords(0,tempPoint2);
//-------------body control and manage-------------
		if ((tempPoint1._x==tempPoint2._x)&&(tempPoint1._y==tempPoint2._y)){
			snake.addNewElementInUnitBody(tempPoint2);
			rabbitStatus==unit_is_dead;	
		}
//-------------------------------------------------

		if (tempPoint1._d!=move_flag){
			tempPoint1._d=move_flag;
			if((snake.getBodyLen()>1) && 
			   (snake.getBodyTPANum()<=snake.getBodyLen()-1))
				snake.addNewElementInBodyTPA(tempPoint1);
		}
		
		for (i=0;i<snake.getBodyLen();i++){
			turn_flag=0;
			snake.getBodyCords(0,tempPoint1);
			if ((tempPoint1._x>GameFild.border_x_min)&&(tempPoint1._x<GameFild.border_x_max)&&(tempPoint1._y>GameFild.border_y_min) &&
				(tempPoint1._y>GameFild.border_y_max)){
				if(snake.getBodyTPANum()){
					for(j=snake.getBodyTPANum()-1;j>=0;j--){
						snake.getBodyCords(i,tempPoint2);
						snake.getBodyTPA(j,tempPoint3);
						if((tempPoint2._x==tempPoint3._x) &&
							(tempPoint2._y==tempPoint3._y)){
							switch(tempPoint3._d)
							{
							case 1:
								tempPoint2._x--;
								break;
							case 2:
								tempPoint2._x++;
								break;
							case 3:
								tempPoint2._y--;
								break;
							case 4:
								tempPoint2._y++;
								break;
							default:break;
							}
							tempPoint2._d=tempPoint3._d;
							snake.setBodyElement(i,tempPoint2);
							if((i==snake.getBodyLen()-1) && (j==0))
								snake.delElementFromBodyTPA();
							turn_flag=1;
						}
					}		
				}
				if (!turn_flag){
					switch(tempPoint2._d)
					{
					case 1:
						tempPoint2._x--;
						break;
					case 2:
						tempPoint2._x++;
						break;
					case 3:
						tempPoint2._y--;
						break;
					case 4:
						tempPoint2._y++;
						break;
					default:break;
					}
					snake.setBodyElement(i,tempPoint2);
				}
			}
			else
				GST=game_over;
		}
		
	}
	return 1;
}

int Game::SnakeControl(MoveDirection md)
{
	Point tempPoint1;
	
	snake.getBodyCords(0,tempPoint1);	

	switch(md)
	{
	case left:
		if (snake.getBodyLen()==1)
			move_flag=left;
		else 
			if((snake.getBodyLen()>1)&&(tempPoint1._d==2))
				move_flag=left;
		break;

	case right:
		if (snake.getBodyLen()==1)
			move_flag=right;
		else
			if((snake.getBodyLen()>1)&&(tempPoint1._d==1))
				move_flag=right;	
		break;

	case up:
		if (snake.getBodyLen()==1)
			move_flag=up;
		else
			if((snake.getBodyLen()>1)&&(tempPoint1._d==3))
				move_flag=up;				
		break;

	case down:
		if (snake.getBodyLen()==1)
			move_flag=down;	
		else
			if((snake.getBodyLen()>1)&&(tempPoint1._d==4))
				move_flag=down;
		break;
	
	default: break;


	}
	return 1;
}

int Game::GameOver()
{

	if (GST==game_over){
		snake.ClearBodyAndTPA();
		rabbit.ClearBodyAndTPA();
	}

	return 1;
}











