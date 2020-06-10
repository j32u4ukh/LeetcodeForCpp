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