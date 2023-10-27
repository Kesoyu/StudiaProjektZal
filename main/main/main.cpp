#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "User.cpp"

int main()
{
    std::cout << "Hello World!\n";
    
    std::fstream plik;
    std::vector<User> users;
    plik.open("Data.txt", std::ios::in);
    if (plik.good() == true)
    {
        while (!plik.eof())
        {
            std::string name;
            std::string lastname;
            std::string idx;
            getline(plik, name, ';');
            getline(plik, lastname, ';');
            getline(plik, idx, ';');
            std::cout << name << lastname << idx << "\n";
            //std::cin >> name;
            //int id = std::stoi(idx);
            //User user = { name, lastname, id };
            //users.push_back(user);
            //std::cout << users[users.size()-1].getFirstName() << "\n";
        }
        plik.close();
    }
    return(0);
}
