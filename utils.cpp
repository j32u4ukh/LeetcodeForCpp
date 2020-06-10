#include "utils.hpp"


#include <iostream>


namespace utils {
	std::string boolToString(bool b) {
		if (b) {
			return "True";
		}
		else {
			return "False";
		}
	}
}