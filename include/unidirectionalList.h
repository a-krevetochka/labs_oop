//
// Created by meteo on 15.11.2023.
//
#include <memory>
#include "ForwardIterator.h"
#ifndef LAB0_UNIDIRECTIONALLIST_H
#define LAB0_UNIDIRECTIONALLIST_H

template<typename T>
struct Node {
    T value;
    Node* next;

    T get_value(){
        return value;
    }
};

template <typename T, typename Allocator = std::allocator<T>>
class unidirectionalList {
public:
    using AllocType = typename std::allocator_traits<Allocator>::template rebind_alloc<Node<T>>;

    unidirectionalList() :size_(0), head_(nullptr), tail_(nullptr), alloc_(AllocType()) {}

    ~unidirectionalList() {
        Node<T>* current = head_;
        while (current != nullptr) {
            Node<T>* next = current->next;
            alloc_.deallocate(current, 1);
            current = next;
        }
    }

    void push_back(const T& value) {
        size_ += 1;
        Node<T>* newNode = alloc_.allocate(1);
        newNode->next = nullptr;
        newNode->value = value;

        if (tail_ != nullptr) {
            tail_->next = newNode;
        } else {
            head_ = newNode;
        }
        tail_ = newNode;
    }

    int size(){
        return size_;
    }

    ForwardIterator<Node<T>> begin() {
        ForwardIterator<Node<T>> iter(head_);
        return iter;
    };

    ForwardIterator<Node<T>> end() {
        ForwardIterator<Node<T>> iter(tail_);
        return ++iter;
    };


private:
    int size_;
    Node<T>* head_;
    Node<T>* tail_;
    AllocType alloc_;
};


#endif //LAB0_UNIDIRECTIONALLIST_H
