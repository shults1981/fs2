//++++++++++++++++++++++
//++++++++++++++++++++++
//   unit.h
//++++++++++++++++++++++
//+++++++++++++++++++++


#ifndef UNIT_H
#define UNIT_H
//
struct Point
{
	int _x; //cord x
	int _y; //cord y
	int _d; //moving direction flag of the point
};


//----------------------------------------------------------

class PointArr
{
	Point *pArr;
	int arrLen;
private:
	PointArr();

public:
	
	PointArr(int Len);
	~PointArr();
	int addElementInBack(const Point &);
	int delElementFromBack();
	int addEllementInBegin(const Point &);	
	int delElementFromBegin();

};

//-------------------------------------------------



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
	void addNewElementInBackOfUnitBody(Point &source);
	void delElementFromBackOfUnitBody();
	void delElementFromBeginOfUnitBody();
	
	

};







#endif 
