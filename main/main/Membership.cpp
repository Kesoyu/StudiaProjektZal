#include <string>
#include <algorithm>
#include <sstream>
#include <ctime>
#include <iostream>
#include "ErrorCode.h"
struct Membership {
protected:
	bool isActive;
	std::string date;
public:
	Membership(const std::string ia, const std::string d) {
		std::transform(ia.begin(), ia.end(), ia.begin(), ::tolower);
		std::istringstream is(ia);
		is >> std::boolalpha >> isActive;
		if (validateDate(d))
			this->date = d;
	}
	bool isActive() {
		return this->isActive;
	}
	std::string getDate() {
		return this->date;
	}
private:
	bool validateDate(const std::string d) {
		int idx = 0;
		std::string str;
		std::string container[3] = {};

		for (int i = 0; i < d.length(); i++) {
			if (d[i] != '-')
				str += d[i];

			if (d[i] == '-' || i == d.length()-1) {
				try {
					std::stoi(str);
				}
				catch (const std::invalid_argument& e) {
					throw ErrorCode::InvalidIntCasting;
				}
				container[idx] = str;
				str = "";
				idx++;
			}
		}
		if (idx == 3 && container[0].length() == 4 && container[1].length() == 2 && container[2].length() == 2) {
			time_t now = time(0);
			tm* ltm = localtime(&now);

			if (!(stoi(container[0]) >= (1900 + ltm->tm_year) && stoi(container[0]) <= 2099))
				return false;
			if (!(stoi(container[1]) >= (1 + ltm->tm_mon) && stoi(container[1]) <= 12))
				return false;
			if (!(stoi(container[2]) >= ltm->tm_mday && stoi(container[2]) <= 31))
				return false;
			return true;
		}
		return false;
	}

};