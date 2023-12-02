#ifndef AUDIOBOOK_HPP
#define AUDIOBOOK_HPP

#include <string>
#include "Media.hpp"
#include "Duration.hpp"

struct AudioBook : protected Media {
protected:
	Duratrion duration;
public:
	AudioBook(const std::string n, const std::string a, const std::string pY, const std::string g, const std::string r, const std::string rD, const std::string d) : Media(n, a, pY, g, r, rD), duration(Duratrion(d)) {}
};

#endif AUDIOBOOK_HPP