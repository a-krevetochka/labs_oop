//
// Created by meteo on 15.11.2023.
//
#include "iostream"

#ifndef LAB0_FORWARDITERATOR_H
#define LAB0_FORWARDITERATOR_H

template <typename T>
class ForwardIterator {
public:
    using value_type = T;
    using reference = T&;
    using pointer = T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    ForwardIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const {
        return *ptr_;
    }

    pointer operator->() const {
        return ptr_;
    }

    ForwardIterator& operator++() {
        ++ptr_;
        return *this;
    }

    ForwardIterator operator++(int) {
        ForwardIterator temp = *this;
        ++ptr_;
        return temp;
    }

    bool operator==(const ForwardIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const ForwardIterator& other) const {
        return ptr_ != other.ptr_;
    }

private:
    pointer ptr_;
};

#endif //LAB0_FORWARDITERATOR_H
