#ifndef MEDIA_HPP
#define MEDIA_HPP

#include <string>
#include "Date.hpp"

struct Media {
protected:
	std::string name;
	std::string author;
	int publicationYear;
	std::string genre;
	float rating;
	Date returnDate;
private:
	Media(const std::string n, const std::string a, const std::string pY, const std::string g, const std::string r, const std::string rD) {
		this->name = n;
		this->author = a;
		try {
			this->publicationYear = std::stoi(pY);
			this->rating = std::stof(r);
		}
		catch (const std::invalid_argument& e) {
			throw ErrorCode::InvalidIntCasting;
		}
		catch (const std::out_of_range& e) {
			throw ErrorCode::InvalidIntCastingRange;
		}
		this->genre = g;
		this->returnDate = Date(r);
	}
public:
	friend struct Book;
	friend struct AudioBook;
};

#endif MEDIA_HPP