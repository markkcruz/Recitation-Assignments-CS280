// Circle class 
#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"  // shape class definition

class Circle : public Shape {

public:

   // default constructor
   Circle( double = 0.0 );  

   void setRadius( double );   // set radius
   double getRadius() const;   // return radius

   double getDiameter() const;       // return diameter
   double getCircumference() const;  // return circumference
   virtual double getArea() const;   // return area

   // return name of shape (i.e., "Circle")
   virtual string getName() const;
   // output Circle object data member
   virtual void print() const;  

private: 
   double radius;  // Circle's radius

}; // end class Circle

#endif 


