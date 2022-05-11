#include "day5_header.h" //include header file
#include <iostream>
// using namespace std;

class class_to_import_namespace
{
public:
    // member function to import namespace
    void root_display()
    {
        namespace p = parent_namespace; // namespace aliasing or using namespace Test;
        p::child_namespace::quad q;     // instanciating class from namespace

        roots var;
        var = q.roots_of_quadratic(1, -6, 5); // x^2 - 6x + 5
        if (var.x == true)
        { // roots are non imaginary
            std::cout << "Roots are real and they are :" << std::endl;
            std::cout << "x1 = " << var.x1 << std::endl;
            std::cout << "x2 = " << var.x2 << std::endl;
        }
        else
        {
            std::cout << "Roots are imaginary" << std::endl;
        }

        std::cout << p::Func() << std::endl; // to print hello from inline namespace
    }
};

int main()
{
    class_to_import_namespace tin; // instanciating class_to_import_namespace
    tin.root_display();            // calling member function
    return 0;
}