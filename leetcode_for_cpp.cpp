#include <iostream>
#include <string>
#include <map>

#include "solution.hpp"
#include "tester.hpp"
#include "utils.hpp"


using namespace std;


enum class Color :int {
    Red,
    Green,
    Blue
};


// 將 enum class 當中的列舉值轉換成數字
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename underlying_type<Enumeration>::type
{
    return static_cast<typename underlying_type<Enumeration>::type>(value);
}


template <typename T>
int getArrayLength(T& _array) {
    return _countof(_array);
}


template <typename T>
int getLength(T &_array) {
    /*原本預期，但失敗：
    int getLength(T _array[]){
        return sizeof(_array) / sizeof(T);
    }    
    */
    return sizeof(_array) / sizeof(_array[0]);
}


class Call {
public:
    template <typename T>
    static int getArrayLength(T& _array) {
        return _countof(_array);
    }
};


template<typename K, typename V>
bool mapContain(map<K, V> _map, K _target)
{
    typename map<K, V>::iterator iter;

    iter = _map.find(_target);

    return (iter != _map.end());
    //return false;
}


int main()
{
    Solution solution;
    Tester tester;
    Tester solution_tester(&solution);
    /* 傳遞物件的函式，須分別傳遞"被建立的物件"本身位置，以及"物件函式"的位置
    tester.classFunctionPointerTest(&solution, &Solution::classFunctionPointer);

    solution_tester: 建立物件時即告知 &solution ，省卻每次函式呼叫都要給一次的麻煩，是我自己想的。 

    // 參考：https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
    */

    //tester.reverseInteger(&solution, &Solution::reverseInteger);
    //solution_tester.palindromeNumber(&Solution::palindromeNumber);

    //Solution ut_solution(&ut);
    
    string roman = "MCDDXMCL";
    //cout << "solution.romanToInteger:" << ut_solution.romanToInteger("CX") << endl;

    char roman_numbers[] = { 'M' , 'D', 'C', 'L', 'X', 'V', 'I' };

    int len = roman.length(), r, nr;
    char c;
    for (int i = 0; i < len; i++) {
    
    }
    cout << roman.find_first_of("D") << endl;
    //solution.romanToInteger("MCDDXMCL");

}