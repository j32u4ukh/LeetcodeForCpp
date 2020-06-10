#include "utils.hpp"

#include <string>
#include <iostream>


using namespace std;


namespace utils {
	namespace vector {
		std::string toString(std::vector<int>& vi) {
			std::string str;

			int i, len = vi.size();

			for (i = 0; i < len; i++) {
				str.append(to_string(vi[i]));

				if (i != (len - 1)) {
					str.append(", ");
				}
			}

			return str;
		}
	}
}