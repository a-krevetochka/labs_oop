#include "../include/octal.h"
#include <gtest/gtest.h>
#include "string"
#include <stdexcept>
using namespace octal;


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
    std::string result = (octal1 + octal2).getValue();

    ASSERT_EQ("110", result);
}

TEST_F(TestOperations, testMinus){
    std::string result = (octal1 - octal2).getValue();

    ASSERT_EQ("72", result);
}

TEST_F(TestOperations, testLower) {
    bool result = octal2 < octal1;

    ASSERT_TRUE(result);

}

TEST_F(TestOperations, testBigger){
    bool result = octal1 > octal2;

    ASSERT_TRUE(result);
}

TEST_F(TestOperations, testEqueals){
    Octal o1("1");
    Octal o2("1");

    bool result = o1 == o2;

    ASSERT_TRUE(result);
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

TEST_F(TestOperations, setterTest){
    octal1.setValue("156");

    std::string newValue = octal1.getValue();

    ASSERT_EQ("156", newValue);
}

TEST_F(TestOperations, parametrized){
    Octal octal3("101");

    std::string value = octal1.getValue();

    ASSERT_EQ("101", value);
}

TEST_F(TestOperations, out){
    testing::internal::CaptureStdout();

    std::cout << octal1;

    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("101", output);
}
