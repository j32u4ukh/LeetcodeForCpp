#ifndef _TESTER_H_
#define _TESTER_H_
#pragma once
#include <vector>
#include "Solution.h"
#include "leetcode.hpp"

using namespace std;

class Tester
{
public:
	int val;
	Tester();
	Tester(int);
	void classFunctionPointerTest(Solution* sol, void (Solution::* func)(int val));
	void twoSum(Solution* sol, vector<int>(Solution::* func)(vector<int>&, int));
	void reverseInteger(Solution* sol, int (Solution::* func)(int));
	void palindromeNumber(Solution* sol, bool (Solution::* func)(int));
	void romanToInt(Solution* sol, int(Solution::* func)(string s));
	void longestCommonPrefix(Solution* sol, string(Solution::* func)(vector<string>& strs));
	void isValid(Solution* sol, bool(Solution::* func)(string s));
	void mergeTwoLists(Solution* sol, ListNode* (Solution::* func)(ListNode* l1, ListNode* l2));
	void removeDuplicates(Solution* sol, int (Solution::* func)(vector<int>& nums));
	void removeElement(Solution* sol, int (Solution::* func)(vector<int>& nums, int val));

};
#endif _TESTER_H_