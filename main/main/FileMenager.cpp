#include "FileMenager.h"
FileMenager::FileMenager(std::string name, FileExtension extension) {
	this->fileName = name;
	this->fileExtension = extension;
};
std::string FileMenager::getExtension() {
	switch (fileExtension) {
	case FileExtension::json : return ".json";
	case FileExtension::csv: return ".csv";
	case FileExtension::txt: return ".txt";
	default: return "";
	};
}

ErrorCode FileMenager::getData(std::vector<std::string>* table) {
	if (getExtension() == "") {
		return ErrorCode::ErrorFileExtension;
	}

	if (!isFileExisting()) {
		return ErrorCode::ErrorFileName;
	}
	std::ofstream file;
	file.open(this->fileName + getExtension(), std::ios::out);
	switch (fileExtension)
	{
		case FileExtension::json :
			do{
				char character = std::getchar();
				if (character == '\n')
					continue;

				if (character == '"') {
					std::string signature;
					for (;;) {
						
					}
				}

				if (character == ']')
					file.close();

			} while (file.is_open());
			break;
		case FileExtension::csv :

			break;
		case FileExtension::txt :

			break;
	default:
		return ErrorCode::ErrorFileExtension;
	}
}
bool FileMenager::isFileExisting() {
	std::ofstream file;
	file.open(this->fileName+getExtension(), std::ios::out);
	if (file.is_open()){
		file.close();
		return true;
	}
	file.close();
	return false;
}