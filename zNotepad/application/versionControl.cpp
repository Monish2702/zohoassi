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

void save_version(string filename, notepad_projects::project &p , notepad_versions::version_list &v)
{
if (v.changes_count() != 0)
                {
                    ifstream version_fstream;
                    // notepad_versions::version_list v;
                    version_fstream.open("../application/user_projects/version_files/" + filename + "_versions", ios_base::in);

                    if (!version_fstream.is_open())
                    {
                        cout << "Failed to open " << filename << '\n';
                    }
                    else
                    {
                        // file operations
                        // v.ParseFromIstream(&version_fstream);
                    }

                    cout << "~~~~~~~~~~~~~~ " << v.each_version(0).version_number() << " " << v.project_id() << " ~~~~~~~~" << endl;
                }
                v.set_project_id(p.project_id());
                cout << "Intital changes count: " << v.changes_count() << endl;
                if (v.changes_count() % 5 == 0)
                {
                    cout << "Creating new version" << endl;
                    v.set_changes_count(v.changes_count() + 1);
                    notepad_versions::version *pversion = v.add_each_version();
                    pversion->set_version_number(v.changes_count() / 5); //v.each_version(v.each_version_size() - 1).version_number() + 1
                    pversion->set_version_id(rand());
                    pversion->set_created_time("0");
                    pversion->clear_file_content();
                    for (int i = 0; i < p.contents_size(); i++)
                    {
                        // notepad_versions::version *pversion_content = pversion->add_file_content();
                        pversion->add_file_content(p.contents(i).content_line());
                    }
                }
                else
                {
                    v.set_changes_count(v.changes_count() + 1);
                    cout << "changes_count: " << v.changes_count() << endl;
                    // *v.mutable_each_version(v.each_version_size()) = v.each_version(v.changes_count() % 5);
                    notepad_versions::version *pversion = v.mutable_each_version(v.each_version_size() - 1);
                    cout << "pversion->file_content_size(): " << pversion->file_content_size() << endl;

                    pversion->clear_file_content();

                    cout << "pversion->file_content_size(): " << pversion->file_content_size() << endl;
                    for (int i = 0; i < p.contents_size(); i++)
                    {
                        // notepad_versions::version *pversion_content = pversion->add_file_content();
                        pversion->add_file_content(p.contents(0).content_line());
                    }
                    cout << "pversion->file_content_size(): " << pversion->file_content_size() << endl;
                    //     changes_count++;
                }
                ofstream version_stream;
                version_stream.open("../application/user_projects/version_files/" + filename + "_versions", ios_base::app | ios_base::out);
                if (!version_stream.is_open())
                {
                    cout << "Failed to open the file:  " << filename << '\n';
                }
                else
                {
                    version_stream << v.SerializeAsString();
                }
                // v.SerializeToOstream(&version_stream);
                version_stream.close();
//                 //------------------------------
}