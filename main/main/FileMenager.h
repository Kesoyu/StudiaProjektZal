#include <iostream> // DO TESTÓW
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "ErrorCode.h"
#include "FileExtension.h"
#include "User.cpp"

class FileMenager {
private:
	std::string fileName;
	FileExtension fileExtension;
	std::map<std::string, std::string> userMapDict;
protected:
	bool isFileExisting();
	std::string getExtension();
	void initDataMap();
	void showVector(std::vector<User>*);
public:
	void getData(std::vector<User>*);
	FileMenager(std::string name, FileExtension extension);
};