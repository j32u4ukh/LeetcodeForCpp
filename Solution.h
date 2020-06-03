#ifndef _SOLUTION_H_
#define _SOLUTION_H_
#pragma once
#include <vector>
#include <string>
#include <unordered_map>

#include "leetcode.h"

using namespace std;

class Solution {
public:
    static const int roman_len = 7;
    static const char romans[roman_len];
    static unordered_map<char, int> roman_map;

    Solution();
    void classFunctionPointer(int val);
    vector<int> twoSum(vector<int>& nums, int target);
    int romanToInt(string s);
    string longestCommonPrefix(vector<string>& strs);
    bool isValid(string s);
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};
#endif _SOLUTION_H_