//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.cpp
//+++++++++++++++++++++
//+++++++++++++++++++++


#include "unit.h"
#include <stddef.h>


Unit::Unit(int UnitLen)
{

	len=UnitLen;
	num_tpa=0;
	cord= new Point*;
	for (int i=0;i<len;i++)
		cord[i]=new Point;	

	tpa= NULL;
	
}

Unit::~Unit()
{
	for (int i=0;i<len;i++)
		delete cord[i];
	delete cord;

	if (tpa){
		for (int i=0;i<num_tpa;i++)
		delete tpa[i];
	}
	delete tpa;
}








