#include <iostream>
#include <fstream>
#include <string>

int main() 
{
    while(true)
    {
        std::cout << "1. Register\n2. Login\n";
        std::string option;
        std::cin >> option;

        system("cls");

        if(option == "1")
        {
            std::cout << "Enter username: ";
            std::string username;
            std::cin >> username;
            std::string file_path = "assets/" + username + ".txt";
            std::ifstream temp_file(file_path);
            if(temp_file)
            {
                std::clog << "!-- There is already a user named " << username << " --!\n";
                temp_file.close();
                continue;
            }
            std::cout << "Enter password: ";
            std::string password;
            std::cin >> password;
            std::ofstream file(file_path);
            if(!file)
            {
                std::cerr << "!?-- There is a error opening file --?!\n";
                continue;
            }
            file << username
                 << " "
                 << password;
            file.close();
        }
        else if (option == "2")
        {
            std::cout << "Enter the username: ";
            std::string username;
            std::cin >> username;
            std::string file_path = "assets/" + username + ".txt";
            std::ifstream file(file_path);
            if(!file)
            {
                std::clog << "!-- This account doesnt exist --!\n";
                continue;
            }
            std::cout << "Enter the password: ";
            std::string password;
            std::cin >> password;

            std::string *garbage = new std::string;
            file >> *garbage;
            delete garbage;
            std::string a_password;
            file >> a_password;
            if (password == a_password)
            {
                std::cout << "Welcome to our app!";
                return 0;
            }
            std::cout << "!-- Not the right password --!\n";
        }
        else
        {
            std::cout << "!-- Not a valid option! --!\n";
        }
        
    }  
}