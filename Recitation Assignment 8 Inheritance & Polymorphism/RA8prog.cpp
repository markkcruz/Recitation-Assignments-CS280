#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

//#include "shape.h"     // Shape class definition
//#include "circle.h"    // Circle class definition
//#include "cylinder.h"  // Cylinder class definition
using namespace std;

class Shape {

protected:
    const double PI = 3.14159;
public:

    virtual double getArea() const
    {
        return 0.0;
    };

    virtual double getVolume() const
    {
        return 0.0;
    };

    // pure virtual functions; overridden in derived classes
    virtual string getName() const = 0; // return shape name
    virtual void print() const = 0;     // output shape

}; // end class Shape

class Circle : public Shape {

public:
    // default constructor
    Circle(  double r = 0.0 ) {
        radius = r;
    }

    // set radius
    void setRadius(  double r ) {
        radius = r;
    }

    // return radius
    double getRadius() const {
        return radius;
    }

    // return diameter
    double getDiameter() const {
        return radius * 2;
    }

    // return circumference 2 * pi * r
    double getCircumference() const {
        return 2 * PI * radius;
    }

    // return area a = r^2 * pi
    virtual double getArea() const {
        return radius * radius * PI;
    }

    // return name of shape (i.e., "Circle")
    virtual string getName() const { return "Circle"; }
    // output Circle object data member
    virtual void print() const {
        cout << "Radius is " << getRadius() << " Area is " << getArea() << " and circumference is " << getCircumference() << endl;
    }

protected:
    double radius;  // Circle's radius

}; // end class Circle


class Cylinder : public Circle {

public:

    // default constructor P1 =
    Cylinder( double r = 0.0,  double h = 0.0 ) {
        radius = r;
        height = h;
    }

    // set Cylinder's height
    void setHeight( double h) {
        height = h;
    }

    // return Cylinder's height
    double getHeight() const {
        return height;
    }

    // return Cylinder's area 2 pi r h + (2pi r * r)
    virtual double getArea() const {
        return (2 * PI * radius * height )+ (2 * PI * radius * radius);
    }

    // return Cylinder's volume V = pi * r * r * h
    virtual double getVolume() const {
        return (PI * radius * radius * height);
    }

    // return name of shape (i.e., "Cylinder" )
    virtual string getName() const { return "Cylinder"; }

    // output Cylinder
    virtual void print() const {
        cout << "Radius is " << getRadius() << " and height is " << getHeight() << " Area is " << getArea() << " and volume is " << getVolume() << endl;
    }

private:
    double height;  // Cylinder's height

}; // end class Cylinder










// Driver, do not touch
int main()
{
    vector< Shape * > shapeVector( 4 );

    cout << fixed << setprecision( 2 );

    Circle circle1( 3.5 ), circle2(7.5);           // create a Circles objects
    //create two Cylinder objects
    Cylinder cylinder1(4, 6), cylinder2(8, 10);

    shapeVector[ 0 ] = &circle1;

    shapeVector[ 1 ] = & cylinder1;

    shapeVector[ 2 ] = &cylinder2;

    shapeVector[ 3 ] = &circle2;

    // print the shape name, attributes, area and volume of each object
    for ( int i = 0; i < shapeVector.size(); i++ )
    {
        cout << "Shape " << i+1 << " " << shapeVector[i]->getName() << ":"<<endl;

        shapeVector[i]->print();

        cout << endl;
    }
    return 0;
}
