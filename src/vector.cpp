#include <string>
#include "vector.h"
#include "string"
int* Vector::begin() {
    return reinterpret_cast<int *>(&data[0]);
}

int* Vector::end() {
    return reinterpret_cast<int *>(&data[size]);
}

Vector::Vector() {
    size = 0;
    capacity = 1;
    data = new unsigned char[capacity];
}

Vector::Vector(int n) {
    size = n;
    capacity = n;
    data = new unsigned char[capacity];
}

Vector::Vector(int n, std::string x) {
    size = n;
    capacity = n;
    data = new unsigned char[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = x[i];
    }
}

Vector::~Vector() {
    delete[] data;
}

signed char Vector::operator[](int i) const{
    return data[i];
}

void Vector::push_back(int x) {
    if (size == capacity) {
        capacity *= 2;
        auto* new_data = new unsigned char[capacity];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
    }
    data[size] = x;
    size++;
}

void Vector::pop_back() {
    size--;
}

int Vector::get_size() const {
    return size;
}

void Vector::clear() {
    size = 0;
    capacity = 1;
    data = new unsigned char[capacity];
}
