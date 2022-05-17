/*
 * @Author: Jerry
 * @Date: 2022/5/16.
*/


#include "../../../headers/add_two_number.h"

/*
 * Old version
ListNode<int>* addTwoNumbers(ListNode<int>* lst1, ListNode<int>* lst2, int carry){
    const int threshold = 10;

    if (lst1 == nullptr && lst2 == nullptr) {
        if (carry == 0) {
            return nullptr;
        }
        return new ListNode<int>(1, nullptr);
    }

    if (lst1 == nullptr) {
        int sum = lst2->val + carry;

        ListNode<int>* next = nullptr;
        if (sum >= threshold) {
            next = addTwoNumbers(lst2->next, lst2, 1);
        } else {
            next = addTwoNumbers(lst2->next, lst2, 0);
        }
        lst2->val = sum % threshold;

        if (next != nullptr) {
            lst2->next = next;
            return lst2;
        }
        return lst2;

    }
    if (lst2 == nullptr) {
        int sum = lst1->val + carry;

        ListNode<int>* next = nullptr;
        if (sum >= threshold) {
            next = addTwoNumbers(lst1->next, lst2, 1);
        } else {
            next = addTwoNumbers(lst1->next, lst2, 0);
        }
        lst1->val = sum % threshold;

        if (next != nullptr) {
            lst1->next = next;
            return lst1;
        }
        return lst1;
    }

    // now consider two complete list
    int sum = lst1->val + lst2->val + carry;
    // lazy list construction
    ListNode<int>* nextResult = nullptr;
    if(sum >= threshold) {
        nextResult = addTwoNumbers(lst1->next, lst2->next, 1);
    } else {
        nextResult = addTwoNumbers(lst1->next, lst2->next, 0);
    }
    lst1->val = sum % threshold;
    if (nextResult != nullptr) {
        lst1->next = nextResult;
    }
    return lst1;
}
*/

ListNode<int>* addTwoNumbers(ListNode<int>* lst1, ListNode<int>* lst2, const int threshold){
    ListNode<int>* head = lst1;
    int carry = 0;
    while (lst1 != nullptr || lst2 != nullptr) {
        int sum = carry;
        if (lst2 != nullptr) {
            sum += lst2->val;
            if (lst1 == nullptr) {
                lst1 = lst2;
                head = lst1;
                lst2 = nullptr;
            } else {
                lst2 = lst2->next;
            }
        }
        // if both or only lst1
        sum += lst1->val;
        lst1->val = sum % threshold;
        carry = sum >= threshold ? 1 : 0;
        if (lst1->next == nullptr && lst2 == nullptr && carry == 1) {
            lst1->next = new ListNode<int>(1, nullptr);
            return head;
        }
        if (lst1->next == nullptr && lst2 != nullptr) {
            lst1->next = lst2;
            lst2 = nullptr;
        }
        lst1 = lst1->next;
    }
    return head;
}