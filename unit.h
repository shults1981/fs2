//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.h
//++++++++++++++++++++++
//+++++++++++++++++++++


#ifndef UNIT_H
#define UNIT_H

struct point
{
	int _x; //cord x
	int _y; //cord y
	int _d; //moving direction flag of the point
};

class unit
{
	point *cord;
	point *tpa;
	int len;
	int num_tpa;

public:
	unit();
	~unit();
}







#endif 
