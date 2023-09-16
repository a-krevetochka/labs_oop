#include "pch.h"

using namespace std;
TEST(simple_correct_test, test1) {
    string input = "()";

    bool isCorrect = isOrderOfTheBracketsCorrect(input);

    ASSERT_TRUE(isCorrect);
}

TEST(correct_large_test, test2) {
    string input = "()()(())(())((()))";

    bool isCorrect = isOrderOfTheBracketsCorrect(input);

    ASSERT_TRUE(isCorrect);
}

TEST(incorrect_extra_close, test3) {
    string input = "())))";

    bool isCorrect = isOrderOfTheBracketsCorrect(input);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_extra_open, test4) {
    string input = "((((((()";

    bool isCorrect = isOrderOfTheBracketsCorrect(input);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_first_bracket_is_not_opening, test5) {
    string input = ")";

    bool isCorrect = isOrderOfTheBracketsCorrect(input);

    ASSERT_FALSE(isCorrect);
}

TEST(incorrect_another_symbol_in_row, test6) {
    string input = "(((((((9)";

    ASSERT_THROW(isOrderOfTheBracketsCorrect(input), invalid_argument);

}