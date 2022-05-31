#if _GLIBCXX_USE_CXX11_ABI
#  define DUAL_ABI cxx11 __attribute__((abi_tag("cxx11")))
#else
#  define DUAL_ABI cxx03
#endif

#include <iostream>
#include "employee.pb.h"

int main() 
{
    std::cout<<"hello";
    monish::Employee emp;
}