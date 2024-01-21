#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <stdexcept>
#include "ErrorCode.h"
#include "Membership.hpp"
#include "BorrowedItems.hpp"
#include "Book.hpp"
#include "AudioBook.hpp"

struct User{
protected:
	int id;
	std::string name;
	std::string surname;
	int age;
	std::string type;
	std::string country;
	int borrowedRecords;
	Membership membership;
	BorrowedItems borrowedItems;
	std::vector<Book> books;
	std::vector<AudioBook> audioBooks;
public:
	User(const std::string i, const std::string n, const std::string s, const std::string a, const std::string t, const std::string c, const std::string bR, Membership m, BorrowedItems bI, std::vector<Book> bs, std::vector<AudioBook> as) {
		if (!(n.length() > 2 || s.length() > 2 || t.length() > 2 || c.length() > 2))
			throw ErrorCode::InvalidStringLength;

		this->name = n;
		this->surname = s;
		this->type = t;
		this->country = c;
		try {
			this->age = std::stoi(a);
			this->id = std::stoi(i);
			this->borrowedRecords = std::stoi(bR);
		}
		catch (const std::invalid_argument& e) {
			throw ErrorCode::InvalidIntCasting;
		}
		catch (const std::out_of_range& e) {
			throw ErrorCode::InvalidIntCastingRange;
		}
		this->membership = m;
		this->borrowedItems = bI;
		this->books = bs;
		this->audioBooks = as;
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

	int getBorrowedRecords() {
		return this->borrowedRecords;
	}
};

#endif USER_HPP