// ==============================================
// проверка #2 использования библиотеки  ncurses
// ============== игра змейка ==================
// ==============================================
// ==============================================

//---------------------------
#include <iostream>



//-----------------------------
#include "game.h"
#include "unit.h"


using namespace std;
	
//============================= MAIN ======================================
		
int main (int argc, char** argv)
{	
	
cout<<"Funny snake v2"<<endl;

//------ test for class PoinArr 
Point p1={1,2,3};
Point p2={4,5,6};
Point p3={7,8,9};
PointArr pa1(2);
pa1.addElementInBegin(p1);
pa1.addElementInBack(p2);

cout<<pa1.getLen()<<endl;
for (int i=0;i<pa1.getLen();i++){
	cout<<pa1.getElement(i)._x<<"--"<<pa1.getElement(i)._y<<"--"<<pa1.getElement(i)._d<<"--"<<endl;
}


pa1.delElementFromBegin();
pa1.delElementFromBack();


//-------end of test 




return 0;
}	



