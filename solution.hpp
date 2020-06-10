#ifndef _SOLUTION_HPP_
#define _SOLUTION_HPP_
#pragma once
#include <vector>
#include <string>

#include "utils.hpp"

using namespace std;

class Solution {
public:
    static int numbers[];
    static int num;
    Solution();
    void classFunctionPointer(int);
    vector<int> twoSum(vector<int>&, int);
    int reverseInteger(int);
    bool palindromeNumber(int);
    int romanToInteger(string);
};

#endif // !_SOLUTION_HPP_