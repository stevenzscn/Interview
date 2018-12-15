#include "common.h"

#include <iostream>

ListNode* MergeSortedList(ListNode *one, ListNode *two) {
    if (one == nullptr)
        return two;
    if (two == nullptr)
        return one;

    ListNode *merged = nullptr;

    if (one->value < two->value) {
        merged = one;
        merged->next = MergeSortedList(one->next, two);
    } else {
        merged = two;
        merged->next = MergeSortedList(one, two->next);
    }

    return merged;
}

ListNode* MergeSortedList2(ListNode *one, ListNode *two) {
    if (one == nullptr)
        return two;
    if (two == nullptr)
        return one;

    ListNode *merged = nullptr;
    if (one->value < two->value) {
        merged = one;
        one = one->next;
    }
    else {
        merged = two;
        two = two->next;
    }
    
    ListNode *tmp = merged;
    while (one != nullptr && two != nullptr) {
        if (one->value < two->value) {
            tmp->next = one;
            tmp = tmp->next;
            one = one->next;
        } else {
            tmp->next = two;
            tmp = tmp->next;
            two = two->next;
        }
    }

    if (one == nullptr)
        tmp->next = two;
    if (two == nullptr)
        tmp->next = one;

    return merged;
}

int main() {
    ListNode *one = new ListNode[3];
    ListNode *two = new ListNode[3];

    if (one != nullptr && two != nullptr) {
        ListNode *tmp = one;
        tmp->value = 1;
        tmp->next = tmp + 1;
        tmp++;
        tmp->value = 3;
        tmp->next = tmp + 1; 
        tmp++;
        tmp->value = 5;
        tmp->next = nullptr;

        tmp = two;
        tmp->value = 2;
        tmp->next = tmp + 1;
        tmp++;
        tmp->value = 4;
        tmp->next = tmp + 1; 
        tmp++;
        tmp->value = 6;
        tmp->next = nullptr;

    }

    //ListNode *result = MergeSortedList(one, two);
    //PrintList(result);

    ListNode *result = MergeSortedList2(one, two);
    PrintList(result);

    delete[] one;
    one = nullptr;
    delete[] two;
    two = nullptr;

    return 0;
}
