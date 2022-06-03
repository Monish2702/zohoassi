#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <filesystem>
#include "../notepad_proto/users.pb.h"
#include "../project_proto/projects.pb.h"
#include "../version_proto/versions.pb.h"

using namespace std;
void version(string contents, int proj_id)
{
    notepad_versions::version_list vl;
    notepad_versions::version *v = vl.add_versions();
    if(changes_count==0)
    {
        vl.set_changes_count(1);
        vl.set_project_id(proj_id);
        v->set_version_id(rand());
        v->set_version_number(1);
        notepad_versions::changes *vc = v->add_current_version();
        vc->set_each_line(contents);
        // output_fstream << p.SerializeAsString();
    }
    else if(changes_count % 5 == 0)
    {
        
    }
    // notepad_versions::version *v = vl.add_versions();
}
