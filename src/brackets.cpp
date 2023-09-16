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
    int counter{0};
    for (int i = 0; !bracketsOrder.empty() && i < bracketsString.size(); ++i, ++counter) {
        if (bracketsString.at(i) == '(') bracketsOrder.push('(');
        else bracketsOrder.pop();
    }
    return bracketsOrder.empty() && counter == bracketsString.size()-1;
}
