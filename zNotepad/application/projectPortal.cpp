#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "../notepad_proto/users.pb.h"
using namespace std;
namespace fs = std::filesystem;

void create_directory(string dir_name)
{
    if (!fs::exists(dir_name))
    {
        fs::create_directory(dir_name);
    }
}