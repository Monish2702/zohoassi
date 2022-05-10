//day5_header.h
#include <string>
#include <cmath>
struct roots{
    double x1,x2;
    bool x;
};

namespace parent_namespace //parent namespace
{
    namespace child_namespace //normal namespace
    {
       class quad {public: //class to find roots of quadratic equations
       roots r;
        roots roots_of_quadratic(double a, double b, double c){  //function
            double x1, x2;
            double d = b*b - 4*a*c;
            if(d < 0){
                r.x = false;
                return r;
            }
            else if(d == 0){
                r.x1 = -b/(2*a);
                r.x2 = -b/(2*a);
                return r;
            }
            else{
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