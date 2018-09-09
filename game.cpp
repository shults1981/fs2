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
	snakeStatus=unit_is_dead;	
	GameScore=0;
	GameLevel=1;

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
		snakeStatus=unit_is_alive;
		rabbitStatus=unit_is_dead;
		RabbitFactory();
		GameScore=0;
		return 1;
	}
	else
		return 0;
}
int Game::setGameStatus(GameStatus gst)
{
	GST=gst;

	if ((GST==game_over)||(GST==game_exit))
		GameOver();

	if (GST==game_new){
		GameOver();   ///?????????????????????????????????????????
		newGameUnitsSet();
		SnakeControl(static_cast<MoveDirection>(rand()%4+1));//rand()%4+1
	}
	return 1;
 }



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


int Game::SnakeMoveToOneStep()
{
	int i,j,turn_flag;
	unsigned int kill_self=0,border_crash=0;

	if (GST==game_on){
		Point tempPoint1,tempPoint2,tempPoint3;
		snake.getBodyCords(0,tempPoint1);
		rabbit.getBodyCords(0,tempPoint2);
//-------------body control and manage-------------
		if ((tempPoint1._x==tempPoint2._x)&&(tempPoint1._y==tempPoint2._y)){
			snake.addNewElementInUnitBody(tempPoint2);
			GameScore++;
			rabbitStatus=unit_is_dead;
			RabbitFactory();	
		}
//-------------------------------------------------
		//std::cout<<move_flag<<std::endl;
		if (tempPoint1._d!=(int)move_flag){
			tempPoint1._d=(int)move_flag;
			snake.setBodyElement(0,tempPoint1);
			//--------------------------------------------------
			if((snake.getBodyLen()>1) && (snake.getBodyTPANum()<=(snake.getBodyLen()-1)))
				snake.addNewElementInBodyTPA(tempPoint1);
		}
			
	
		snake.getBodyCords(0,tempPoint1);
		for (i=0;i<snake.getBodyLen();i++){
			turn_flag=0;
			snake.getBodyCords(i,tempPoint2);
			if(snake.getBodyTPANum()){
				for(j=snake.getBodyTPANum()-1;j>=0;j--){
					snake.getBodyTPA(j,tempPoint3);
					if((tempPoint2._x==tempPoint3._x) && (tempPoint2._y==tempPoint3._y)){
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
				default:
					break;
				}
				snake.setBodyElement(i,tempPoint2);
			}
		}

		snake.getBodyCords(0,tempPoint1);
		border_crash=!((tempPoint1._x>GameFild.border_x_min)&&(tempPoint1._x<GameFild.border_x_max)&&(tempPoint1._y>GameFild.border_y_min) &&(tempPoint1._y<GameFild.border_y_max));		

		for (i=1;i<snake.getBodyLen();i++){
			snake.getBodyCords(i,tempPoint2);
			if ((tempPoint1._x==tempPoint2._x)&&(tempPoint1._y==tempPoint2._y))
				kill_self=1;			
		}
			


		if (border_crash /*||kill_self*/ ) {
			GST=game_over;
			snakeStatus=unit_is_dead;
		}
		else {	}
	}
	return 1;
}

int Game::SnakeControl(MoveDirection md)
{
	Point tempPoint1;
	
	snake.getBodyCords(0,tempPoint1);	

	switch(md)
	{
	case Left:
		if (snake.getBodyLen()==1){
			move_flag=Left;
		}
		else 
			if((snake.getBodyLen()>1)&&(!(tempPoint1._d==2)))
				move_flag=Left;
		break;

	case Right:
		if (snake.getBodyLen()==1){
			move_flag=Right;
		}
		else
			if((snake.getBodyLen()>1)&&(!(tempPoint1._d==1)))
				move_flag=Right;	
		break;

	case Up:
		if (snake.getBodyLen()==1)
			move_flag=Up;
		else
			if((snake.getBodyLen()>1)&&(!(tempPoint1._d==4)))
				move_flag=Up;				
		break;

	case Down:
		if (snake.getBodyLen()==1)
			move_flag=Down;	
		else
			if((snake.getBodyLen()>1)&&(!(tempPoint1._d==3)))
				move_flag=Down;
		break;
	
	default: break;


	}
	return 1;
}


Fild Game::getGameFild()
{
	return GameFild; 
}


int Game::GameOver()
{

	if (GST==game_over){
		snake.ClearBodyAndTPA();
		rabbit.ClearBodyAndTPA();
	}

	return 1;
}

int Game::getGameScore()
{
	return GameScore;

}

int Game::getGameLevel()
{
	return GameLevel;
}

int Game::DBG_f1()
{
	return snake.getBodyTPANum();
}






