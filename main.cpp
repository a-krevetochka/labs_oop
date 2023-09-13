#include <iostream>
#include "src/bracket_row.h"

using namespace std;
using namespace bracket_row;

int main() {
    string input_row;
    cin >> input_row;
    BracketRow row(input_row);
    bool isCorrect = BracketRow::isOrderOfTheBracketsCorrect(&row);
    cout << boolalpha << isCorrect << endl;
}
