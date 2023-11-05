#include "FileMenager.h"
FileMenager::FileMenager(std::string name, FileExtension extension) {
	this->fileName = name;
	this->fileExtension = extension;
};

void FileMenager::initDataMap() {
	userMapDict["name"] = "";
	userMapDict["surname"] = "";
	userMapDict["age"] = "";
	userMapDict["id"] = "";
	userMapDict["type"] = "";
	userMapDict["country"] = "";
}

std::string FileMenager::getExtension() {
	switch (fileExtension) {
	case FileExtension::json : return ".json";
	case FileExtension::csv: return ".csv";
	case FileExtension::txt: return ".txt";
	default: return "";
	};
}

void FileMenager::getData(std::vector<User> *table) {
	if (getExtension() == "") {
		throw ErrorCode::ErrorFileExtension;
	}

	if (!isFileExisting()) {
		throw ErrorCode::ErrorFileName;
	}
	std::ifstream file;
	file.open(this->fileName + getExtension(), std::ios::out);
	switch (fileExtension)
	{
		case FileExtension::json :
			do {
				char character;
				std::string line, key = "", value = "";
				std::getline(file, line, '\n');
				for (int i = 0; i < line.length(); i++)
					if (line[i] == '\n' || line[i] == '\t' || line[i] == '\b' || line[i] == ' ')
						line.erase(i--, 1);	

				for (int i = 0; i <= line.length(); i++) {
					character = line[i];
					if (character == '}')
						table->push_back({ userMapDict["name"], userMapDict["surname"], userMapDict["age"], userMapDict["id"], userMapDict["type"], userMapDict["country"] });

					if (character == ']')
						file.close();

					if (character == '"') {
						for (;;) {
							character = line[++i];
							if (character == '"')
								break;

							key.push_back(character);
						}
					}

					if (character == ':') {
						for (;;) {
							character = line[++i];
							if (character == '"') {
								character = line[++i];
							}
							if (i == line.length())
								break;
							if (character == ',') {
								i++;
								break;
							}

							value.push_back(character);
						}
					}

					if (character = '"' && !(key == "" || value == ""))
						userMapDict[key] = value;
				}
			} while (file.is_open());
			this->showVector(table);
			break;
		case FileExtension::csv :

			break;
		case FileExtension::txt :
			
			break;
	default:
		throw ErrorCode::ErrorFileExtension;
	}
}
bool FileMenager::isFileExisting() {
	std::ifstream file;
	file.open(this->fileName+getExtension(), std::ios::out);
	if (file.is_open()){
		file.close();
		return true;
	}
	file.close();
	return false;
}

//Funkcja pogl¹dowa
void FileMenager::showVector(std::vector<User> *table) {
	for (int i = 0; i < table->size(); i++) {
		std::cout << table->at(i).getName() << ", "
			<< table->at(i).getSurname() << ", "
			<< table->at(i).getAge() << ", "
			<< table->at(i).getId() << ", "
			<< table->at(i).getType() << ", "
			<< table->at(i).getCountry() << "\n";
	}
}