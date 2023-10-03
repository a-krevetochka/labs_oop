#include "octal.h"
#include <gtest/gtest.h>
#include <stdexcept>


class TestOperations : public ::testing::Test{
protected:
    void SetUp(){
        octal1.setValue("101");
        octal2.setValue("7");
    }
    void TearDown(){
    }
    Octal octal1;
    Octal octal2;
};

TEST_F(TestOperations, testPlus){
    ASSERT_EQ("011", (octal1 + octal2)->getValue());
}

TEST_F(TestOperations, testMinus){
    ASSERT_EQ("27", (octal1 - octal2)->getValue());
}

TEST_F(TestOperations, testLowerAndBigger) {
    ASSERT_TRUE(octal2 < octal1);
    ASSERT_TRUE(octal1 > octal2);
}

TEST_F(TestOperations, testEqueals){
    octal1.setValue("1");
    octal2.setValue("1");
    ASSERT_TRUE(octal1 == octal2);
}

TEST_F(TestOperations, startWithZero){
    ASSERT_THROW(octal1.setValue("01"), std::invalid_argument);
}

TEST_F(TestOperations, containsAnotherSymbols){
    ASSERT_THROW(octal1.setValue("01!"), std::invalid_argument);
}
TEST_F(TestOperations, containsHigher7digits){
    ASSERT_THROW(octal1.setValue("018"), std::invalid_argument);
}