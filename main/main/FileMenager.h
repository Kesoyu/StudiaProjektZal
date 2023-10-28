#include <string>
#include <vector>
#include "ErrorCode.cpp"
#include "FileExtension.cpp"

class FileMenager {
private:
	std::string fileName;
	FileExtension fileExtension;
protected:
	ErrorCode getData(std::vector<std::string>*);
public:
	FileMenager(std::string name, FileExtension extension);
};