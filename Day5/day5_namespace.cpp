#include "day5_header.h"
#include <string>
#include <iostream>
using namespace std;

class class_to_import_namespace { public:

    void root_display() {
        namespace p=parent_namespace; //namespace aliasing or using namespace Test;
        p::child_namespace::quad q;

        roots var;
        var = q.roots_of_quadratic(1, -6, 5); // x^2 - 6x + 5 
        if(var.x == true) {
            cout << "Roots are real and they are :" << endl;
            cout << "x1 = " << var.x1 << endl;
            cout << "x2 = " << var.x2 << endl;
        }
        else {
            cout << "Roots are imaginary" << endl;
        }
    
        cout << p::Func() << endl; //Hello from new
    }
};

int main()
{
    class_to_import_namespace tin;
    tin.root_display();
    return 0;
}