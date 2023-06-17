#include <iostream>

#include "sha256.h"
#include "Display_Class.hpp"
#include "Twitterak_Class.hpp"

//============================================================= Login_Functions ============================================================= 

void display::login(twitterak &app, std::string user_name, std::string password)
{
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//------------------------------------------------------------------------------------------

void display::login(twitterak &app, std::string user_name)
{
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }
    std::string password;

    std::cout << "$ Password : ";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//------------------------------------------------------------------------------------------

void display::login(twitterak &app)
{
    std::string user_name, password;
    std::cout << "$ Username : ";
    std::cin >> user_name;
    user_name = app.lower(user_name);
    if(user_name[0] == '@')
    {
        user_name.erase(0,1);
    }

    std::cout << "$ Password : ";
    std::cin >> password;

    if (app.users.count(user_name) == 1)
    {
        if (app.users[user_name].get_password() == display::encrypt(password))
        {
            app.is_logedin = true;
            app.logedin_user = user_name;
            std::cout << "* Login was successful\n";
        }
        else
        {
            std::cout << "! Your password is incorrect\n";
        }
    }
    else
    {
        std::cout << "! Your username is incorrect\n";
    }
}

//============================================================= Sign-up_Function ============================================================= 

void display::signup(twitterak &app)
{
    std::string Full_Name;
    std::string Username;
    std::string Password;

    user u1;

    std::cout << "$ Name : ";
    std::cin >> Full_Name;
    u1.set_name(Full_Name);

    std::cout << "$ Username : @";
    std::cin >> Username;
    u1.set_username(Username);

    while(1)
    {
        if(app.users.count(u1.get_username()) == 1)
        {
            std::cout << "! Your username is invalid.\n";
            std::cout << "$ Username : @";
            std::cin >> Username;
            u1.set_username(Username);
        }

        else
        {
            break;
        }
    }

    std::cout << "$ Password : ";
    std::cin >> Password;
    u1.set_password(Password);

    app.users[u1.get_username()] = u1;

    app.is_logedin = true;
    app.logedin_user = u1.get_username();
    
    std::cout << "* Registration was successful.\n";
}

//------------------------------------------------------------------------------------------

void display::signup(twitterak &app, std::string user_name)
{
    std::string Full_Name;
    std::string Password;

    user u1;

    std::cout << "$ Name : ";
    std::cin >> Full_Name;
    u1.set_name(Full_Name);

    u1.set_username(user_name);

    while(1)
    {
        if(app.users.count(u1.get_username()) == 1)
        {
            std::cout << "! Your username is invalid.\n";
            std::cout << "$ Username : @";
            std::cin >> user_name;
            u1.set_username(user_name);
        }

        else
        {
            break;
        }
    }

    std::cout << "$ Password : ";
    std::cin >> Password;
    u1.set_password(Password);

    app.users[u1.get_username()] = u1;

    app.is_logedin = true;
    app.logedin_user = u1.get_username();
    
    std::cout << "* Registration was successful.\n";
}
//============================================================= Help_Function ============================================================= 

void display::help(twitterak &app)
{
    if(app.is_logedin == false)
    {
        std:: cout << "login : to login to your acount\n";
        std::cout << "~ login your_user_name your_password\n~ login your_user_name\n~ login \n\n";

        std::cout << "signup : to create a new account\n";
        std::cout << "~ login your_user_name\n~ signup \n\n";

        std::cout << "exit : to close the app\n";
        std::cout << "~ exit\n~ quit\n~ q\n\n";

    }

    else
    {
        std::cout << "show profile : show your/another person account\n";
        std::cout << "show your profile :\n";
        std::cout << "~ profile\n";
        std::cout << "~ me\n";
        std::cout << "~ @me\n";
        std::cout << "show another person profile :\n";
        std::cout << "~ profile @user_name\n\n";

        std::cout << "edit account : to edit your profile\n";
        std::cout << "~ edit profile edit_part value\n";
        std::cout << "~ if your value is an string, put it between "" \n\n";

        std::cout << "logout : logout from your account\n";
        std::cout << "~ logout\n\n";

        std::cout << "delete account : to delete your account\n";
        std::cout << "~ delete account\n\n";

        // std::cout << "signup : \n";
        // std::cout << "signup : for create a new account\n";
    }
}