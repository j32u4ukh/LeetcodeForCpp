#include <iostream>

#include "Solution.h"

using namespace std;

Solution::Solution() {
    
};

const char Solution::romans[Solution::roman_len] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };

unordered_map<char, int> Solution::roman_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
};

////////////////////////////////////////////////////////////////////////////////////////////////////
string subString(string str, int from, int to);
int findRightParentheses(char left_parentheses, string s, char right_parentheses);
////////////////////////////////////////////////////////////////////////////////////////////////////

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

#pragma region romanToInt: 效率可再提升
int Solution::romanToInt(string s)
{
    int len = static_cast<int>(s.size());

    if (len == 0) {
        return 0;
    }
    else if (len == 1) {
        const char* c = s.c_str();
        return Solution::roman_map[*c];
    }
    else {
        int i, value;
        size_t t;
        for (i = 0; i < roman_len; i++) {
            char c = romans[i];
            t = s.find_first_of(c);
            if (t != s.npos) {
                value = Solution::roman_map[c];
                break;
            }
        }

        int index = static_cast<int>(t);
        string left = subString(s, 0, index);
        string right = subString(s, index + 1, len);
        return value - romanToInt(left) + romanToInt(right);
    }
}

string subString(string str, int from, int to) {
    if (from > to) {
        throw "from > to";
    }

    return str.substr(from, to - from);
}
#pragma endregion

string Solution::longestCommonPrefix(vector<string>& strs)
{
    int n_string = strs.size();
    if (n_string == 0) {
        return "";
    }
    else if (n_string == 1) {
        return strs[0];
    }
    else
    {
        int shortest_len = strs[0].length();
        for (int i = 1; i < strs.size(); i++) {
            if (strs[i].length() < shortest_len) {
                shortest_len = strs[i].length();
            }
        }

        string common_prefix = "";
        int i;
        for (i = 0; i < shortest_len; i++) {
            char c = strs[0][i];
            for (int s = 1; s < n_string; s++) {
                if (strs[s][i] != c) {
                    goto OUTPUT;
                }
            }
        }

    OUTPUT:
        if (i == 0) {
            common_prefix = "";
        }
        else {
            common_prefix = strs[0].substr(0, i);
        }

        return common_prefix;
    }
}

#pragma region isValid: 效率可再提升，很多事前過濾，或許後面的其他步驟也可以做到
bool Solution::isValid(string s)
{
    int len = s.length();

    // 長度為 0
    if (len == 0) {
        //cout << "true: 長度為 0" << endl;
        return true;
    }

    // 總長度 等於 1，無法組成有效的括弧
    if (len & 1) {
        //cout << "總長度 等於 1" << endl;
        return false;
    }

    // 個數為奇數個，無法組成有效的括弧
    if (len % 2 != 0) {
        //cout << "總個數為奇數個" << endl;
        return false;
    }

    unordered_map<char, char> left_map = {
        {')', '('},
        {']', '['},
        {'}', '{'},
    };

    int right;
    switch (s[0])
    {
    case '(':
        right = findRightParentheses('(', s, ')');
        break;
    case '[':
        right = findRightParentheses('[', s, ']');
        break;
    case '{':
        right = findRightParentheses('{', s, '}');
        break;
    default:
        return false;
    }

    // 找不到右括弧
    if (right == -1) {
        //cout << "找不到右括弧" << endl;
        return false;
    }

    // 第一組括弧間沒有其他括弧    
    if (right == 1) {
        if (len == 2) {
            //cout << "true: 第一組括弧間沒有其他括弧，且長度為 2" << endl;
            return true;
        }

        // 計算右括弧右方剩餘的括弧個數，若為奇數個，則無法組成有效的括弧
        int n_right = len - right - 1;
        if (n_right % 2 != 0) {
            //cout << "右方剩餘的括弧個數為奇數個" << endl;
            return false;
        }

        return true & isValid(s.substr(right + 1, n_right));
    }

    // 第一組括弧間包含了其他括弧
    else {
        // left 為偶數時，表示左右括弧所夾括弧個數為奇數個，無法組成有效的括弧
        if (right % 2 == 0) {
            //cout << "第一組括弧間包含了其他括弧，且右方剩餘的括弧個數為奇數個" << endl;
            return false;
        }

        // 計算右括弧右方剩餘的括弧個數，若為奇數個，則無法組成有效的括弧
        int n_right = len - right - 1;
        if (n_right % 2 != 0) {
            //cout << "第一組括弧間包含了其他括弧，且左右括弧所夾括弧個數為奇數個" << endl;
            return false;
        }

        if (n_right == 0) {
            return true & isValid(s.substr(1, right - 1));
        }
        else {
            return true & isValid(s.substr(1, right - 1)) & isValid(s.substr(right + 1, n_right));
        }
    }

    //cout << "其他錯誤(" << s << "): len = " << len << ", left = " << left << ", right = " << right << endl;
    return false;
}

int findRightParentheses(char left_parentheses, string s, char right_parentheses) {
    int i, len = s.length(), pointer = 0;

    for (i = 0; i < len; i++) {
        if (s[i] == left_parentheses) {
            pointer -= 1;
        }
        else if (s[i] == right_parentheses) {
            pointer += 1;
        }

        if (pointer == 0) {
            return i;
        }
    }

    return -1;
}
#pragma endregion

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    return nullptr;
}
