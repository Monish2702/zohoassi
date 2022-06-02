#include "projectPortal.cpp"

int wrong_password_count = 0; // global variable

bool validateEmail(string email) //to validate email
{
    int at = email.find('@');
    int dot = email.find('.');
    if (at == -1 || dot == -1 || at > dot)
    {
        return false;
    }
    return true;
}

bool check_Captcha(string &captcha, string &user_input) //to validate captcha
{
    return captcha.compare(user_input) == 0;
}

// function to generate CAPTCHA
string generateCaptcha(int n)
{
    time_t t;
    srand((unsigned)time(&t));
    const char *required_chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string captcha = "";
    while (n--)
        captcha.push_back(required_chars[rand() % 62]);
    return captcha;
}

bool emailExists(string email) //to check if email already exists so as to prompt to login
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

bool is_user_name_available(string username) //to check username is available or already taken
{
    ifstream file("users", ios::in | ios::binary);
    if (!file.is_open())
    {
        return false;
    }
    string line;
    while (getline(file, line))
    {
        if (line.find(username) != string::npos)
        {
            return true;
        }
    }
    return false;
}

//function to login/logout/signup
void create_maintain_session()
{
    int key = 32;
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
                        // string captcha = generateCaptcha(4); //captcha part starts
                        // cout << "CAPTCHA: " << captcha << endl;
                        // string user_input;
                        // cout << "Enter the CAPTCHA: ";
                        // cin >> user_input;
                        // if (check_Captcha(captcha, user_input))
                        // {
                        //     cout << "Valid CAPTCHA" << endl;
                        // }
                        // else
                        // {
                        //     cout << "Invalid CAPTCHA" << endl;
                        //     return create_maintain_session(); // captcha part ends
                        // } 
                        cout << endl;
                        cout << "Login successful Welcome " << user_list.users(i).name() << endl;
                        cout << user_list.users(i).id() << endl;
                        open_project_portal(user_list.users(i).id(),user_list.users(i).name());
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
                        cout << "Invalid password relogin" << endl;
                        return create_maintain_session();
                    }
                }
            }
            return;
        }
        //-------------------------------------------------------------------------------------
        else // user does not exist so ask to create a new one
        {
            cout << "Enter username: ";
            cin >> username;
            if (is_user_name_available(username))
            {
                cout << "User name already exists. Try some other name...." << endl;
                return create_maintain_session();
            }

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