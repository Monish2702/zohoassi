#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <filesystem>
#include "../notepad_proto/users.pb.h"
#include "../project_proto/projects.pb.h"
//------------------------------------------------------------------------------------------------------

using std::filesystem::directory_iterator;
using namespace std;
namespace fs = std::filesystem;
//------------------------------------------------------------------------------------------------------

void create_directory(string dir_name)
{
    if (!fs::exists("../application/user_projects/" + dir_name))
    {
        fs::create_directory("../application/user_projects/" + dir_name);
    }
}
//------------------------------------------------------------------------------------------------------

void open_project_portal(int s, string uname)
{
    notepad_projects::project p;
    bool ch;
    cout << "0-Create new file\n1-Open an existing file:" << endl;
    cin >> ch;
    switch (ch) // outer switch starts
    {
    case 0: // if(!ch)
    {
        cout << "Enter your new file name:" << endl;
        string filename;
        cin >> filename;
        // string filename("output.txt");
        ofstream output_fstream;
        output_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::out);
        if (!output_fstream.is_open())
        {
            cout << "Failed to open " << filename << '\n';
        }
        else
        {
            // file operations
            p.set_user_id(s);
            p.set_project_id(rand());
            p.set_project_name(filename);
            output_fstream << p.SerializeAsString();
        }
        output_fstream.close();
        cout << p.user_id() << " " << p.project_id() << " " << p.project_name() << endl;
        break;
    }
    case 1: //edit existing files
    {
        // displaying all the files that this particular user has
        string path = "../application/user_projects/" + uname + "/"; // to display the project list
        for (const auto &file : directory_iterator(path))
            cout << file.path() << endl;
        
        // asking user which file to open
        cout << "Enter the file name to open: ";
        string filename;
        cin >> filename;
        ifstream input_fstream;
        input_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::in);
        if (!input_fstream.is_open())
        {
            cout << "Failed to open " << filename << '\n';
        }
        else
        {
            // file operations
            p.ParseFromIstream(&input_fstream);
            cout << p.user_id() << " " << p.project_id() << " " << p.project_name() << endl;
        }
        ofstream output_fstream;
        output_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::out);
        if (!output_fstream.is_open())
        {
            cout << "Failed to open " << filename << '\n';
        }
        else
        {
            // now file is open and asking user what operation to perform on the file
            bool flag = true;
            while (flag)
            {
                cout << "--------\n0-Add text\n1-Update text\n2-Remove\n3-Display\n4-Exit this file operations\n--------" << endl;
                int operation_choice;
                cin >> operation_choice;
                // input_fstream.close();
                switch (operation_choice) // inner switch inside of case 1 of outer switch
                {
                case 0:
                {
                    // get lines from user until they enter STOP serialize it and put into file
                    string line; bool inner_flag = true;  // inner flag to break out of while loop
                    cout << "Enter text to add to file: " << endl;
                    while(inner_flag)
                    {
                        
                        getline(cin>>ws, line);
                        if (line == "STOP")
                        {
                            inner_flag = false;
                            break;
                        }
                        notepad_projects::contents *pcontent = p.add_contents();
                        pcontent->set_content_line(line);
                    }
                    output_fstream << p.SerializeAsString();
                    break;
                }
                case 1:
                {
                    // to update any line of the file using proto content
                    // output_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::in);
                    // output_fstream.close();
                    break;
                }
                case 2:
                {
                    // to remove any line of the file
                    //  cout << "Enter the line number to remove: ";
                    //  int line_number;
                    //  cin >> line_number;
                    //  input_fstream.seekg(0, input_fstream.beg);
                    // output_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::app);
                    // output_fstream.close();
                    break;
                }
                case 3:
                {
                    cout << "User ID: " << p.user_id() << endl
                         << "Project ID: " << p.project_id() << endl
                         << "Project Name: " << p.project_name() << endl;
                    for (int i = 0; i < p.contents_size(); i++)
                    {
                        cout << i + 1 << ". " << p.contents(i).content_line() << endl;
                    }
                    // 
                    break;
                }
                case 4:
                {
                    // close the file and exit
                    // output_fstream.close();
                    flag = false;
                    break;
                }
                }
                // output_fstream.open("../application/user_projects/" + uname + "/" + filename, std::ios_base::out);
                // p.SerializeToOstream(&output_fstream);
                output_fstream.close();
                
                input_fstream.close();
            }
        }
        break;
    }
    }
}