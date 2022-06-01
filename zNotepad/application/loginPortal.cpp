// #include <iostream>
// #include <fstream>
// #include <string>
// #include "../notepad_proto/users.pb.h"
#include "projectPortal.cpp"
using namespace std;
int wrong_password_count = 0;
bool validateEmail(string email)
{
    int at = email.find('@');
    int dot = email.find('.');
    if (at == -1 || dot == -1 || at > dot)
    {
        return false;
    }
    return true;
}

bool emailExists(string email)
{
    ifstream file("users", ios::in | ios::binary);
    if (!file.is_open())
    {
        return false;
    }
    string line;
    while (getline(file, line))
    {
        if (line.find(email) != string::npos)
        {
            return true;
        }
    }
    return false;
}

void create_maintain_session()
{
    int key=32;
    notepad_users::UserList user_list;
    bool choice;
    string username, pwd, email;
    cout << "Enter email address: ";
    cin >> email;
    if (!validateEmail(email)) // to check if entered email is not valid one
    {
        cout << "Invalid email address" << endl;
        return create_maintain_session();
    }
    else // means that email is valid
    {
        if (emailExists(email)) // check if email exists and proceed to login
        {
            cout << "User exists. Enter password to login....." << endl;
            cin >> pwd;
            for (int i = 0; i < pwd.size(); i++)
            {
                pwd[i] = (pwd[i] + key) % 26;
            }
            ifstream file("users", ios::in | ios::binary);
            if (!file.is_open())
            {
                cout << "Error opening file" << endl;
                return;
            }
            user_list.ParseFromIstream(&file);
            for (int i = 0; i < user_list.users_size(); i++)
            {
                if (user_list.users(i).email() == email)
                {
                    if (user_list.users(i).password() == pwd) // if entered password is correct
                    {
                        cout << endl;
                        cout << "Login successful Welcome " << user_list.users(i).name() << endl;
                        cout << user_list.users(i).id() << endl;
                        cout << "0-Logout 1-Quit: ";
                        cin >> choice;
                        cout << "------" << endl;
                        if (!choice)
                        {
                            return create_maintain_session();
                        }
                        else
                        {
                            return;
                        }

                        return;
                    }
                    else
                    {
                        if(wrong_password_count>2) 
                        {
                            cout << "Get out" << endl;
                            return;
                        }
                        cout << "Invalid password relogin" << endl;
                        wrong_password_count++;
                        return create_maintain_session();
                    }
                }
            }
            return;
        }
        else // user does not exist so ask to create a new one
        {
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            getline(cin >> ws, pwd);
            for (int i = 0; i < pwd.size(); i++)
            {
                pwd[i] = (pwd[i] + key) % 26;
            }
            notepad_users::User *u = user_list.add_users();
            u->set_email(email);
            u->set_id(rand());
            // u->set_id(user_list.users_size());
            u->set_name(username);
            u->set_password(pwd);

            ofstream file("users", ios::out | ios::app | ios::binary);
            if (!file.is_open())
            {
                cout << "Error opening file" << endl;
                return;
            }
            file << user_list.SerializeAsString();
            file.close();
            cout << endl;
            create_directory(username);
            cout << "User created successfully" << endl;

            cout << "0-Login/SignUp 1-Quit: ";
            cin >> choice;
            cout << "------" << endl;
            if (!choice)
            {
                return create_maintain_session();
            }
            else
            {
                return;
            }
        }
    }
}

int main()
{
    create_maintain_session();
    return 0;
}