#ifndef DURATION_HPP
#define DURATION_HPP

#include <string>
#include <stdexcept>
#include "ErrorCode.h"
#include <stack>

struct Duratrion {
protected:
	int minutes;
	int seconds;
public:
	Duratrion(const std::string v) {
	std::string str;
	std::stack<int> values;
		for (int i = 0; i < v.length(); i++) {
			if (v[i] != ':')
				str += v[i];

			if (v[i] == ':' || i == v.length() - 1) {
				try {
					values.push(std::stoi(str));
				}
				catch (const std::invalid_argument& e) {
					throw ErrorCode::InvalidIntCasting;
				}
				catch (const std::out_of_range& e) {
					throw ErrorCode::InvalidIntCastingRange;
				}
				str = "";
			}
		}
		this->seconds = values.top();
		values.pop();
		this->minutes = values.top();
	}

	//friend struct AudioBook;
};

#endif DURATION_HPP