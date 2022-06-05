#include "bateau.h"
#include <gtest/gtest.h>
//#include "googletest/googletest/include/gtest/gtest.h"
TEST(getShotTest,Plouf) {
        bateau b1;
        ASSERT_EQ(0, b1.getShot(0,0));
}

TEST(getShotTest2,Plouf) {
        bateau b2;
        ASSERT_EQ(1, b2.getShot(2,2));
}

