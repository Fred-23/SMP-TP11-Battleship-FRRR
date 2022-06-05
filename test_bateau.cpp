#include "bateau.h"
#include <gtest/gtest.h>

// test getshot de bateau
TEST(getShotTest,Touche) {//1e test on test si le bateau est touche
        bateau b1(2,3,3,1);//creation d'un bateau 
        EXPECT_EQ(1, b1.getShot(2,3));//getshot à la position 2,3 : 0 = plouf , 1 touché , 2 coulé
}

TEST(getShotTest2,Plouf) {//2ème test plouf
        bateau b2(2,3,3,1);
        EXPECT_EQ(0, b2.getShot(8,9));
}

