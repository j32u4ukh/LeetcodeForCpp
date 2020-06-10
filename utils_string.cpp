#include "utils.hpp"


namespace utils {
	namespace string {
		std::vector<int> findAll(std::string word, char c) {
			std::vector<int> indexs;
			size_t start_pos = 0, idx = word.find(c, start_pos);

			while (idx != std::string::npos) {
				indexs.push_back(idx);
				start_pos = idx + 1;
				idx = word.find(c, start_pos);
			}

			return indexs;
		}

		std::string subString(std::string str, int from, int to) {
			if (from > to) {
				throw "from > to";
			}

			return str.substr(from, to - from);
		}
	}
}