//Header.h
#include <string>
#include <cmath>

namespace parent_namespace //parent namespace
{
    namespace child_namespace //normal namespace
    {
       class quad {public: //class to find roots of quadratic equations
        double roots_of_quadratic(double a, double b, double c){  //function
            double x1, x2;
            double d = b*b - 4*a*c;
            if(d < 0){
                return -1;
            }
            else if(d == 0){
                x1 = -b/(2*a);
                return x1;
            }
            else{
                x1 = (-b + sqrt(d))/(2*a);
                x2 = (-b - sqrt(d))/(2*a);
                return x1;
            }
        }
     };
    }

    inline namespace print_inline //inline namespace (here no class only function)
    {
        std::string Func() { return std::string("Hello from inline namespace"); }
    }
}