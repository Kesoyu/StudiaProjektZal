#include "FileMenager.h"
FileMenager::FileMenager(std::string name, FileExtension extension) {
	this->fileName = name;
	this->fileExtension = extension;
};

//unnecessary declartion, but is nescessary for me
void FileMenager::initDataMap() {
	userMapDict["users"]["id"] = "";
	userMapDict["users"]["name"] = "";
	userMapDict["users"]["surname"] = "";
	userMapDict["users"]["age"] = "";
	userMapDict["users"]["type"] = "";
	userMapDict["users"]["country"] = "";
	userMapDict["users"]["borrowedRecords"] = "";
	userMapDict["membership"]["date"] = "";
	userMapDict["membership"]["isActive"] = "";
	userMapDict["borrowedItems"]["total"] = "";
	userMapDict["borrowedItems"]["books"] = "";
	userMapDict["borrowedItems"]["audiobooks"] = "";
	userMapDict["books"]["name"] = "";
	userMapDict["books"]["author"] = "";
	userMapDict["books"]["publicationYear"] = "";
	userMapDict["books"]["genre"] = "";
	userMapDict["books"]["rating"] = "";
	userMapDict["books"]["returnDate"] = "";
	userMapDict["books"]["pages"] = "";
	userMapDict["audiobooks"]["name"] = "";
	userMapDict["audiobooks"]["author"] = "";
	userMapDict["audiobooks"]["publicationYear"] = "";
	userMapDict["audiobooks"]["genre"] = "";
	userMapDict["audiobooks"]["rating"] = "";
	userMapDict["audiobooks"]["returnDate"] = "";
	userMapDict["audiobooks"]["duration"] = "";
}

std::string FileMenager::getExtension() {
	switch (fileExtension) {
	case FileExtension::json: return ".json";
	case FileExtension::csv: return ".csv";
	case FileExtension::txt: return ".txt";
	default: return "";
	};
}

std::string FileMenager::getAllowedStringValue(const AllowedJsonElement ev) {
	switch (ev) {
	case AllowedJsonElement::Id: return "id";
	case AllowedJsonElement::Name: return "name";
	case AllowedJsonElement::Surname: return "surname";
	case AllowedJsonElement::Age: return "age";
	case AllowedJsonElement::Type: return "type";
	case AllowedJsonElement::Country: return "Country";
	case AllowedJsonElement::Dates: return "date";
	case AllowedJsonElement::IsActive: return "isActive";
	case AllowedJsonElement::BorrowedRecords: return "borrowedRecords";
	case AllowedJsonElement::Total: return "total";
	case AllowedJsonElement::Books: return "books";
	case AllowedJsonElement::Audiobooks: return "audiobooks";
	case AllowedJsonElement::Author: return "author";
	case AllowedJsonElement::PublicationYear: return "publicationYear";
	case AllowedJsonElement::Genre: return "genre";
	case AllowedJsonElement::Rating: return "rating";
	case AllowedJsonElement::ReturnDate: return "returnDate";
	case AllowedJsonElement::Pages: return "pages";
	case AllowedJsonElement::Duration: return "duration";
	default: return "";
	};
}
AllowedJsonObject FileMenager::getAllowedObject(std::string object) {
	if (object == "users") {
		return AllowedJsonObject::Users;
	}
	if (object == "membership") {
		return AllowedJsonObject::Memberships;
	}
	if (object == "borrowedItems") {
		return AllowedJsonObject::BorrowedItemss;
	}
	if (object == "items") {
		return AllowedJsonObject::Items;
	}
	if (object == "books") {
		return AllowedJsonObject::Bookss;
	}
	if (object == "audiobooks") {
		return AllowedJsonObject::Audiobookss;
	}
	return AllowedJsonObject::Default;
}

void FileMenager::getData(std::vector<User>* table) {
	if (getExtension() == "") {
		throw ErrorCode::ErrorFileExtension;
	}

	if (!isFileExisting()) {
		throw ErrorCode::ErrorFileName;
	}
	std::ifstream file;
	file.open(this->fileName + getExtension(), std::ios::out);
	int bracketCounter = 0;
	std::stack<std::string> lastObjectKey;
	bool doInsert = false;
	switch (fileExtension)
	{
	case FileExtension::json:
		do {
			bool is = false;
			char character;
			std::string line, key = "", value = "", object = "";
			std::getline(file, line, '\n');
			for (int i = 0; i < line.length(); i++)
				if (line[i] == '\n' || line[i] == '\t' || line[i] == '\b' || line[i] == ' ')
					line.erase(i--, 1);

			for (int i = 0; i < line.length(); i++) {
				character = line[i];
				//if (character == '}')
				//	table->push_back({ userMapDict["name"], userMapDict["surname"], userMapDict["age"], userMapDict["id"], userMapDict["type"], userMapDict["country"] });

				if (line.find('{') != -1 || line.find('[') != -1 || line.find('}') != -1 || line.find(']') != -1) {
					for (;;) {
						if (line.length() == 1)
							break;
						character = line[i];
						if (character == '{' || character == '[' || character == '}' || character == ']')
							break;
						i++;
					}
					switch (character)
					{	
					case '[':
						
						bracketCounter++;
						if (i < line.length() - 1) {
							for (;;) {
								character = line[++i];
								if (character == ']')
									is = true;
								if (i >= line.length() - 1) 
									break;
							}
						}
						if (is) {
							bracketCounter--;
							is = false;
							break;
						}
					case '{':
						if(character == '{')
							bracketCounter++;

						if (line.length() == 1)
							break;

						i = 0;
						for (;;) {
							character = line[++i];
							if (character == '"')
								break;
							
							object.push_back(character);
						}
						lastObjectKey.push(object);
						i = line.length() - 1;
						character = line[i];
						break;
					case ']':
					case '}':
						AllowedJsonObject object = AllowedJsonObject::Default;
						bracketCounter--;
						if(lastObjectKey.size()>0)
							object = getAllowedObject(lastObjectKey.top());

						switch (object) {
						case AllowedJsonObject::Users:
							if (bracketCounter != 2) {
								lastObjectKey.pop();
								break;
							}
							table->push_back(User{ userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Id)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Name)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Surname)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Age)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Type)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::Country)],
								userMapDict["users"][getAllowedStringValue(AllowedJsonElement::BorrowedRecords)],
								Membership{userMapDict["membership"][getAllowedStringValue(AllowedJsonElement::IsActive)],
									userMapDict["membership"][getAllowedStringValue(AllowedJsonElement::Dates)]},
								BorrowedItems{userMapDict["borrowedItems"][getAllowedStringValue(AllowedJsonElement::Total)],
									userMapDict["borrowedItems"][getAllowedStringValue(AllowedJsonElement::Books)],
									userMapDict["borrowedItems"][getAllowedStringValue(AllowedJsonElement::Audiobooks)]}, books, audiobooks });
							break;
						case AllowedJsonObject::Memberships:
						case AllowedJsonObject::BorrowedItemss:
						case AllowedJsonObject::Items:
							lastObjectKey.pop();
							break;
						case AllowedJsonObject::Bookss:
							if (character == ']')
								lastObjectKey.pop();
							books.push_back(Book{ userMapDict["books"][getAllowedStringValue(AllowedJsonElement::Name)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::Author)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::PublicationYear)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::Genre)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::Rating)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::ReturnDate)],
								userMapDict["books"][getAllowedStringValue(AllowedJsonElement::Pages)] });
							break;
						case AllowedJsonObject::Audiobookss:
							if (character == ']')
								lastObjectKey.pop();
							audiobooks.push_back(AudioBook{ userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::Name)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::Author)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::PublicationYear)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::Genre)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::Rating)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::ReturnDate)],
								userMapDict["audiobooks"][getAllowedStringValue(AllowedJsonElement::Duration)] });
							break;
						}
						
						i = line.length() - 1;
						character = line[i];
						break;
					}
				}

				if (bracketCounter == 0)
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
					userMapDict[lastObjectKey.top()][key] = value;
			}
		} while (file.is_open());
		this->showVector(table);
		break;
	case FileExtension::csv:

		break;
	case FileExtension::txt:

		break;
	default:
		throw ErrorCode::ErrorFileExtension;
	}
}
bool FileMenager::isFileExisting() {
	std::ifstream file;
	file.open(this->fileName + getExtension(), std::ios::out);
	if (file.is_open()) {
		file.close();
		return true;
	}
	file.close();
	return false;
}

//Funkcja pogl¹dowa
void FileMenager::showVector(std::vector<User>* table) {
	for (int i = 0; i < table->size(); i++) {
		std::cout << table->at(i).getName() << ", "
			<< table->at(i).getSurname() << ", "
			<< table->at(i).getAge() << ", "
			<< table->at(i).getId() << ", "
			<< table->at(i).getType() << ", "
			<< table->at(i).getCountry() << "\n";
	}
}