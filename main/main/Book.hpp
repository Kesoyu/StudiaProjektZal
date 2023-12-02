#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include "Media.hpp"

struct Book : protected Media{
protected:
	int pages;
public:
	Book(const std::string n, const std::string a, const std::string pY, const std::string g, const std::string r, const std::string rD, const std::string p) : Media(n, a, pY, g, r, rD) {
		try {
			this->pages = std::stoi(p);
		}
		catch (const std::invalid_argument& e) {
			throw ErrorCode::InvalidIntCasting;
		}
		catch (const std::out_of_range& e) {
			throw ErrorCode::InvalidIntCastingRange;
		}
	}

};

#endif BOOK_HPP