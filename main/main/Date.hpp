#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>
#include <ctime>
#include <string>
#include "ErrorCode.h"

struct Date {
protected:
	int year;
	int month;
	int day;
public:
	Date() : year(0), month(0), day(0) {};
	Date(const std::string date) {
		if (this->validateDate(date)) {
			this->year = std::stoi(date.substr(4));
			this->month = std::stoi(date.substr(4, 2));
			this->day = std::stoi(date.substr(7, 2));
		}
	}
	std::string getDate() {
		return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
	}
private:
	bool validateDate(const std::string d) {
		int idx = 0, test;
		std::string str;
		std::string container[3] = {};

		for (int i = 0; i < d.length(); i++) {
			if (d[i] != '-')
				str += d[i];

 			if (d[i] == '-' || i == d.length() - 1) {
				try {
					test = std::stoi(str);
				}
				catch (const std::invalid_argument& e) {
					throw ErrorCode::InvalidIntCasting;
				}
				catch (const std::out_of_range& e) {
					throw ErrorCode::InvalidIntCastingRange;
				}
				container[idx] = str;
				str = "";
				idx++;
			}
		}
		if (idx == 3 && container[0].length() == 4 && container[1].length() == 2 && container[2].length() == 2) {
			std::time_t t;
			std::time(&t);

			std::tm timeInfo;
			localtime_s(&timeInfo, &t);
			int ct0value = stoi(container[0]);
			int ct1value = stoi(container[1]);
			int ct2value = stoi(container[2]);

			if (!(ct0value >= 1900 && ct0value <= 2099))
				throw ErrorCode::InvalidDateRange;
			if (!(ct1value >= 1 && ct1value <= 12))
				throw ErrorCode::InvalidDateRange;
			if (!(ct2value >= 1 && ct2value <= 31))
				throw ErrorCode::InvalidDateRange;

			return true;
		}
		throw ErrorCode::InvalidDateRange;
	}
};

#endif DATE_HPP