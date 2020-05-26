#include <iostream>
#include <unordered_map>
#include <tuple>

#include "Solution.h"
#include "Tester.h"

using namespace std;

enum class Color :int {
    red,
    green,
    blue
};

// 將 enum class 當中的列舉值轉換成數字
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename underlying_type<Enumeration>::type
{
    return static_cast<typename underlying_type<Enumeration>::type>(value);
}

/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
===================
III:          3
IV:           4
IX:           9
LVIII:        58
MCMXCIV:      1994
*/

unordered_map<char, int> roman_map = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

bool biggerRoman(char curr_char, char pre_char = NULL) {
    if (pre_char == NULL) {
        return true;
    }
    else {
        return roman_map[curr_char] >= roman_map[pre_char];
    }
}

vector<string> subRoman(string roman) {    
    string first;
    vector<string> second;
    int i, len = roman.length();

    if (len > 1) {
        for (i = 1; i < len; i++) {
            // 若目前這個字元 小於 前一個字元
            if (!biggerRoman(roman[i], roman[i - 1])) {
                break;
            }
        }

        first = roman.substr(0, i);

        if (len - i > 0) {
            second = subRoman(roman.substr(i, len - i));
        }
    }
    else if (len == 1) {
        first = roman;
    }

    vector<string> sub_roman = {first};

    for(string s : second) {
        sub_roman.push_back(s);
    }

    return sub_roman;
}

int computeRomanValue(string roman) {
    int i, len = roman.length(), value = roman_map[roman[len - 1]];

    for (i = len - 2; i >= 0; i--) {
        if (roman[i] == roman[i + 1]) {
            value += roman_map[roman[i]];
        }
        else {
            value -= roman_map[roman[i]];
        }
    }

    return value;
}

int romanToInt(string s) {
    int value = 0;
    vector<string> sub_roman = subRoman(s);

    for (string sub : sub_roman) {
        value += computeRomanValue(sub);
        cout << sub << ": " << computeRomanValue(sub) << endl;
    }

    return value;
}

ostream& operator<<(ostream& os, const vector<string>& vec) {
    os << "[" << vec[0];
    int i;
    for (i = 1; i < vec.size(); i++) {
        os << ", " << vec[i];
    }
    os << "]";
    return os;
}

int main()
{
    Solution solution;
    Tester tester;
    /* 傳遞物件的函式，須分別傳遞"被建立的物件"本身位置，以及"物件函式"的位置
    tester.classFunctionPointerTest(&solution, &Solution::classFunctionPointer);

    // 參考：https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
    */
    // tester.twoSum(&solution, &Solution::twoSum);

    string questions[] = {"III", "IV", "IX", "LVIII", "MCMXCIV", "DCXXI" };
    int answers[] = {3, 4, 9, 58, 1994, 621};

    int i, len = sizeof(questions) / sizeof(questions[0]);
    cout << "len: " << len << endl;

    for (i = 0; i < len; i++) {
        string question = questions[i];
        int answer = answers[i];
        int value = romanToInt(question);
        cout << question << ": " << value << " >>> " << (value == answer) << endl;
        cout << "====================" << endl;
    }
}