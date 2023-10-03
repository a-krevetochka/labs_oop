//
// Created by meteo on 03.10.2023.
//

#ifndef LABRAB1_ICOUNTABLE_H
#define LABRAB1_ICOUNTABLE_H
#include <iostream>
template<typename T>
class ICountable {
    virtual void setValue(std::string value) = 0;
    virtual std::string getValue() = 0;
    virtual T* operator+(const T& right) = 0;
    virtual T* operator-(const T& right) = 0;
    virtual bool operator==(const T& right) = 0;
    virtual bool operator<(const T& right) = 0;
    virtual bool operator>(const T& right) = 0;
    virtual T* operator=(const T& right) = 0;
    virtual void print() = 0;
};



#endif //LABRAB1_ICOUNTABLE_H
