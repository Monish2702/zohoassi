#include "day5_header.h"
#include <string>
#include <iostream>
using namespace std;

class class_to_import_namespace { public:

    void root_display() {

    namespace p=parent_namespace; //namespace aliasing or using namespace Test;
    p::child_namespace::quad r;

    double root = r.roots_of_quadratic(1, -6, 5); // x^2 - 6x + 5 
    cout <<"The root of the given x^2 - 6x + 5 equation is: "<< root << endl;

    cout << p::Func() << endl; //Hello from new
    }
};

int main()
{
    class_to_import_namespace tin;
    tin.root_display();
    return 0;
}