
#ifndef BRACKETS_H
#define BRACKETS_H

#include<string>
#include <iostream>
#include "ICountable.h"

class Octal : ICountable<Octal> {
private:
    std::string value;
public:
    Octal();
    Octal(std::string value);
    void setValue(std::string parameter) override;
    std::string getValue() override;
    Octal* operator+(const Octal& right) override;
    Octal* operator-(const Octal& right) override;
    bool operator==(const Octal& right) override;
    bool operator<(const Octal& right) override;
    bool operator>(const Octal& right) override;
    Octal* operator=(const Octal& right) override;
    ~Octal();
    void print() override;
};

#endif
