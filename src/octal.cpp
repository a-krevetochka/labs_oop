#include<string>
#include <stdexcept>
#include <iostream>
#include <cstdint>
#include "octal.h"
#include "algorithm"

const int ZERO_ASCII = 48;
const int DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS = 2;
const int NEW_CATEGORY = 10;

using namespace std;
using namespace octal;

Octal::Octal() = default;

void Octal::setValue(std::string parameter) {
    vector.clear();

    if (parameter.at(0) == '0' && parameter.size() > 1) {
        throw invalid_argument("The number can't start from 0");
    }

    for (int i = parameter.size() - 1; i >= 0; --i) {
        if (!isdigit(parameter.at(i)) || parameter.at(i) > 55) {
            throw invalid_argument("octal numbers contain only digits from 0 to 7");
        }
        vector.push_back(parameter[i]);
    }
}

Octal::Octal(std::string val) {
    setValue(val);
}

std::string Octal::getValue() const {
    string result;

    for (int i = 0; i < vector.get_size(); ++i) {
        result += (char) vector[i];
    }

    reverse(result.begin(), result.end());

    return result;
}

Octal Octal::operator-(const Octal &right) {
    if (*this == right) {
        return Octal("0");
    }

    string bigger = *this > right ? this->getValue() : right.getValue();
    reverse(bigger.begin(), bigger.end());

    string lower = *this < right ? this->getValue() : right.getValue();
    reverse(lower.begin(), lower.end());

    string result;
    int currentDiff;
    int memory{0};
    int index{0};

    for (; index < lower.size(); ++index) { //сначала складываем до последнего знака меньшего числа
        if (bigger.at(index) - memory < lower.at(index)) {
            currentDiff =
                    bigger.at(index) - lower.at(index) - memory + NEW_CATEGORY - DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS;
            result += (char) (currentDiff + ZERO_ASCII);
            memory = 1;
        } else {
            currentDiff = bigger.at(index) - lower.at(index) - memory;
            result += (char) (currentDiff + ZERO_ASCII);
            memory = 0;
        }
    }

    for (; index < bigger.size(); ++index) {
        if (bigger.at(index) - memory - ZERO_ASCII < 0) {
            currentDiff = bigger.at(index) - memory - DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS + NEW_CATEGORY;
            result += (char) (currentDiff);
        } else {
            currentDiff = bigger.at(index) - memory;
            if (currentDiff - ZERO_ASCII == 0) {
                break;
            }
            result += (char) currentDiff;
            memory = 0;
        }
    }

    reverse(result.begin(), result.end());

    return Octal(result);
}

Octal Octal::operator+(const Octal &right) {
    string bigger = this->vector.get_size() >= right.vector.get_size() ? this->getValue() : right.getValue();
    reverse(bigger.begin(), bigger.end());

    string lower = this->vector.get_size() < right.vector.get_size() ? this->getValue() : right.getValue();
    reverse(lower.begin(), lower.end());

    string result;
    int currentSum;
    int memory{0};
    int index{0};

    for (; index < lower.size(); ++index) { //сначала складываем до последнего знака меньшего числа
        currentSum = lower.at(index) + bigger.at(index) - ZERO_ASCII * 2 +
                     memory; // два числа складываем, вычитаем код по таблице аски, прибавляем значение из памяти
        memory = 0; // так как значение из памяти взяли, обнуляем ее
        if (currentSum > 7) {
            result += (char) (currentSum + DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS - NEW_CATEGORY +
                              ZERO_ASCII); // значение после 7 отличаются от десятичной системы счисления на 2, eg: 7 + 5 = 12(decimal) 7 + 5 = 14(octal)
            memory += 1; // записываем только единицы, десятки в память, значение в памяти не может превышать 1, тк при сложении 7 + 7 = 16 в восьмиричной
        } else {
            result += (char) (currentSum + ZERO_ASCII);
        }
    }

    for (; index <
           bigger.size(); ++index) { // если второе число оказалось больше, то к нему прибавляем значение из памяти до тех пор, пока можем, затем просто дописываем числа
        currentSum = bigger.at(index) + memory - ZERO_ASCII;
        memory = 0;
        if (currentSum > 7) {
            result += (char) (currentSum + DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS - NEW_CATEGORY + ZERO_ASCII);
            memory += 1;
        } else {
            result += (char) (currentSum + ZERO_ASCII);
        }
    }

    if (memory != 0) { // если в памяти еще что-то осталось, то это будет новый разряд
        result += (char) 1 + ZERO_ASCII;
    }

    reverse(result.begin(), result.end());
    return Octal(result);
}


bool Octal::operator<(const Octal &right) {
    if (vector.get_size() < right.vector.get_size()) {
        return true;
    }

    if (vector.get_size() > right.vector.get_size()) {
        return false;
    }

    for (int i = 0; i < vector.get_size(); ++i) {
        if (vector[i] < right.vector[i]) {
            return true;
        }
    }

    return false;
}

bool Octal::operator>(const Octal &right) {
    if (vector.get_size() > right.vector.get_size()) {
        return true;
    }

    if (vector.get_size() < right.vector.get_size()) {
        return false;
    }

    for (int i = 0; i < vector.get_size(); ++i) {
        if (vector[i] > right.vector[i]) {
            return true;
        }
    }

    return false;
}

Octal Octal::operator=(const Octal &right) {
    vector = right.vector;
    return *this;
}

bool Octal::operator==(const Octal &right) {
    if (vector.get_size() != right.vector.get_size()) {
        return false;
    }

    for (int i = 0; i < vector.get_size(); ++i) {

        if (vector[i] != right.vector[i]) {
            return false;
        }
    }

    return true;
}


std::ostream &octal::operator<<(ostream &stream, const Octal &octal) {
    stream << octal.getValue();
    return stream;
}

Octal::~Octal() = default;
