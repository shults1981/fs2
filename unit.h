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
	//PointArr();

public:
	
	PointArr();
	PointArr(int Len);
	PointArr(const PointArr &PointSRC);
	~PointArr();
	PointArr & operator=(const PointArr &PointSRC);
	int setElement (const Point &, int index) const;
	int addElementInBack(const Point &PointSRC);
	int delElementFromBack();
	int addElementInBegin(const Point &PointSRC);	
	int delElementFromBegin();
	int getElement(int index,Point &PointDEST) const;
	int delElement(int index);
	int getLen() const;
	int insertElementAfterIndex(int index,Point &PointSRC);

};

//-------------------------------------------------



class Unit
{
	PointArr cord;// coordinates of body parts  
	PointArr  tpa; // coordinates of turning body points
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
