#include <iostream>
struct User {
protected:
	std::string firstName;
	std::string lastName;
	int idx;
public:
	User(std::string fname = "Anonymous", std::string lname = "Anonymous", int id = 0000) : firstName(fname), lastName(lname), idx(id) {};
	std::string getFirstName() {
		return firstName;
	}
	std::string getLastName() {
		return lastName;
	}
	int getId() {
		return idx;
	}
};