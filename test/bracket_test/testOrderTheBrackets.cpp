//
// Created by meteo on 13.09.2023.
//
#include "gtest/gtest.h"
#include "../../src/bracket_row.h"
using namespace std;
using namespace bracket_row;
TEST(simple_correct_test, test1){
    BracketRow simpleTest("()");

    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);

    ASSERT_TRUE(isCorrect);
}

TEST(correct_large_test, test2){
    BracketRow simpleTest("((()()))()()(())");

    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);

    ASSERT_TRUE(isCorrect);
}

TEST(incorrect_simple_test, test3){
    BracketRow simpleTest("())");

    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_large_test, test4){
    BracketRow simpleTest("((()()))()()(())(");

    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_first_bracket_is_not_opening, test5){
    BracketRow simpleTest(")");

    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_another_symbol_in_row, test6){
    BracketRow simpleTest("9");
    try {
        bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&simpleTest);
    }catch (invalid_argument invalid_argument){
        EXPECT_STREQ("row must contain only round brackets", invalid_argument.what());
    };

    ;
}