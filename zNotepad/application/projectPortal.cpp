#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include "../notepad_proto/users.pb.h"
// #include "../project_proto/projects.pb.h"

using namespace std;
namespace fs = std::filesystem;

void create_directory(string dir_name)
{
    if (!fs::exists(dir_name))
    {
        fs::create_directory(dir_name);
    }
}

void open_project_portal(int s)
{

}