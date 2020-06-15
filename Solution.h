#ifndef _SOLUTION_H_
#define _SOLUTION_H_
#pragma once
#include <vector>
#include <string>
#include <unordered_map>

#include "leetcode.hpp"

using namespace std;

class Solution {
public:
    static const int roman_len = 7;
    static const char romans[roman_len];
    static unordered_map<char, int> roman_map;

    Solution();
    void classFunctionPointer(int val);
    // =====以下為題目=====
    vector<int> twoSum(vector<int>&, int);
    int reverseInteger(int);
    bool palindromeNumber(int);
    int romanToInt(string);
    string longestCommonPrefix(vector<string>& strs);
    // 20. Valid Parentheses: isValid
    bool isValid(string s);
    // 21. Merge Two Sorted Lists: mergeTwoLists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
    // 26. Remove Duplicates from Sorted Array: removeDuplicates
    int removeDuplicates(vector<int>& nums);
    int removeElement(vector<int>& nums, int val);
};
#endif _SOLUTION_H_