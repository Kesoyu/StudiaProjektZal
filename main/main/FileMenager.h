#include <string>
#include <vector>
#include <fstream>
#include "ErrorCode.cpp"
#include "FileExtension.cpp"

class FileMenager {
private:
	std::string fileName;
	FileExtension fileExtension;
protected:
	ErrorCode getData(std::vector<std::string>*);
	bool isFileExisting();
	std::string getExtension();
public:
	FileMenager(std::string name, FileExtension extension);
};