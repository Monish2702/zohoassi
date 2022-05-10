//day5_header.h
#include <string>
#include <cmath>
struct roots{
    double x1,x2; //to store roots
    bool x; //to know if roots are real or imaginary
};

namespace parent_namespace //parent namespace
{
    namespace child_namespace //normal namespace
    {
       class quad {public: //class to find roots of quadratic equations
       roots r; //struct to store roots
        roots roots_of_quadratic(double a, double b, double c){  //function
            double x1, x2; //to store roots here
            double d = b*b - 4*a*c; //discriminant
            if(d < 0){ //roots are imaginary
                r.x = false;
                return r;
            }
            else if(d == 0){ //roots are real and equal
                r.x1 = -b/(2*a);
                r.x2 = -b/(2*a);
                return r;
            }
            else{ //roots are imaginary and distinct
                r.x1 = (-b + sqrt(d))/(2*a);
                r.x2 = (-b - sqrt(d))/(2*a);
                return r;
            }
        }
     };
    }

    inline namespace print_inline //inline namespace (here no class only function)
    {
        std::string Func() { return std::string("\nHello from inline namespace"); }
    }
}