/*
 * @Author: Jerry
 * @Date: 2022/5/17.
*/

#include "gtest/gtest.h"
#include "../headers/add_two_number.h"

TEST(ADD_TWO_NUMBER_TEST, TEST_EMPTY) {
    auto *lst1 = new LinkedList<int>();
    auto *lst2 = new LinkedList<int>();

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    ASSERT_TRUE(pNode == nullptr);
}

TEST(ADD_TWO_NUMBER_TEST, TEST_FIRST_EMPTY) {
    auto lst1 = LinkedList<int>::of();
    auto lst2 = LinkedList<int>::of(1, 2, 3);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    ASSERT_TRUE(pNode == lst2->getHeadNode());
}

TEST(ADD_TWO_NUMBER_TEST, TEST_SECOND_EMPTY) {
    auto lst1 = LinkedList<int>::of(1, 2, 3);
    auto lst2 = LinkedList<int>::of();

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    ASSERT_TRUE(pNode == lst1->getHeadNode());
}

TEST(ADD_TWO_NUMBER_TEST, TEST_SAME_NON_CARRY) {
    auto lst1 = LinkedList<int>::of(1, 2, 3);
    auto lst2 = LinkedList<int>::of(4, 5, 6);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(5, 7, 9);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
}

TEST(ADD_TWO_NUMBER_TEST, TEST_SAME_CARRY) {
    auto lst1 = LinkedList<int>::of(1, 2, 3);
    auto lst2 = LinkedList<int>::of(4, 5, 7);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(5, 7, 0, 1);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
}

TEST(ADD_TWO_NUMBER_TEST, TEST_SAME_MULTI_CARRY) {
    auto lst1 = LinkedList<int>::of(1, 2, 3);
    auto lst2 = LinkedList<int>::of(9, 7, 6);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(0, 0, 0, 1);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
}

TEST(ADD_TWO_NUMBER_TEST, TEST_DIFF_NON_CARRY) {
    auto lst1 = LinkedList<int>::of(1, 2, 3);
    auto lst2 = LinkedList<int>::of(1, 2, 3, 4);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(2, 4, 6, 4);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
    ASSERT_EQ(count, expectedResult->size());

    lst1.release();
    lst2.release();
    expectedResult.release();
}

TEST(ADD_TWO_NUMBER_TEST, TEST_COMPLEX) {
    auto lst1 = LinkedList<int>::of(9,9,9,9,9,9,9);
    auto lst2 = LinkedList<int>::of(9,9,9,9);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(8,9,9,9,0,0,0,1);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
    ASSERT_EQ(count, expectedResult->size());

    lst1.release();
    lst2.release();
    expectedResult.release();
}

TEST(ADD_TWO_NUMBER_TEST, TEST_RANDOM) {
    auto lst1 = LinkedList<int>::of(2, 4, 3);
    auto lst2 = LinkedList<int>::of(5, 6, 4);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(7,0,8);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
    ASSERT_EQ(count, expectedResult->size());

    lst1.release();
    lst2.release();
    expectedResult.release();
}

TEST(ADD_TWO_NUMBER_TEST, TEST_STEP_1_ADDITION) {
    auto lst1 = LinkedList<int>::of(2, 4, 9);
    auto lst2 = LinkedList<int>::of(5, 6, 4, 9);

    ListNode<int> *pNode = addTwoNumbers(lst1->getHeadNode(), lst2->getHeadNode());

    auto expectedResult = LinkedList<int>::of(7,0,4, 0, 1);

    ASSERT_TRUE(pNode != nullptr);
    int count = 0;
    while (pNode != nullptr) {
        ASSERT_EQ(pNode->val, expectedResult->at(count));
        pNode = pNode->next;
        ++count;
    }
    ASSERT_EQ(count, expectedResult->size());

    lst1.release();
    lst2.release();
    expectedResult.release();
}