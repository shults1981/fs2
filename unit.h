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


//------------------Class PointArr----------------------------------------

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

//------------------ Class Unit  --------------------------------

class Unit
{
protected:
	PointArr *BodyCords;// coordinates of body parts  i
	PointArr  *BodyTPA; // coordinates of turning body points

private:
	Unit();
	Unit(Unit&);

public:
	Unit(int UnitLen);
	~Unit();
	virtual int addNewElementInUnitBody(const Point &PointSRC);
	virtual	int addNewElementInBodyTPA(const Point &PointSRC);
	virtual	int delElementFromBackOfUnitBody();
	virtual	int delElementFromBeginOfUnitBody();
	virtual	int delElementFromBodyTPA();	
	virtual	int getBodyLen();
	virtual	int getBodyTPANum();	
	virtual	int getBodyCords(int BodyPartIndex,Point &PointDEST);
	virtual	int getBodyTPA(int TPAIndex,Point &PointDEST);

};


//-----------------Class Snake --------------------------


class Snake:public Unit
{

public:
	Snake();
	int addNewElementInUnitBody(const Point &PointSRC);
	int delElementFromBeginOfUnitBody ();
};


class Rabbit:public Unit
{

public:
	Rabbit();
	int addNewElementInUnitBody(const Point &PointSRC);
	int addNewElementInBodyTPA(const Point &PointSRC);
	int delElementFromBackOfUnitBody();
	int delElementFromBeginOfUnitBody();
	int delElementFromBodyTPA();	
	int getBodyLen();
	int getBodyTPANum();	
	int getBodyCords(int BodyPartIndex,Point &PointDEST);
	int getBodyTPA(int TPAIndex,Point &PointDEST);

};


#endif

