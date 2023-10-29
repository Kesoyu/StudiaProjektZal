#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "ErrorCode.cpp"
#include "FileExtension.cpp"
#include "User.cpp"

class FileMenager {
private:
	std::string fileName;
	FileExtension fileExtension;
	std::map<std::string, std::string> userTagDict;
protected:
	ErrorCode getData(std::vector<User>*);
	bool isFileExisting();
	std::string getExtension();
	void initDataMap();
public:
	FileMenager(std::string name, FileExtension extension);
};