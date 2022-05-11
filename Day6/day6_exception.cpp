#include <iostream>
#include <string>
#include <exception>
class user_exception : public std::exception
{
    const char *msg;

public:
    user_exception(const char *s) : msg(s) {}
    virtual const char *what() const throw()
    {
        return msg;
    }
};

int main()
{
    int numerator, denominator;
    long MEMORY_SIZE = 0x88ffffff;

    // 1) Division by zero
    std::cout << "\n---------------- 1)Division by zero ----------------\n";
    std::cout << "Enter numerator: ";
    std::cin >> numerator;
    std::cout << std::endl
              << "Enter denominator: ";
    std::cin >> denominator;
    try
    {
        if (denominator == 0)
        {
            throw std::runtime_error("\nInvalid division");
        }
        else
        {
            std::cout << numerator / denominator << std::endl;
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 2) Creation of heap memory variable
    std::cout << "\n---------------- 2)Creation of heap memory variable ----------------\n";
    try
    {
        int *ptr = new int[MEMORY_SIZE];
        std::cout << "Memory is allocated Successfully" << std::endl;
        delete[] ptr;
    }
    catch (const std::bad_alloc &e)
    {
        std::cout << "Memory is compromised: " << e.what() << std::endl;
    }

    // 3) String parsed to a numeric variable
    std::cout << "\n---------------- 3)String parsed to a numeric variable ----------------\n";
    try
    {
        int x;
        std::string str2;
        std::cout << "Enter :";
        std::cin >> str2;
        x = std::stoi(str2);
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "Invalid argument: " << e.what() << std::endl;
    }
    // Other way
    //      if(std::cin.fail()) {
    //          throw std::runtime_error("\nInvalid input");
    //      }
    //      std::cout << "Number is: " << str << std::endl;
    //  }
    //  catch (std::runtime_error &e) {
    //      std::cout << e.what() << std::endl;
    //  }

    // 4) Accessing an invalid index in a string
    std::cout << "\n---------------- 4)Accessing an invalid index in a string ----------------\n";
    try
    {
        std::string s;
        std::cout << "Enter a string: ";
        std::cin >> s;
        std::cout << "Enter the index: " << std::endl;
        int i;
        std::cin >> i;
        if (i > s.length() || i < 0)
        {
            throw std::runtime_error("\nInvalid index");
        }
        else
        {
            std::cout << "Character at index " << i << " is: " << s[i] << std::endl;
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 5) Accessing an invalid index in a array
    std::cout << "\n---------------- 5)Accessing an invalid index in a array ----------------\n";
    try
    {
        int n;
        std::cout << "Enter the size of array: ";
        std::cin >> n;
        int *arr = new int[n];
        std::cout << "Enter the elements: " << std::endl;
        for (int i = 0; i < n; i++)
        {
            std::cin >> arr[i];
        }
        std::cout << "Enter the index: " << std::endl;
        int index;
        std::cin >> index;
        if (index > n || index < 0)
        {
            throw std::runtime_error("\nInvalid index");
        }
        else
        {
            std::cout << "Element at index " << index << " is: " << arr[index] << std::endl;
        }
    }
    catch (std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 6)user defined exception
    std::cout << "\n---------------- 6)user defined exception ----------------\n";
    try
    {
        int height; // feet
        std::cout << "Enter height in feet: ";
        std::cin >> height;
        if (height > 8 || height < 0)
            throw user_exception("\nInvalid height");
    }
    catch (user_exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    // 7) Other exception
    std::cout << "\n---------------- 7)Other exception ----------------\n";
    try
    {
        throw std::runtime_error("\nInvalid input");
    }
    catch (int error)
    {
        std::cout << "Error: " << error << std::endl;
    }
    catch (...)
    {
        std::cout << "Exception encountered" << std::endl;
    }

    std::cout << "\n***************************************************************************************" << std::endl;
    std::cout << "Exception handling accomplished" << std::endl;
    std::cout << "***************************************************************************************" << std::endl;
    return 0;
}