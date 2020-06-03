#ifndef _LEETCODE_H_
#define _LEETCODE_H_
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

        // ���o�̫�@�� ListNode(�� next ����)
        while (node->next != nullptr)
        {
            node = node->next;
        }

        node->next = new ListNode(x);
    }

    int getDepth() {
        int depth = 1;

        ListNode* node = this;

        // �p�� ListNode �`��
        while (node->next != nullptr)
        {
            node = node->next;
            depth++;
        }

        return depth;
    }

    string toString() {
        int d, depth = getDepth() - 1;

        std::stringstream ss;
        ss << "[ " << this->val;

        ListNode* node = next;

        // d: �Ω�p���A�ӫD���ޭ�
        for (d = 0; d < depth; d++) {
            ss << ", " << node->val;
            node = node->next;
        }

        ss << " ]";

        return ss.str();
    }
};

ListNode* vectorToListNode(const vector<int>& vi);
#endif _LEETCODE_H_