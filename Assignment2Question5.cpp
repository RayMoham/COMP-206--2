/* 
 Name: Rayan Kaleem Mohammed
 Athabasca University ID: 3669212
 Description: Shape Contruction project - Creting instances of shapes via coordinate system and facts
 Date: December 10th, 2023
*/

/*
  Documentataion for Assignment 2 - Q5
 
 Program Name: Shape Contruction project

 Program Purpose:
   Demonstrates a series of shapes and their measurements like area, circumference and their data points, bounding box. This catalouge will utilze classes,
   methods, array usage and error handling

 Compile: (assuming MinGW-W64  is running): g++ -o Assignment2Question5 Assignment2Question5.cpp
 Execution (assuming MinGW-W64 is running): .\Assignment2Question5
 
 Notes: Main must return type int
 
 Classes: 
 Point Class - Utilized to create methods for shape manipulation and display - Holds x,y variables for coordinates, show method, add,subtract and length methods for creating bounding box.
 Shape class - Holds the shape chracteriistic methods, display, area, circumference and bounding box 
 Child classes :
 Triangle, Rectangle, Circle -each holds a constructor and their needed elements for creation - like radius, centrepoint, or genral points. - with validity chcek
 They also contain their own ways of calculating circumference, area and bounding box. - They also contain the display which outputs their data sheet.

 Variables:
x and y - holds xand y coordinates.
vertpoints- point array that holds points
validity function : utilizes point class reference to check triangle inequality, paralelism and more.
*/

/*
Test plan layout:
 
Normal case: ( Only 1 case based on no user input):

Here are a selection of shapes : 

Triangle Details:
Verices are:
( 2, 5 ) ( 0, 4 ) ( 2, 1 )
Circumference : 5   Area : 3   Bounding Box : ( 0, 1 ) ( 2, 5 ) ( 2, 1 ) ( 0, 5 )

This is a special case = It is a Square
Rectangle Details:
Verices are: :
( 1, 1 ) ( 3, 1 ) ( 3, 3 ) ( 1, 3 )
Circumference : 8   Area : 4   Bounding Box : ( 1, 1 ) ( 3, 1 ) ( 3, 3 ) ( 1, 3 )

Circle Details:
Center: ( 0, 0 )
Radius : 4   Circumference : 25.1327   Area : 50.2655   Bounding Box : ( -4, -4 ) ( -4, 4 ) ( 4, 4 ) ( 4, -4 )

Rectangle Details:
Verices are: :
( 1, 1 ) ( 5, 1 ) ( 5, 3 ) ( 1, 3 )
Circumference : 12   Area : 8   Bounding Box : ( 1, 1 ) ( 5, 1 ) ( 5, 3 ) ( 1, 3 )

Last Shape is irregular
Invalid Rectangle ! --> it doesn't meet requirments of rectangle

Other cases: Dependant on Creator with different point choice and more creation of shapes.


 Discussion:
	Thi program uses a few classes Point, Shape, and child classes of specific shapes.
	the point class initilizes the x and y values of point aswell as functions to disply contents of each shape
	The Shape class helps with criteria calculations like area, circumference .. etc.
	Each child class contains the error checking based on point and display the content using pointers and arrays when needed.
	The display is constructed with a creation of 5 different shapes and listing it's criteria effectively.
	Since it is only 1 case, there is no user input.
 
*/

#include <iostream>								// initial declarations 
using namespace std;
#include <algorithm>			 // allows uses of std::min and max		
#define _USE_MATH_DEFINES
#include <math.h>		 // math operations needed - (pi)

class Point {	// point class

public: 

double x;		// x and y values for point 
double y;
Point(){}; //default
Point(double xterm, double yterm) : x(xterm), y(yterm){};	// Constructor used for point class

void show() {
	std:: cout << "( " << x << ", " << y << " ) ";	// show method for display
};

Point add( const Point& newpoint) const { 	// const to relate to child shape classes -  end const for const member function so it can be called in main without causing issues
	return Point(x + newpoint.x , y + newpoint.y );	// add method created with Point object return type and use of constructor. (.x and .y is sued to acess x and y cordinates based on private)
};

Point subtract( const Point& newpoint) const  {	// const to relate to child shape classes and end const for const member function so it can be called in main without causing issues
	return Point(x - newpoint.x , y - newpoint.y ); // subtract  method created with Point object return type and use of constructor
};

double length() {				// used for error checking trinagles 
	return std:: sqrt(x*x + y*y);
}

}; 

// shape class - performs basis of set of shapes 
class Shape{
public:

// all are virtual functions as all will get overridden

virtual double circumference(){
	std:: cout << "Print circumference";
	return 0.0;
 };
 
 virtual void display(){
	std::cout << " Shape Details: :"<< std::endl;
 };

 virtual double area(){
	std:: cout << "Print area";
	return 0.0;
 };
 virtual Point* boundingbox(){		// created pointer to point object as coordinates will take points
	std:: cout << "Print bounds";
	return nullptr;		// syntax for pointers if none is found
 };

};

// Hierarchy of shape classes - triangle,  circle and rectangle 

class Triangle: public Shape{

private:
	Point vertpoints[3]; // private point object which hold 3 vertices 

bool validity(const Point& v1, const  Point& v2, const Point& v3){		// chceking validity 
	double x = v1.subtract(v2).length();	 // calculate lengths of triangles side 
	double y = v2.subtract(v3).length();
	double z = v3.subtract(v1).length();

	return ( x + y  > z) &&(x + z > y) && (y + z > x ); // check using trinagle identity
}
public:
// Constructor ( Default and parameters)

Triangle(){};

Triangle( const Point& v1, const  Point& v2, const Point& v3){ // initilizes vertices in array
if(validity(v1, v2, v3)){		// run normally if true 
	vertpoints[0] = v1;
	vertpoints[1] = v2;
	vertpoints[2] = v3;
}else {						// print message otherwise
	std:: cout << " Invalid Triangle creation !";
}
	
};
// functions to override:

// area function
double area(){		// use 0.5 * b *h -> use subtraction method to get lengths
	double b = vertpoints[0].subtract(vertpoints[1]).x; // .x is used to recieve x coordinate
	double h = vertpoints[1].subtract(vertpoints[2]).y; // to get y 
	return 0.5 * std:: abs(b*h);	//abs for absolute value and clean result
} 
double circumference(){		// perimeter x + y + z -> use subtraction method to get lengths
	double x = vertpoints[0].subtract(vertpoints[1]).x; // .x is used to recieve x coordinate
	double y = vertpoints[1].subtract(vertpoints[2]).y; // to get y 
	double z = vertpoints[2].subtract(vertpoints[0]).x; // to get x
	return std:: abs(x) +std:: abs(y) + std:: abs(z);	//abs for absolute value and clean +ve result
} 

void display(){
	std::cout << "Triangle Details: " << std::endl;
	std::cout << "Verices are:" << std::endl;
	for (Point& vertex : vertpoints){		// create for loop to iterate through vertices array of point objects
		vertex.show();
		
	};
	std:: cout << std::endl;
	std:: cout<< "Circumference : " << circumference();
	std:: cout<< "   Area : " << area();
	Point* boxtri = boundingbox(); 	// calling bounding box method so pointer holds allocated array from the bounding box method
	std:: cout<< "   Bounding Box : ";
	for (int k = 0; k < 4; k++){
		boxtri[k].show();	
	}
	std::cout << endl;
	
	
};

Point* boundingbox() {
	Point* boxtriangle = new Point[4];	 // Pointer to point class creating a array of 4 vertices
	
	// since triangle can be done in multiple ways - I will use min and max on the verticies to craete points for the bounding box 
	double a = std::min({vertpoints[0].x, vertpoints[1].x, vertpoints[2].x});
	double b = std::min({vertpoints[0].y, vertpoints[1].y, vertpoints[2].y});
	double c = std::max({vertpoints[0].x, vertpoints[1].x, vertpoints[2].x});
	double d = std::max({vertpoints[0].y, vertpoints[1].y, vertpoints[2].y});

	// now create with created array plot points with min and max
	boxtriangle[0] = Point(a,b);
	boxtriangle[1] = Point(c,d);
	boxtriangle[2] = Point(c,b);
	boxtriangle[3] = Point(a,d);

	return boxtriangle;
};

};

class Rectangle: public Shape{

private:

Point vertpoints[4]; // private point object which hold 4 vertices 

bool validity(const Point& v1, const Point& v2, const Point& v3, const Point& v4){		// chceking validity 
	double x = v1.subtract(v2).length();	 // calculate lengths of triangles side 
	double y = v2.subtract(v3).length();
	double z = v3.subtract(v4).length();
	double v = v4.subtract(v1).length();

	return ( x == z) &&(y ==v); // check parallel sides - to see if rectangle is true
}
bool squarecheck (){
	double x = vertpoints[0].subtract(vertpoints[1]).x; //  .x is used to recieve x coordinate
	double y = vertpoints[1].subtract(vertpoints[2]).y;
	return std:: abs(x) == std:: abs(y);
};

public:
// Constructor ( Default and parameters)

Rectangle(){};

Rectangle(const Point& v1, const Point& v2, const Point& v3, const Point& v4){ // intilizes vertices in array - calling const informs points cannot be modified
if (validity(v1, v2, v3, v4)){
	vertpoints[0] = v1;
	vertpoints[1] = v2;
	vertpoints[2] = v3;
	vertpoints[3] = v4;

	if (squarecheck()){
		std::cout << endl;
		std::cout << "This is a special case = It is a Square";
	};
}	else{
	std::cout << endl;
	std:: cout << "Invalid Rectangle ! --> it doesn't meet requirments of rectangle";
};

};
// functions to overide:

// area function
double area(){		// use b * h -> use subtraction method to get lengths
	double b = vertpoints[0].subtract(vertpoints[1]).x; // .x is used to recieve x coordinate
	double h = vertpoints[1].subtract(vertpoints[2]).y; // to get y 
	return std:: abs(b*h);	//abs for absolute value and clean result
} 
double circumference(){		// perimeter x + y + z -> use subtraction method to get lengths
	double x = vertpoints[0].subtract(vertpoints[1]).x; // .x is used to recieve x coordinate
	double y = vertpoints[1].subtract(vertpoints[2]).y; // to get y 
	
	return (std:: abs(x) + std:: abs(y)) * 2.0;	//abs for absolute value and clean result and multiply by 2 because asumming rectangle is normal 
} 

void display(){
	std::cout << endl;
	std::cout << "Rectangle Details: " << std::endl;
	std::cout << "Verices are: : " << std::endl;
	for (Point& vertex : vertpoints){		// create for loop to iterate through vertices array of point objects
		vertex.show();
	};
	std:: cout << std::endl;
	std:: cout<< "Circumference : " << circumference();
	std:: cout<< "   Area : " << area();
	Point* boxrectangle = boundingbox(); 	// calling bounding box method so pointer holds allocated array from the bounding box method
	std:: cout<< "   Bounding Box : ";
	for (int k = 0; k < 4; k++){
		boxrectangle[k].show();	
	}
	std::cout << endl;
	
	
};

// this method is easier as the bounding box is the rectangle itself 
Point* boundingbox() {
	Point* boxrec = new Point[4];	 // Pointer to point class creating a array of 4 vertices
	for(int k = 0; k < 4; k ++){
		boxrec[k] = vertpoints[k]; // copying coordinates from vertpoints to boxrec array
	}
	return boxrec;
};

};

class circle : public Shape{

private:
	double radius;		// radius of circle 
	Point centrepoi;	// center point of circle

public:	
circle(){};//Default constructor

circle(double rad, const Point& centre): radius(rad), centrepoi(centre){	// parameterized constructor with error handling
	if(rad <= 0.0){	// error if -statement
		std::cout << "Warning: Invalid radius for circle creation" << std:: endl;
	}
}
// now the overidding functions for corrected output:

double circumference(){
	return 2.0 * M_PI * radius;
};

double area(){
	return M_PI * radius * radius;
}

void display() {
	std:: cout << endl;
	std::cout << "Circle Details: " << std::endl;
	std:: cout << "Center: ";
	centrepoi.show();
	std::cout<< endl;
	std:: cout<< "Radius : " << radius;
	std:: cout<< "   Circumference : " << circumference();
	std:: cout<< "   Area : " << area();
	Point* boxcircle = boundingbox(); 	// calling bounding box method so pointer holds allocated array from the bounding box method
	std:: cout<< "   Bounding Box : ";
		for (int k = 0; k < 4; k++){
			boxcircle[k].show();	
	}
	std::cout << endl;
	
}
Point* boundingbox(){		// the bounding box will demonstrate a box lengths of diameter since it will fix exactly around circle
	Point* boxedcircle = new Point[4]; // Pointer to point class creating a array of 4 vertices
	boxedcircle[0] = centrepoi.add(Point(-radius, -radius));
	boxedcircle[1] = centrepoi.add(Point(-radius, radius));
	boxedcircle[2] = centrepoi.add(Point(radius, radius));
	boxedcircle[3] = centrepoi.add(Point(radius, -radius));
	
	return boxedcircle;
}
};

int main(){
std:: cout << "Here are a selection of shapes : " << std::endl;
std:: cout << endl;

// Create 5 instances of shapes 
Triangle triangleshape(Point(2, 5), Point(0, 4), Point(2, 1));
triangleshape.display();

Rectangle sqaureshape(Point(1, 1), Point(3, 1), Point(3, 3), Point(1, 3));
sqaureshape.display();	// square implementation

circle circleshape(4.0, Point(0, 0));
circleshape.display();

Rectangle rectangleshape(Point(1, 1), Point(5, 1), Point(5, 3), Point(1, 3));
rectangleshape.display();
std::cout << endl;

// invalid shape attempt -non rectangle
std::cout << "Last Shape is irregular";
Rectangle fail(Point(1, 1), Point(2, 2), Point(3, 3), Point(1, 3)); 	// It prints the statement

return 0;

}


