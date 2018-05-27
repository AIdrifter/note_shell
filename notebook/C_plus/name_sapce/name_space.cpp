/*
 *  #include <iostream.h> standard version doesn't define *.h , this is older version
 *
 *  C++ header transform to C header
 *   math.h -> cmath
 *   string.h -> cstring
 */
#include <iostream>
#include "Point2D.h"

using namespace std; // C++ standard lib
using d2d::Point2D;  // using namespace d2d;

/*
 *  undefined namespace
 *  All identifier only can be used in this file
 */

namespace {
    int i, j, k;

    class Undefined_Point3D {
    public:
        Undefined_Point3D() {
            _x = 0;
            _y = 0;
            _z = 0;
        }

        Undefined_Point3D(int x, int y, int z) : _x(x), _y(y), _z(z) {
        }

        int x() {return _x;}
        int y() {return _y;}
        int z() {return _z;}

    private:
        int _x;
        int _y;
        int _z;
    };
};


int main()
{
    /*
     *  C-out
     *    1. iostream object
     *    2. << operator
     */
    cout << "Hello! World!\n";
    cout << "Welcome to C++!\n";


    /* How to use name space */
    Point2D P1(10,10);
    cout << "(x , y) : ("
         << P1.x() << ", "
         << P1.y() << ")"
         << endl;

    /*
     * check retrun type with echo \$?
     */
    return 0;
}
