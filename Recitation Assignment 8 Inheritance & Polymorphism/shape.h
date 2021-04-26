// shape.h
// Shape abstract base class definition.
#ifndef SHAPE_H
#define SHAPE_H

#include <string>  

using std::string;

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

#endif


