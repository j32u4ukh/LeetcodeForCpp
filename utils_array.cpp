#include "utils.hpp"


#include <iostream>


namespace utils {
	namespace array {
		// 傳遞陣列的指標與長度
		typedef struct {
			int* p;
			int length;
		}sendArray;
	}
}