#include <iostream>
#include "math.h"
#include "Tester.h"
#include "Solution.h"
#include "utils.hpp"

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

void Tester::palindromeNumber(Solution* sol, bool (Solution::* func)(int)) {
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

void Tester::romanToInt(Solution* sol, int(Solution::* func)(string s))
{
    string questions[] = { "III", "IV", "IX", "LVIII", "MCMXCIV", "DCXXI" };
    int answers[] = { 3, 4, 9, 58, 1994, 621 };

    int i, len = sizeof(questions) / sizeof(questions[0]);
    cout << "len: " << len << endl;

    for (i = 0; i < len; i++) {
        string question = questions[i];
        int answer = answers[i];
        int value = (sol->*func)(question);
        cout << question << ": " << value << " >>> " << (value == answer) << endl;
        cout << "====================" << endl;
    }
};

void Tester::longestCommonPrefix(Solution* sol, string(Solution::* func)(vector<string>& strs)) {
    vector<vector<string>> questions = { 
        { "flower","flow","flight" },
        {"dog","racecar","car"},
        {},
        {"tokyo"}
    };

    vector<string> answers = { "fl", "" , "", "tokyo" };
    vector<string> strs;
    string output;

    int i, len = answers.size();

    for (i = 0; i < len; i++) {
        strs = questions[i];
        output = (sol->*func)(strs);

        cout << "output: " << output << ", answer: " << answers[i];

        if (output == answers[i]) {
            cout << ", True" << endl;
        }
        else {
            cout << ", False" << endl;
        }
    }
}

void Tester::isValid(Solution* sol, bool(Solution::* func)(string s))
{
    string questions[] = { "()", "()[]{}", "(]", "([)]", "{[]}", ""};
    bool answers[] = { true, true, false, false, true, true };

    int i, len = sizeof(answers) / sizeof(answers[0]);

    for (i = 0; i < len; i++) {
        string question = questions[i];
        bool answer = answers[i];
        bool result = (sol->*func)(question);
        cout << question << ": " << result << " >>> " << (result == answer) << endl;
        cout << "====================" << endl;
    }

}

void Tester::mergeTwoLists(Solution* sol, ListNode* (Solution::* func)(ListNode* l1, ListNode* l2))
{

}

