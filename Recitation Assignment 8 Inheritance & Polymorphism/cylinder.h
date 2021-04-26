// Cylinder class inherits from class Circle.
#ifndef CYLINDER_H
#define CYLINDER_H

#include "circle.h"  // Circle class definition

class Cylinder : public Circle {

public:

   // default constructor
   Cylinder( double = 0.0, double = 0.0 ); 
      
   void setHeight( double );  // set Cylinder's height
   double getHeight() const;  // return Cylinder's height 

   virtual double getArea() const; // return Cylinder's area
   virtual double getVolume() const; // return Cylinder's volume
   
   // return name of shape (i.e., "Cylinder" )
   virtual string getName() const;

   virtual void print() const;  // output Cylinder

private:
   double height;  // Cylinder's height

}; // end class Cylinder

#endif


