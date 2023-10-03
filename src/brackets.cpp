#include<stack>
#include<string>
#include <stdexcept>
#include <iostream>

using namespace std;

bool isFirstSymbolIsOpeningBracket(string bracketsString) {
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
    bool isFirstIsOpeningBracket = isFirstSymbolIsOpeningBracket(bracketsString);
    if (!isFirstIsOpeningBracket) {
        return false;
    }
    stack<char> bracketsOrder;
    bracketsOrder.push('(');
    int counter{1};

    for (; counter < bracketsString.size() && (!bracketsOrder.empty() || bracketsString.at(counter) == '(') ; ++counter) {
        if (bracketsString.at(counter) == '(') bracketsOrder.push('(');
        else bracketsOrder.pop();
    }
        return bracketsOrder.empty() && counter == bracketsString.size();
}
