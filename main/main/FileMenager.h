#include <iostream> // DO TESTÓW
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <stack>
#include <any>
#include "ErrorCode.h"
#include "FileExtension.h"
#include "AllowedJsonObject.h"
#include "AllowedJsonElement.h"
#include "User.hpp"
#include "Membership.hpp"
#include "Book.hpp"
#include "AudioBook.hpp"
#include "BorrowedItems.hpp"

class FileMenager {
private:
	std::string fileName;
	FileExtension fileExtension;
	std::map<std::string, std::map<std::string, std::string>> userMapDict;
	std::string getAllowedStringValue(const AllowedJsonElement);
	AllowedJsonObject getAllowedObject(std::string);
	std::vector<Book> books;
	std::vector<AudioBook> audiobooks;
protected:
	bool isFileExisting();
	std::string getExtension();
	void initDataMap();
	void showVector(std::vector<User>*);
public:
	void getData(std::vector<User>*);
	FileMenager(std::string name, FileExtension extension);
};