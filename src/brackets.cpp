#include<stack>
#include<string>
#include <stdexcept>
#include <iostream>

using namespace std;

bool checkFirstSymbolIsOpeningBracket(string bracketsString) {
	return bracketsString.at(0) == '(';
}

void checkRowContainOnlyBrackets(string bracketsString) {

    for (char bracket : bracketsString) {
        if (bracket != ')' && bracket != '(') {
            throw invalid_argument("row must contain only round brackets");
        }
    }
}

bool isOrderOfTheBracketsCorrect(string bracketsString) {

    checkRowContainOnlyBrackets(bracketsString);
    bool isFirstSymbolIsOpeningBracket = checkFirstSymbolIsOpeningBracket(bracketsString);
    if (!isFirstSymbolIsOpeningBracket) {
        return false;
    }
    stack<char> bracketsOrder;
    for (char currentBracket : bracketsString) {
        if (currentBracket == '(') bracketsOrder.push(currentBracket);
        else if(currentBracket == ')' && !bracketsOrder.empty())bracketsOrder.pop();
        else return false;
    }
    return bracketsOrder.empty();
}
