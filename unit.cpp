//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.cpp
//+++++++++++++++++++++
//+++++++++++++++++++++

#include <stdlib.h>
#include "unit.h"
#include <stddef.h>

//-------------------------------------
//-----------------methods of class PointArr 

PointArr::PointArr(int Len)
{
	arrLen=Len;
	pArr=new Point [arrLen];
	if (pArr){
		for(int i=0;i<arrLen;i++){
			pArr[i]._x=0;
			pArr[i]._y=0;
			pArr[i]._d=0;
		}
	}
}

PointArr::PointArr(const PointArr &pa)
{
	Point tVar;
	arrLen=pa.arrLen;
	pArr=new Point[arrLen];
	if (pArr){
		for (int i=0;i<arrLen;i++){
			if(pa.getElement(i,tVar)){
				pArr[i]._x=tVar._x;
				pArr[i]._y=tVar._y;
				pArr[i]._d=tVar._d;
			}
		}
	}
}

PointArr & PointArr::operator= (const PointArr & paSRC)
{
	Point *tVar1,*tVar2;
	Point tVar3;
	if (this==&paSRC)
		return *this;
	else{
		tVar1=new Point[paSRC.getLen()];
		if (tVar1){
			for(int i=0; i<paSRC.getLen();i++){
				if(paSRC.getElement(i,tVar3)){
					tVar1[i]._x=tVar3._x;
					tVar1[i]._y=tVar3._y;
					tVar1[i]._d=tVar3._d;
				}
			}
		}

		tVar2=tVar1;
		tVar1=this->pArr;
		this->pArr=tVar2;
		this->arrLen=paSRC.getLen();

		delete []tVar1;
		return *this;
	}
}


PointArr::~PointArr()
{
	if (pArr)
		delete []pArr;

}


int PointArr::setElement(const Point & PointSRC, int index) const
{
	if ((index>=0)&&(index<arrLen)){
		pArr[index]._x=PointSRC._x;
		pArr[index]._y=PointSRC._y;	
		pArr[index]._d=PointSRC._d;
		return 1;
	}
	else
		return 0;


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
		delete []tVar2;
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
		tVar2=pArr;
		pArr=NULL;
	}
	
	delete []tVar2;
	return 1;
}

int PointArr::addElementInBegin(const Point &PointSRC)
{
	Point *tVar1,*tVar2;
	arrLen++;
	tVar1=new Point[arrLen];
	if (tVar1){
		if (pArr!=NULL){
			tVar1[0]._x=PointSRC._x;
			tVar1[0]._y=PointSRC._y;
			tVar1[0]._d=PointSRC._d;
			for(int i=1;i<arrLen;i++){
				tVar1[i]._x=pArr[i-1]._x;
				tVar1[i]._y=pArr[i-1]._y;
				tVar1[i]._d=pArr[i-1]._d;
			}
		}
		else {
			tVar1->_x=PointSRC._x;
			tVar1->_y=PointSRC._y;
			tVar1->_d=PointSRC._d;
		}

		tVar2=pArr;
		pArr=tVar1;
		delete []tVar2;
		return 1;
	}
	else
		return 0;

}

int PointArr::delElementFromBegin()
{
	Point *tVar1, *tVar2;
	arrLen--;
		
	if(arrLen!=0){
		tVar1=new Point[arrLen];
		if (tVar1){
		for(int i=0;i<(arrLen);i++){
				tVar1[i]._x=pArr[i+1]._x;
				tVar1[i]._y=pArr[i+1]._y;
				tVar1[i]._d=pArr[i+1]._d;
			}
			tVar2=pArr;
			pArr=tVar1;
		}
		else
		   return 0;
	} 
			
	else {
		tVar2=pArr;
		pArr=NULL;
	}
	
	delete []tVar2;
	return 1;

}


int  PointArr::getElement(int index, Point & pointDEST) const
{
	
	if ((index>=0)&&(index<arrLen)){
		pointDEST._x=pArr[index]._x;
		pointDEST._y=pArr[index]._y;
		pointDEST._d=pArr[index]._d;
		return 1;
	}
	else 
		return 0;
}

int PointArr::delElement(int index)
{
	Point *tVar1,*tVar2;
	if ((index>=0)&&index<arrLen){
		tVar1=new Point[arrLen-1];
			if (tVar1){
				for(int i=0;i<index;i++){
					tVar1[i]._x=pArr[i]._x;
					tVar1[i]._y=pArr[i]._y;
					tVar1[i]._d=pArr[i]._d;
				}
				for (int i=index;i<arrLen-1;i++){
					tVar1[i]._x=pArr[i+1]._x;
					tVar1[i]._y=pArr[i+1]._y;
					tVar1[i]._d=pArr[i+1]._d;
				}
				tVar2=pArr;
				pArr=tVar1;
				arrLen--;
				delete []tVar2;
			}
			else 
				return 0;
	}
	else
		return 0;	

}


int PointArr::getLen() const
{
	return arrLen;
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
	Point **tVar1,*tVar2;
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








