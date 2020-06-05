#include "leetcode.h"

#include <iostream>

ListNode* vectorToListNode(const vector<int>& vi) {
    int len = vi.size();

    if (len == 0) {
        return new ListNode();
    }
    else {
        ListNode* list_node = new ListNode(vi[0]);
        int i;

        for (i = 1; i < len; i++) {
            list_node->addNode(vi[i]);
        }

        return list_node;
    }
}

bool isSameListNode(ListNode* l1, ListNode* l2)
{
    ListNode *node1 = l1, *node2 = l2;

    while (node1 != nullptr && node2 != nullptr) {
        if (node1->val != node2->val) {
            return false;
        }

        node1 = node1->next;
        node2 = node2->next;
    }

    if (node1 == nullptr && node2 != nullptr) {
        return false;
    }

    if (node1 != nullptr && node2 == nullptr) {
        return false;
    }

    return true;
}
