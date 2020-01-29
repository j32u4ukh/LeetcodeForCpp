#include <iostream>
#include "Solution.h"

using namespace std;

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