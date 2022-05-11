#include <iostream>
#include <string>
#include <exception>

int main(){
    try{
        try{
            throw std::runtime_error("Invalid argument");
        }
        catch(std::runtime_error &e){
            std::cout << e.what() << std::endl;
            throw;
        }
    }
    catch(std::invalid_argument &e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    // catch(std::runtime_error &e){
    //     std::cout << e.what() << std::endl;
    // }
    catch(...){
        std::cout << "Unknown error" << std::endl;
    }
    return 0;
}