#ifndef _LEETCODE_HPP_
#define _LEETCODE_HPP_
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

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

    int getDepth() {
        int depth = 0;

        if (this != nullptr) {
            depth++;

            ListNode* node = this;

            // 計算 ListNode 深度
            while (node->next != nullptr)
            {
                node = node->next;
                depth++;
            }
        }

        return depth;
    }

    string toString() {
        int d, depth = getDepth() - 1;

        std::stringstream ss;
        ss << "[ ";

        if (this != nullptr) {
            ss << this->val;

            ListNode* node = next;

            // d: 用於計次，而非索引值
            for (d = 0; d < depth; d++) {
                ss << ", " << node->val;
                node = node->next;
            }
        }

        ss << " ]";

        return ss.str();
    }
};

ListNode* vectorToListNode(const vector<int>& vi);
bool isSameListNode(ListNode* l1, ListNode* l2);
#endif _LEETCODE_HPP_