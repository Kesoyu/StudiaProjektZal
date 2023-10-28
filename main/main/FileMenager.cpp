#include "FileMenager.h"
FileMenager::FileMenager(std::string name, FileExtension extension) {
	this->fileName = name;
	this->fileExtension = extension;
};

ErrorCode FileMenager::getData(std::vector<std::string>* table) {
	switch (fileExtension)
	{
		case FileExtension::json :

			break;
		case FileExtension::csv :

			break;
		case FileExtension::txt :

			break;
	default:
		return ErrorCode::ErrorFileExtension;
	}
}