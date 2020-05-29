#pragma once
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    void addNode(int x) {
        ListNode* node = this;

        // 取得最後一個 ListNode(其 next 為空)
        while (node->next != nullptr)
        {
            node = node->next;
        }

        node->next = new ListNode(x);
    }

    string toString() {
        string result = "[ ";

        ListNode* node = this;
        cout << node->val << endl;

        // 取得最後一個 ListNode(其 next 為空)
        while (node != nullptr)
        {
            result += (node->val) + " ";
            cout << "result:" << result << endl;
            node = node->next;
        }

        result += "]";

        return result;
    }
};