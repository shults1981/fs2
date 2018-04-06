//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.cpp
//+++++++++++++++++++++
//+++++++++++++++++++++


#include "unit.h"
#include <stddef.h>

//-------------------------------------
//-----------------methods of class PointArr 

PointArr::PointArr(int Len)
{
	arrLen=Len;
	pArr=new Point [arrLen];
	if (pArr){
		for(int i=0;i<Len;i++){
			pArr[i]._x=0;
			pArr[i]._y=0;
			pArr[i]._d=0;
		}
	}
}

int PointArr::addElementInBack(const Point &PointSRC)
{
	Point *tVar1,*tVar2;
	arrLen++;
	tVar1=new Point[arrLen];
	if (tVar1){
		if (pArr!=NULL){
			for(int i=0;i<(arrLen-1);i++){
				tVar1[i]._x=pArr[i]._x;
				tVar1[i]._y=pArr[i]._y;
				tVar1[i]._d=pArr[i]._d;
			}
			tVar1[arrLen-1]._x=PointSRC._x;
			tVar1[arrLen-1]._y=PointSRC._y;
			tVar1[arrLen-1]._d=PointSRC._d;		
		}
		else {
			tVar1->_x=PointSRC._x;
			tVar1->_y=PointSRC._y;
			tVar1->_d=PointSRC._d;
		}

		tVar2=pArr;
		pArr=tVar1;
		delete tVar2;
		return 1;
	}
	else
		return 0;

}

int PointArr::delElementFromBack()
{
	Point *tVar1, *tVar2;
	arrLen--;
		
	if(arrLen!=0){
		tVar1=new Point[arrLen];
		if (tVar1){
			for(int i=0;i<(arrLen-1);i++){
				tVar1[i]._x=pArr[i]._x;
				tVar1[i]._y=pArr[i]._y;
				tVar1[i]._d=pArr[i]._d;
			}
			tVar2=pArr;
			pArr=tVar1;
		}
		else
		   return 0;
	} 
			
	else {
		tVar1=pArr;
		pArr=NULL;
	}
	
	delete tVar1;
	return 1;
}





//---------------------------------------

//----------------------methods of class Unit


Unit::Unit(int UnitLen)
{

	len=UnitLen;
	num_tpa=0;
	cord= new Point*[len];
	for (int i=0;i<len;i++)
		cord[i]=new Point;	

	tpa= NULL;
	
}

Unit::~Unit()
{

	for (int i=0;i<len;i++)
		delete cord[i];
	delete []cord;

	if (tpa){
		for (int i=0;i<num_tpa;i++)
		delete tpa[i];
	}
	delete []tpa;

}

void Unit::addNewElementInBackOfUnitBody(Point &source)
{
	Point **tVar1,**tVar2;
	len++;
	tVar1=new Point*;
	for(int i=0; i<len-1; i++){
		tVar1[i]=new Point;
	}





}

void Unit::delElementFromBackOfUnitBody()
{


}

void Unit::delElementFromBeginOfUnitBody()
{



}








