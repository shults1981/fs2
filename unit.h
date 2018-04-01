//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.h
//++++++++++++++++++++++
//+++++++++++++++++++++


#ifndef UNIT_H
#define UNIT_H

struct Point
{
	int _x; //cord x
	int _y; //cord y
	int _d; //moving direction flag of the point
};

class Unit
{
	Point **cord;// coordinates of body parts  
	Point **tpa; // coordinates of turning body points
	int len;// leight of body
	int num_tpa; // number of turning poins  


private:
	Unit();
	Unit(Unit&);


public:
	Unit(int UnitLen);
	~Unit();
};







#endif 
