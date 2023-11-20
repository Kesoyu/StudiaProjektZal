#include <string>
#include <stdexcept>
#include "ErrorCode.h"
struct User{
protected:
	int id;
	std::string name;
	std::string surname;
	int age;
	std::string type;
	std::string country;
public:
	User(const std::string n, const std::string s, const std::string a, const std::string i, const std::string t, const std::string c){
		if (!(n.length() > 2 || s.length() > 2 || t.length() > 2 || c.length() > 2))
			throw ErrorCode::InvalidStringLength;

		this->name = n;
		this->surname = s;
		this->type = t;
		this->country = c;
		try {
			this->age = std::stoi(a);
			this->id = std::stoi(i);
		}
		catch (const std::invalid_argument& e) {
			throw ErrorCode::InvalidIntCasting;
		}
		catch (const std::out_of_range& e) {
			throw ErrorCode::InvalidIntCastingRange;
		}
		this->age = std::stoi(a);
		this->id = std::stoi(i);
		
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