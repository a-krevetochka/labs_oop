#include<string>
#include <stdexcept>
#include <iostream>
#include "octal.h"
#include <utility>

const int ZERO_ASCII = 48;
const int DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS = 2;
const int NEW_CATEGORY = 10;

using namespace std;

string reverseString(string target) {
    std::string reversed;
    for (int i = target.size() - 1; i >= 0; --i) {
        reversed += target[i];
    }
    return reversed;
}

Octal::Octal() = default;

void Octal::setValue(std::string parameter) {
    if (parameter.at(0) == '0' && parameter.size() < 211){
        throw invalid_argument("The number can't start from 0");
    }
    std::string reversed;
    for (int i = parameter.size() - 1; i >= 0; --i) {
        if (!isdigit(parameter.at(i)) || parameter.at(i) > 55) {
            throw invalid_argument("octal numbers contain only digits from 0 to 7");
        }
        reversed += parameter[i];
    }
    value = reversed;
}

Octal::Octal(std::string value) {
    setValue(value);
}

std::string Octal::getValue() {
    return value;
}

Octal *Octal::operator-(const Octal &right) {
    if (value == right.value){
        return new Octal("0");
    }
    string bigger = *this > right ? value : right.value;
    string lower = *this < right ? value : right.value;
    string result;
    int currentDiff;
    int memory{0};
    int index{0};
    for (; index < lower.size(); ++index) { //сначала складываем до последнего знака меньшего числа
        if (bigger.at(index) - memory < lower.at(index)) {
            currentDiff = bigger.at(index) - lower.at(index) - memory + NEW_CATEGORY - DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS;
            result += (char) (currentDiff + ZERO_ASCII);
            memory = 1;
        } else{
            currentDiff = bigger.at(index) - lower.at(index) - memory;
            result += (char)(currentDiff + ZERO_ASCII);
            memory = 0;
        }
    }
    for (; index < bigger.size() ; ++index) {
        if (bigger.at(index) - memory - ZERO_ASCII < 0){
            currentDiff = bigger.at(index) - memory - DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS + NEW_CATEGORY;
            result += (char)(currentDiff);
        } else{
            currentDiff = bigger.at(index) - memory;
            if (currentDiff - ZERO_ASCII == 0){
                break;
            }
            result += (char)currentDiff;
            memory = 0;
        }
    }
    result = reverseString(result);
    cout << result << endl;
    return new Octal(result);
}

Octal *Octal::operator+(const Octal &right) {
    string bigger = value.size() >= right.value.size() ? value : right.value;
    string lower = value.size() < right.value.size() ? value : right.value;
    string result;
    int currentSum;
    int memory{0};
    int index{0};
    for (; index < lower.size(); ++index) { //сначала складываем до последнего знака меньшего числа
        currentSum = lower.at(index) + bigger.at(index) - ZERO_ASCII * 2 + memory; // два числа складываем, вычитаем код по таблице аски, прибавляем значение из памяти
        memory = 0; // так как значение из памяти взяли, обнуляем ее
        if (currentSum > 7) {
            result += (char) (currentSum + DIFFERENCE_BETWEEN_NUMBERS_SYSTEMS - NEW_CATEGORY + ZERO_ASCII); // значение после 7 отличаются от десятичной системы счисления на 2, eg: 7 + 5 = 12(decimal) 7 + 5 = 14(octal)
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
    result = reverseString(result);
    return new Octal(result);
}


bool Octal::operator<(const Octal &right) {
    if (value.size() > right.value.size()) {
        return false;
    }
    string leftValue = reverseString(value);
    string rightValue = reverseString(right.value);
    for (int i = 0; i < leftValue.size(); ++i) {
        if (leftValue.at(i) > rightValue.at(i)) {
            return true;
        }
    }
    return false;
}

bool Octal::operator>(const Octal &right) {
    if (value.size() > right.value.size()) {
        return true;
    }
    string leftValue = reverseString(value);
    string rightValue = reverseString(right.value);
    for (int i = 0; i < leftValue.size(); ++i) {
        if (leftValue.at(i) > rightValue.at(i)) {
            return true;
        }
    }
    return false;
}

Octal *Octal::operator=(const Octal &right) {
    value = right.value;
    return this;
}

bool Octal::operator==(const Octal &right) {
    if (value.size() != right.value.size()) {
        return false;
    }
    for (int i = 0; i < value.size(); ++i) {
        if (value.at(i) != right.value.at(i)) {
            return false;
        }
    }
    return true;
}

void Octal::print() {
    cout << reverseString(value) << endl;
}

Octal::~Octal() = default;
