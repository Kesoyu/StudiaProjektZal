#include <string>
struct User {
protected:
	std::string name;
	std::string surname;
	int age;
	int id;
	std::string type;
	std::string country;
public:
	User(std::string n, std::string s, std::string a, std::string i, std::string t, std::string c) : name(n), surname(s), type(t), country(c)  {
		this->age = std::stoi(a);
		this->id = std::stoi(i);
	};
	std::string getName() {
		return this->name;
	}
	std::string getSurname() {
		return this->surname;
	}
	int getId() {
		return this->id;
	}
};