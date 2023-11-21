#include <string>
#include <algorithm>
#include <sstream>
#include "Date.cpp"

struct Membership {
protected:
	bool isAccountActive;
	Date date;
public:
	Membership(std::string ia, const std::string d) {
		std::transform(ia.begin(), ia.end(), ia.begin(), ::tolower);
		try {
			std::istringstream is(ia);
			is >> std::boolalpha >> isAccountActive;

			if (is.fail() || is.bad()) {
				throw ErrorCode::InvalidBoolCasting;
			}
		}
		catch (const std::exception& e) {
			isAccountActive = false;
			throw ErrorCode::InvalidBoolCasting;
		}

		try {
			this->date = Date(d);
		}
		catch (const std::exception& e) {
			this->date = Date();
			throw ErrorCode::ErrorConstructingDate;
		}
		
	}
	bool isActive() {
		return this->isAccountActive;
	}
	std::string getDate() {
		return this->date.getDate();
	}

};