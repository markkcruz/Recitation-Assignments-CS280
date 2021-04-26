#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "shape.h"     // Shape class definition
#include "circle.h"    // Circle class definition
#include "cylinder.h"  // Cylinder class definition
using namespace std;

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
