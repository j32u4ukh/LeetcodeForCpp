#include <iostream>
#include "Tester.h"

using namespace std;

Tester::Tester() {
    this->val = 57;
};

Tester::Tester(int val) {
    this->val = val;
};

void Tester::classFunctionPointerTest(Solution* sol, void (Solution::* func)(int val)) {
    // (sol->*func): 呼叫的函式必須用括弧圈起來。
    // 參考：https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
    (sol->*func)(val);
};

void Tester::twoSum(Solution* sol, vector<int>(Solution::* func)(vector<int>&, int)) {
    vector<int> vi = { 2, 7, 11, 15 };
    int target = 9;
    vector<int> answer = (sol->*func)(vi, target);

    for (auto val : answer) {
        cout << val << " ";
    }
    cout << endl;
};