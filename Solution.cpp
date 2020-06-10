#include <iostream>
#include <string>
#include <map>

#include "solution.hpp"
#include "utils.hpp"


using namespace std;


//#define arrayLength _countof

int Solution::numbers[] = { 11, 23, 37 };
int Solution::num = 11;

template<typename K, typename V>
bool mapValueCompare(map<K, V> _map, K key1, K key2);

Solution::Solution() {};


void Solution::classFunctionPointer(int val) {
	cout << "classFunctionPointer:" << val << endl;
};


vector<int> Solution::twoSum(vector<int>& nums, int target) {
	vector<int> answer;

	int i = 0, len = nums.size(), j;

	for (i = 0; i < len - 1; i++) {
		for (j = i + 1; j < len; j++) {
			//cout << "i:" << i << ", j:" << j << endl;

			if (nums[i] + nums[j] == target) {
				//answer.push_back(i);
				//answer.push_back(j);
				answer = { i, j };
				goto ANSWER;
			}
		}
	}

ANSWER:
	return answer;
}


int Solution::reverseInteger(int x) {
    bool is_negative = false;    

    if (x == 0) {
        return 0;
    }

    string str = to_string(x);
    if (x < 0) {
        is_negative = true;

        // 移除負號'-'，分別給予開始位置以及移除字數
        str.erase(begin(str));
    }

    // 數字反轉
    std::reverse(begin(str), end(str));

    if (str.at(0) == '0') {

        // 移除字串中的值，分別給予開始位置以及移除字數
        str.erase(begin(str));
    }

    // string 轉 double
    double reversed_x = stod(str);
    //cout << "reversed_x:" << reversed_x << endl;

    if (is_negative) {
        reversed_x *= -1;
    }
    //cout << "reversed_x:" << reversed_x << endl;

    // 避免溢位
    if (reversed_x < (double)INT32_MIN || INT32_MAX < reversed_x) {
        return 0;
    }

	return static_cast<int>(reversed_x);
}


bool Solution::palindromeNumber(int x) {
    if (x < 0) {
        return false;
    }
    
    string str = to_string(x);
    int i, len = str.size();

    for (i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }

    return true;
}


int Solution::romanToInteger(string roman)
{
    /*    Symbol       Value
            I             1
            V             5
            X             10
            L             50
            C             100
            D             500
            M             1000    */
    char roman_numbers[] = { 'M' , 'D', 'C', 'L', 'X', 'V', 'I'};
    map<char, int> roman_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int i, len = _countof(roman_numbers);
    char c;
    vector<int> indexs;
    //c = &roman_numbers[0];
    //indexs = utils::string::findAll(roman, c);

    for (i = 0; i < len; i++) {
        cout << "loop:" << i << endl;
        c = roman_numbers[i];
        indexs = utils::string::findAll(roman, c);

        //for (int j = 0; j < indexs.size(); j++) {
        //    cout << "j:" << indexs[j] << endl;
        //}
        cout << c << " @ " << utils::vector::toString(indexs) << endl;
    }

    //cout << "mapValueCompare:" << mapValueCompare(roman_map, roman[0], roman[1]) << endl;

	return 0;
}

template<typename K, typename V>
bool mapValueCompare(map<K, V> _map, K key1, K key2) {  
    V value1 = _map[key1];
    V value2 = _map[key2];

    cout << "value1:" << value1 << ", value2:" << value2 << endl;

    return value2 > value1;
}
