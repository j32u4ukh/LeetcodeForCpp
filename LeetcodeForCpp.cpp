﻿#include <iostream>
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

int main()
{
    Solution solution;
    Tester tester;
    /* 傳遞物件的函式，須分別傳遞"被建立的物件"本身位置，以及"物件函式"的位置
    tester.classFunctionPointerTest(&solution, &Solution::classFunctionPointer);

    // 參考：https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
    */
    tester.twoSum(&solution, &Solution::twoSum);
}