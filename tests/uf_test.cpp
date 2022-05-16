//
// Created by Jerry on 2022/5/16.
//

#include "gtest/gtest.h"
#include "../headers/union_found.h"

// Demonstrate some basic assertions.
TEST(UFTest, TestUnion) {
    UF uf {10};
    uf.connect(0, 1);
    uf.connect(1, 2);
    uf.connect(2, 3);
    uf.connect(3, 4);
    ASSERT_TRUE(uf.connected(0, 4));
}