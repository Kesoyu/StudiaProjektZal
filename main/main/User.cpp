#include <string>
struct User{
protected:
	std::string name;
	std::string surname;
	int age;
	int id;
	std::string type;
	std::string country;
public:
	User(std::string n, std::string s, std::string a, std::string i, std::string t, std::string c){
		this->name = n;
		this->surname = s;
		this->age = std::stoi(a);
		this->id = std::stoi(i);
		this->type = t;
		this->country = c;
	};
	std::string getName() {
		return this->name;
	}

	std::string getSurname() {
		return this->surname;
	}

	int getAge() {
		return this->age;
	}

	int getId() {
		return this->id;
	}

	std::string getType() {
		return this->type;
	}

	std::string getCountry() {
		return this->country;
	}
};