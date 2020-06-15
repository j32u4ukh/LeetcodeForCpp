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
    ListNode* q1 = new ListNode(1);
    q1->addNode(2);
    q1->addNode(4);

    ListNode* q2 = new ListNode(1);
    q2->addNode(3);
    q2->addNode(4);

    vector<vector<ListNode*>> questions = {
        {q1, q2},
        {nullptr, nullptr},
    };

    ListNode* a1 = new ListNode(1);
    a1->addNode(1);
    a1->addNode(2);
    a1->addNode(3);
    a1->addNode(4);
    a1->addNode(4);

    vector<ListNode*> answers = {a1, nullptr};

    vector<ListNode*> question;
    ListNode* lq, * l1, * l2, * la;

    int i, len = answers.size();
    for (i = 0; i < len; i++) {
        question = questions[i];
        l1 = question[0];
        l2 = question[1];
        lq = (sol->*func)(l1, l2);

        cout << "l1: " << l1->toString() << ", l2: " << l2->toString() << endl;
        cout << "lq: " << lq->toString() << endl;

        la = answers[i];
        cout << "la: " << la->toString() << endl;
        cout << "Same? " << isSameListNode(lq, la) << endl;
        cout << "==========" << endl;
    }
}

void Tester::removeDuplicates(Solution* sol, int(Solution::* func)(vector<int>& nums))
{
    vector<vector<int>> questions = {
        {1, 1, 2},
        {0, 0, 1, 1, 1, 2, 2, 3, 3, 4},

    };

    vector<int> answers = {2, 5};

    int i, len = answers.size(), result;
    vector<int> question;

    for (i = 0; i < len; i++) {
        question = questions[i];
        result = (sol->*func)(question);
        cout << "result: " << result << ", answer: " << answers[i] << endl;
        cout << "Correct? " << (result == answers[i]) << endl;
    }
}

void Tester::removeElement(Solution* sol, int(Solution::* func)(vector<int>& nums, int val))
{
    vector<vector<int>> questions = {
        {3,2,2,3},
        {0,1,2,2,3,0,4,2},
    };

    vector<int> vals = {3, 2};

    vector<int> question;
    int val;

    ////////////////////
    vector<int> answers = { 2, 5 };
    vector<vector<int>> new_nums = {
        {2,2},
        {0,1,3,0,4},
    };

    int answer;
    vector<int> new_num;

    int i, len = vals.size(), j, result;
    for (i = 0; i < len; i++) {
        question = questions[i];
        val = vals[i];
        result = (sol->*func)(question, val);
        answer = answers[i];

        if (result == answer) {
            cout << "Correct" << endl;
            for (j = 0; j < result; j++) {
                cout << "answer: " << new_nums[i][j] 
                     << ", result:" << question[j] 
                     << ", correct? " << (new_nums[i][j] == question[j]) << endl;
            }
        }
        else {
            cout << "Wrong" << endl;
        }

        cout << "====================" << endl;
    }
}
