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

        // ���o�̫�@�� ListNode(�� next ����)
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

        // ���o�̫�@�� ListNode(�� next ����)
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