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

//------ test for class PoinArr--------------------------------------- 
Point p1={1,2,3};
Point p2={4,5,6};
Point p3={7,8,9};
PointArr pa1(2);
PointArr pa3(1);


cout<<pa1.getLen()<<endl;
cout<<"+++++++++++++++test constructor +++++++++++++"<<endl;
for (int i=0;i<pa1.getLen();i++){
	cout<<pa1.getElement(i)._x<<"--"<<pa1.getElement(i)._y<<"--"<<pa1.getElement(i)._d<<"--"<<endl;
}

cout<<"+++++++++++ test insert in back and in begin+++++++++++++++++++++++"<<endl;
pa1.addElementInBegin(p1);
pa1.addElementInBack(p2);
for (int i=0;i<pa1.getLen();i++){
	cout<<pa1.getElement(i)._x<<"--"<<pa1.getElement(i)._y<<"--"<<pa1.getElement(i)._d<<endl;
}

cout<<"++++++++++++ test copy constructor  +++++++++++++++++++++++"<<endl;
PointArr pa2(pa1);
for (int i=0;i<pa2.getLen();i++){
	cout<<pa2.getElement(i)._x<<"--"<<pa2.getElement(i)._y<<"--"<<pa2.getElement(i)._d<<endl;
}

cout<<"+++++++++++++test operator= ++++++++++++++++++"<<endl;
pa3=pa1;
for (int i=0;i<pa3.getLen();i++){
	cout<<pa3.getElement(i)._x<<"--"<<pa3.getElement(i)._y<<"--"<<pa3.getElement(i)._d<<endl;
}

cout<<"+++++++++++ test  del from back and  begin+++++++++++++++++++++++"<<endl;
pa1.delElementFromBegin();
pa1.delElementFromBack();
for (int i=0;i<pa1.getLen();i++){
	cout<<pa1.getElement(i)._x<<"--"<<pa1.getElement(i)._y<<"--"<<pa1.getElement(i)._d<<endl;
}

cout<<"+++++++++++ test set element[i]    ++++++++++++++++++++++"<<endl;
pa1.setElement(p3,1);
for (int i=0;i<pa1.getLen();i++){
	cout<<pa1.getElement(i)._x<<"--"<<pa1.getElement(i)._y<<"--"<<pa1.getElement(i)._d<<endl;
}

//---------------------end of test-------------------------------------- 




return 0;
}	



