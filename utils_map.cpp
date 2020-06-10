#include "utils.hpp"


#include <iostream>


namespace utils {
	namespace map {
		template<typename K, typename V>
		bool isContain_(std::map<K, V> _map, K _target) {
			typename std::map<K, V>::iterator iter;

			iter = _map.find(_target);

			return (iter != _map.end());
		}

		bool isContain(std::map<std::string, int> _map, std::string target) {
			return isContain_(_map, target);
		}

		bool isContain(std::map<char, int> _map, char target) {
			
			return isContain_(_map, target);
		}
	}
}