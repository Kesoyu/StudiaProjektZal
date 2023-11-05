#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "FileMenager.h"


int main()
{
    FileMenager fileMenager =  FileMenager("DataJson", FileExtension::json);
    
    std::vector<User> * users = new std::vector<User>;
    fileMenager.getData(users);
    
    
     
    return(0);
}
