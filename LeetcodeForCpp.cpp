#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>

#include "leetcode.h"
#include "Solution.h"
#include "Tester.h"

using namespace std;

enum class Color : int {
    red,
    green,
    blue
};

// 將 enum class 當中的列舉值轉換成數字
template <typename Enumeration>
auto as_integer(Enumeration const value) -> typename underlying_type<Enumeration>::type
{
    return static_cast<typename underlying_type<Enumeration>::type>(value);
}

ostream& operator<<(ostream& os, const vector<string>& vec) {
    os << "[" << vec[0];
    int i;
    for (i = 1; i < vec.size(); i++) {
        os << ", " << vec[i];
    }
    os << "]";
    return os;
}

int main()
{
    Solution solution;
    Tester tester;
    /* 傳遞物件的函式，須分別傳遞"被建立的物件"本身位置，以及"物件函式"的位置
    tester.classFunctionPointerTest(&solution, &Solution::classFunctionPointer);

    // 參考：https://www.tutorialspoint.com/function-pointer-to-member-function-in-cplusplus
    */
    // tester.twoSum(&solution, &Solution::twoSum);
    // tester.romanToInt(&solution, &Solution::romanToInt);
    //tester.longestCommonPrefix(&solution, &Solution::longestCommonPrefix);
    //tester.isValid(&solution, &Solution::isValid);

    //ListNode *list1 = new ListNode(1);
    //(*list1).addNode(2);
    //(*list1).addNode(4);
    vector<int> vi1 = { 1, 2, 4 };
    ListNode *list1 = vectorToListNode(vi1);
    cout << "list1:" << (*list1).toString() << endl;

    ListNode list2(1);
    list2.addNode(3);
    list2.addNode(4);
    cout << "list2:" << list2.toString() << endl;
    ListNode* merge_list = solution.mergeTwoLists(list1, &list2);
    //ListNode* merge_list, * node, * node1, * node2;

    //if (list1.val < list2.val) {
    //    node = new ListNode(list1.val);
    //    node1 = list1.next;
    //    node2 = &list2;
    //}
    //else {
    //    node = new ListNode(list2.val);
    //    node1 = &list1;
    //    node2 = list2.next;
    //}

    //merge_list = node;

    //cout << (*merge_list).val << endl;

    //// node1, node2 都為空時，結束迴圈
    //while ((node1 != nullptr) || (node2 != nullptr)) {
    //    // node1, node2 都不為空
    //    if ((node1 != nullptr) && (node2 != nullptr)) {
    //        // node1 數值較小
    //        if (node1->val <= node2->val) {
    //            node->next = new ListNode(node1->val);
    //            node1 = node1->next;
    //        }

    //        // node2 數值較小
    //        else {
    //            node->next = new ListNode(node2->val);
    //            node2 = node2->next;
    //        }
    //    }

    //    // node1, node2 其中一個為空
    //    else {
    //        // node1 不為空
    //        if (node2 == nullptr) {
    //            node->next = new ListNode(node1->val);
    //            node1 = node1->next;
    //        }

    //        // node2 不為空
    //        else {
    //            node->next = new ListNode(node2->val);
    //            node2 = node2->next;
    //        }
    //    }

    //    cout << (*node).val << endl;
    //    node = node->next;
    //}

    cout << "merge_list:" << (*merge_list).toString() << endl;

}
