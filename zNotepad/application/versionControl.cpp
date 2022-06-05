#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <iterator>
#include <filesystem>
#include "../notepad_proto/users.pb.h"
#include "../project_proto/projects.pb.h"
#include "../version_proto/versions.pb.h"
using namespace std;

void save_version(string filename, notepad_projects::project &p, notepad_versions::version_list &v)
{
    ifstream version_fstream;
    // notepad_versions::version_list v;
    version_fstream.open("../application/user_projects/version_files/" + filename + "_versions", ios::in | ios::binary);

    if (!version_fstream.is_open())
    {
        cout << "Failed to open " << filename << '\n';
    }
    else
    {
        // file operations
        cout << "Version File opened successfully" << endl;
        v.ParseFromIstream(&version_fstream);
    }

    cout << "~~~~~~~~~~~~~~ " << v.project_id() << " ~~~~~~~~" << endl;

    ofstream version_stream;
    version_stream.open("../application/user_projects/version_files/" + filename + "_versions", ios_base::out | ios_base::app);
    if (!version_stream.is_open())
    {
        cout << "Failed to open " << filename << '\n';
    }
    else
    {
        v.set_project_id(p.project_id());
        cout << "Intital changes count: " << p.changes_count() << endl;
        if (p.changes_count() % 5 == 0) //creating new version every 5 changes
        {

            cout << "Creating new version" << endl;
            notepad_versions::version *pversion = v.add_each_version();
            pversion->set_version_number(p.changes_count() % 5); // v.each_version(v.each_version_size() - 1).version_number() + 1
            pversion->set_version_id(rand());
            pversion->set_created_time("0");
            pversion->clear_file_content();
            for (int i = 0; i < p.contents_size(); i++)
            {
                pversion->add_file_content(p.contents(i).content_line());
            }
            v.SerializeToOstream(&version_stream);
        }
        else // updating the existing version
        {
            cout << "making changes in old version. changes_count: " << p.changes_count() << endl;
            // *v.mutable_each_version(v.each_version_size()) = v.each_version(p.changes_count() % 5);
            notepad_versions::version *pversion = v.mutable_each_version(v.each_version_size() - 1);
            
            //to keep only the latest file content and remove all previous contents
            pversion->clear_file_content();
            for (int i = 0; i < p.contents_size(); i++)
            {
                pversion->add_file_content(p.contents(i).content_line());
            }
            
            v.SerializeToOstream(&version_stream);
        }
    }
    ifstream version_stream_read;
    version_stream_read.open("../application/user_projects/version_files/" + filename + "_versions", ios::in | ios::binary);
    if (!version_stream_read.is_open())
    {
        cout << "Failed to open " << filename << '\n';
    }
    else
    {
        v.ParseFromIstream(&version_stream_read);
        cout << "~~~~~~~~~~~~~~ " << v.project_id() << " ~~~~~~~~" << endl;
        for (int i = 0; i < v.each_version_size(); i++)
        {
            cout << "Version Number: " << v.each_version(i).version_number() << endl;
            cout << "Version ID: " << v.each_version(i).version_id() << endl;
            cout << "File Content: " << endl;
            for (int j = 0; j < v.each_version(i).file_content_size(); j++)
            {
                cout << v.each_version(i).file_content(j) << endl;
            }
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        }
    }
    version_stream_read.close();
    version_stream.close();
}