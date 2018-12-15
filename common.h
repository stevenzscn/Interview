#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

struct ListNode {
    int value = 0;
    ListNode *next = nullptr;
};

struct TreeNode {
    int value = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
};

void PrintList(ListNode *list) {
    while (list != nullptr) {
        std::cout << list->value << " -> ";
        list = list->next;
    }
    std::cout << "nullptr\n";
}

#endif
