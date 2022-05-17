/*
 * @Author: Jerry
 * @Date: 2022/5/17.
*/

#include "gtest/gtest.h"
#include "../headers/add_two_number.h"

TEST(LINKED_LIST_TEST, TEST_QUICK_CONSTRUCT) {
    auto list = LinkedList<int>::of(1, 2, 3, 4, 5);
    ASSERT_EQ(list->at(0), 1);
    ASSERT_EQ(list->at(1), 2);
    ASSERT_EQ(list->at(2), 3);
    ASSERT_EQ(list->at(3), 4);
    ASSERT_EQ(list->at(4), 5);
}

TEST(LINKED_LIST_TEST, TEST__ADD) {
    auto list = std::make_unique<LinkedList<int>>();
    list->add(0);
    list->add(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->add(5);
    ASSERT_EQ(list->at(0), 0);
    ASSERT_EQ(list->at(1), 1);
    ASSERT_EQ(list->at(2), 2);
    ASSERT_EQ(list->at(3), 3);
    ASSERT_EQ(list->at(4), 4);
    ASSERT_EQ(list->at(5), 5);
}