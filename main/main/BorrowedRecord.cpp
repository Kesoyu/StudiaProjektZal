#include <string>
#include <stdexcept>
#include "ErrorCode.h"
struct BorrowedItems {
	int total;
	int books;
	int audiobooks;
	BorrowedItems(const std::string t, const std::string b, const std::string a) {
		try {
			this->total = std::stoi(t);
			this->books = std::stoi(b);
			this->audiobooks = std::stoi(a);
		}
		catch (const std::invalid_argument& e) {
			throw ErrorCode::InvalidIntCasting;
		}
		catch (const std::out_of_range& e) {
			throw ErrorCode::InvalidIntCastingRange;
		}
	}
};