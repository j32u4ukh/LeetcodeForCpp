#pragma once
#include <vector>
#include "Solution.h"

using namespace std;

class Tester
{
public:
	int val;
	Tester();
	Tester(int);
	void classFunctionPointerTest(Solution* sol, void (Solution::* func)(int val));
	void twoSum(Solution* sol, vector<int>(Solution::* func)(vector<int>&, int));
	void romanToInt(Solution* sol, int(Solution::* func)(string s));
	void longestCommonPrefix(Solution* sol, string(Solution::* func)(vector<string>& strs));
	void isValid(Solution* sol, bool(Solution::* func)(string s));
};

