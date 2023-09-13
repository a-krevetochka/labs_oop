//
// Created by meteo on 13.09.2023.
//

#ifndef BRACKET_ROW_H
#define BRACKET_ROW_H

#include <string>
#include <stdexcept>
namespace bracket_row{

    class BracketRow {
    private:
        std::string data;

    public:
        void setData(std::string row);

        std::string getData();

        explicit BracketRow(std::string row);

        bool checkFirstSymbolIsOpeningBracket();

        void checkRowIsContainOnlyBrackets();

        static bool isOrderOfTheBracketsCorrect(BracketRow *bracketRow);
    };
}

#endif //BRACKET_ROW_H
