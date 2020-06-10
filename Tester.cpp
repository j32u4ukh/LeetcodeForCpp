#include <iostream>
#include "math.h"
#include "tester.hpp"
#include "utils.hpp"

using namespace std;

Tester::Tester() {
    this->val = 57;
};

Tester::Tester(int val) {
    this->val = val;
};

Tester::Tester(Solution* sol) {
    this->sol = sol;
}

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

void Tester::reverseInteger(Solution* sol, int (Solution::* func)(int)) {
    cout << "INT32_MIN:" << INT32_MIN << ", INT32_MAX:" << INT32_MAX << endl;

    int q, len, answer, question;
    int questions[] = { 123, -123, 120, -2147483412, -2147483648 };
    len = sizeof(questions) / sizeof(int);

    for (q = 0; q < len; q++) {
        question = questions[q];

        answer = (sol->*func)(question);
        cout << "Q" << q + 1 << ":" << question << " >> " << answer << endl;
    }
}

void Tester::palindromeNumber(bool (Solution::* func)(int)) {
    int q, len, question;
    int questions[] = { 121, -121, 10};
    bool answers[] = {true, false, false};
    bool answer, result;

    len = _countof(questions);

    for (q = 0; q < len; q++) {
        question = questions[q];
        answer = answers[q];
        result = (sol->*func)(question);

        cout << "question: " << question 
             << ", result: " << utils::boolToString(result)
             << ", answer: " << utils::boolToString(answer)
             << ", correct: " << utils::boolToString(result == answer) << endl;
    }
}

void Tester::getArrayLength() {
    int* p = sol->numbers;
    //cout << "sol->numbers:" << sol->numbers << endl;

    for (int i = 0; i < 3; i++) {
        cout << "numbers:" << *(p + i) << endl;
    }

    //cout << "Tester::getArrayLength():" << _countof(*p) << endl;
    //cout << "p" << p << endl;
}