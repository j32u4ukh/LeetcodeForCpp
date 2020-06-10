#ifndef _TESTER_HPP_
#define _TESTER_HPP_
#pragma once
#include <vector>
#include <map>
#include "solution.hpp"

using namespace std;

class Tester
{
public:
	int val;
	Solution* sol;
	Tester();
	Tester(int);
	Tester(Solution* sol);
	void classFunctionPointerTest(Solution* sol, void (Solution::* func)(int val));
	void twoSum(Solution* sol, vector<int>(Solution::* func)(vector<int>&, int));
	void reverseInteger(Solution* sol, int (Solution::* func)(int));
	void palindromeNumber(bool (Solution::* func)(int));

	void getArrayLength();
};

#endif // !_TESTER_HPP_