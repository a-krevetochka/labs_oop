//
// Created by meteo on 15.11.2023.
//

#include "iostream"
#ifndef LAB0_CONSTFORWARDITERATOR_H
#define LAB0_CONSTFORWARDITERATOR_H


template <typename T>
class ConstForwardIterator {
public:
    using value_type = T;
    using reference = const T&;
    using pointer = const T*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::forward_iterator_tag;

    ConstForwardIterator(pointer ptr) : ptr_(ptr) {}

    reference operator*() const {
        return *ptr_;
    }

    pointer operator->() const {
        return ptr_;
    }

    ConstForwardIterator& operator++() {
        ++ptr_;
        return *this;
    }

    ConstForwardIterator operator++(int) const{
        ConstForwardIterator temp = *this;
        ++temp;
        return temp;
    }

    bool operator==(const ConstForwardIterator& other) const {
        return ptr_ == other.ptr_;
    }

    bool operator!=(const ConstForwardIterator& other) const {
        return ptr_ != other.ptr_;
    }

private:
    pointer ptr_;
};


#endif //LAB0_CONSTFORWARDITERATOR_H
