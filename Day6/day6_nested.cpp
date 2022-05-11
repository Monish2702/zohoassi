#include <iostream>
#include <string>
#include <exception>

int main(){
    /*Outer try block*/
    try{
        throw std::runtime_error("\nRuntime error outer try block");
        /*Inner try block*/
        try{
            throw std::runtime_error("Runtime error inner try block");
            throw 20;
        }  /*Inner catch block*/
        catch(std::runtime_error &e){
            std::cout << e.what() << std::endl;
            std::cout<<"Rethrowing an already catched exception\n"<<std::endl;
            throw;
        }
    }
    /*Outer catch block-1*/
    catch(std::invalid_argument &e){
        std::cout << "Invalid argument: " << e.what() << std::endl;
    } /*Outer catch block-2*/
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    } /*Outer catch block-3*/
    catch(...){
        std::cout << "Unknown error" << std::endl;
    }
    return 0;
}