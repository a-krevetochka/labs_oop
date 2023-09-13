//
// Created by meteo on 13.09.2023.
//

#include <iostream>
#include <stack>
#include "bracket_row.h"
#include <map>
#include <utility>
using namespace std;
using namespace bracket_row;

BracketRow::BracketRow(std::string row):data(std::move(row)){};

void BracketRow::setData(std::string row) {
    this->data = std::move(row);
}

string BracketRow::getData() {
    return this->data;
}

bool BracketRow::checkFirstSymbolIsOpeningBracket() {
    return this->data.at(0) == '(';
}

void BracketRow::checkRowIsContainOnlyBrackets() {
    for (char bracket: this->data) {
        if (bracket != ')' && bracket != '('){
            throw invalid_argument("row must contain only round brackets");
        }
    }
}

bool BracketRow::isOrderOfTheBracketsCorrect(bracket_row::BracketRow *bracketRow) {
    bracketRow->checkRowIsContainOnlyBrackets();
    bool isFirstSymbolIsOpeningBracket = bracketRow->checkFirstSymbolIsOpeningBracket();
    if (!isFirstSymbolIsOpeningBracket){
        return false;
    }
    stack<char> bracketsOrder;
    for (char currentBracket: bracketRow->getData()) {
        if (currentBracket == '(') bracketsOrder.push(currentBracket);
        else bracketsOrder.pop();
    }
    return bracketsOrder.empty();
}
