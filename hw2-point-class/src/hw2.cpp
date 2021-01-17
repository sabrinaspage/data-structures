#ifndef __HW2_CPP__
#define __HW2_CPP__
#include "hw2.h"
using namespace std;
// Put your functions/prototype here

//Default constructor, all set to 0
Point::Point(){
	x=0;
	y=0;
	z=0;
}

//sets private points to have those from the parameter, from user input
Point::Point(double inX, double inY, double inZ){
	x = inX;
	y = inY;
	z = inZ;
}

//copy constructor
Point::Point(const Point& inPt){
	x = inPt.getX();
	y = inPt.getY();
	z = inPt.getZ();
}

//Return x, y, or z from private member, based on point.
double Point::getX() const{return x;}
double Point::getY() const{return y;}
double Point::getZ() const{return z;}

//Set functions from user input
void Point::setX(double inX){x = inX;}
void Point::setY(double inY){y = inY;}
void Point::setZ(double inZ){z = inZ;}
void Point::setXY(double inX, double inY){x = inX; y = inY;}
void Point::setXYZ(double inX, double inY, double inZ){x = inX; y = inY; z = inZ;}

void Point::print(){
	//cout << printf("(%lf, %lf, %lf)", x, y, z) << endl;
	cout << "(" << x << ", "<< y << ", "<< z << ")" << endl;
	return;
}

//return distance between origin and the point
double Point::distance(){
	double xsum = (x+0);
	double ysum = (y+0);
	double zsum = (z+0);
	/*referring to the formula I found on Google...*/
	//
	double distance = sqrt(pow(xsum, 2) + pow(ysum, 2) + pow(zsum,2));
	return distance;
}

//return distance between pt2 and the point
double Point::distance(const Point& pt2) const{
	//if p1 calls it, then it has to call pt2 afterwards
	//but how to solve overloading function?!? find out next time :3
	double xDiff= pt2.getX() - x;
	double yDIff= pt2.getY() - y;
	double zDiff= pt2.getZ() - z;

	double distance = sqrt(pow(xDiff,2)+pow(yDiff,2)+pow(zDiff,2));
	return distance;
}
//if point is the origin, return true
bool Point::origin(){
	if((x == 0.0) && (y == 0.0) && (z == 0)){
		return true;
	} else {
		return false;
	}
}

/*return true if pt2 is on the same line as origin and the point;
return false if not in line; return false if origin and p1 don't make a line*/
bool Point::line(Point p2){
	//some points on the line btwn origin and the line
	//this is for pt1, the one that calls this function
	double xsumO = getX() + 0;
	double ysumO = getY() + 0;
	double zsumO = getZ() + 0;
	//this is for p2, the point being called and compared
	double xsump2 = p2.getX() + 0;
	double ysump2 = p2.getY() + 0;
	double zsump2 = p2.getZ() + 0;

	//so compare the distances
	double distance1 = sqrt(pow(xsumO,2)+pow(ysumO,2)+pow(zsumO,2));
	double distance2 = sqrt(pow(xsump2,2)+pow(ysump2,2)+pow(zsump2,2));
	//create points which compare their coordinates with the others' coordinates
	//basically, x * 1/distance means there is at least one coordinate in distance, and that is x.
	Point st1(xsumO/distance1,ysumO/distance1,zsumO/distance1);
	Point st2(xsump2/distance2,ysump2/distance2,zsump2/distance2);
	//compare the points with eachother
	return (st1.getX() == st2.getY() && st1.getY() == st2.getY() && st1.getZ() == st2.getZ());
}

//return a point
Point Point::cross(Point pt2){
	//cross product is vectors a x b
	//general formula seems to be:
	//well we have ax, ay, az
	//we also have bx, by, bz
	//so as a result we have axbx - axbz -aybx + aybz + azbx-azby
	//create an identifier

	double a1 = getX();
	double a2 = getY();
	double a3 = getZ();

	double b1 = pt2.getX();
	double b2 = pt2.getY();
	double b3 = pt2.getZ();
//create the formulas. the cross product rule involves i, j, k in the general format...
	double i = a2*b3 - a3*b2;
	double j = a3*b1 - a1*b3;
	double k = a1*b2 - a2*b1;

	//if we have a point as the function, we return it.
	Point crosspoint(i,j,k);
	return crosspoint; 
}

//Postcondition: sum of p1 and p2 is returned
Point operator+(const Point& pt1, const Point& pt2){
	double xsum, ysum;
	xsum=(pt1.getX()+ pt2.getX());
	ysum=(pt1.getY() + pt2.getY());
	Point sum(xsum, ysum);
	return sum;
}
//Postcondition: the different between pt1 and pt2. results may be negative
Point operator-(const Point& pt1, const Point& pt2){
	double xdiff, ydiff;
	xdiff=(pt1.getX()-pt2.getX());
	ydiff=(pt1.getY()-pt2.getY());
	Point difference(xdiff, ydiff);
	return difference;
}

ostream& operator<<(ostream& outs, const Point& source){
	outs << source.getX() << source.getY() << source.getZ();
	return outs;
}

bool plane(const Point pts[], const Point& target){
	//array of three Point objects
	Point uVec = pts[1]-pts[0]; //0 is our first point
	Point vVec = pts[2]-pts[0]; //2 is out third point

	bool plane;
	Point UcrossV = uVec.cross(vVec);
	for(size_t i = 0; i < 3; i++){
		pts[i].getX();
		pts[i].getY();
		pts[i].getZ();

		double plane =
	}

	return plane = false;
}

bool square(const Point pts[], const size_t size);

Point centroid(const Point pts[], const size_t size){
	if(size == 0){
		Point origin(0,0,0);
		return origin;
	}

	double midX = 0, midY = 0, midZ = 0;

	for(size_t i = 0; i < size; i++){
		midX += pts[i].getX();
		midY += pts[i].getY();
		midZ += pts[i].getZ();
	}

	Point center(midX/size, midY/size, midZ/size);
	return center;
}

#endif