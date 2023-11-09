#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include "FileMenager.h"


int main()
{
    try {
        FileMenager fileMenager = FileMenager("DataJson", FileExtension::json);

        std::vector<User>* users = new std::vector<User>;
        fileMenager.getData(users);
    }
    catch (ErrorCode e) {
        switch (e) {
        case ErrorFileName:
            std::cerr << "Error: Invalid file name." << std::endl;
            break;
        case ErrorFileExtension:
            std::cerr << "Error: Invalid file extension." << std::endl;
            break;
        case InvalidIntCasting:
            std::cerr << "Error: Invalid integer casting." << std::endl;
            break;
        case InvalidIntCastingRange:
            std::cerr << "Error: Integer out of range for casting." << std::endl;
            break;
        case InvalidStringLength:
            std::cerr << "Error: Invalid string length." << std::endl;
            break;
        default:
            std::cerr << "Unknown error occurred." << std::endl;
            break;
        }
    }
    
    
     
    return(0);
}
