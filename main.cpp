#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>
#include <vector>
#include "allocator.h"
#include "ForwardIterator.h"
#include "ConstForwardIterator.h"
#include "unidirectionalList.h"

struct SomeStruct {
    char buffer[1024];
};

void test1() {
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct> my_list;
    for (int i = 0; i < 500000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 500000; i++)
        my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

void test2() {
    auto begin = std::chrono::high_resolution_clock::now();
    std::list<SomeStruct, MapAllocator<SomeStruct>> my_list;
    for (int i = 0; i < 500000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 500000; i++)
        my_list.erase(my_list.begin());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}


int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Используем обычный итератор
    ForwardIterator<int> it(numbers.data());
    ForwardIterator<int> end(numbers.data() + numbers.size());
    for (; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Используем const итератор
    ConstForwardIterator<int> cit(numbers.data());
    ConstForwardIterator<int> cend(numbers.data() + numbers.size());
    for (; cit != cend; ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    test1();
    test2();

    std::map<int, int, std::less<int>, MapAllocator<std::pair<const int, int>>> my_map;

    my_map[1] = 10;
    my_map[2] = 20;
    my_map[3] = 30;


    for (const auto &[k, v]: my_map)
        std::cout << k << "->" << v << std::endl;

    unidirectionalList<int, MapAllocator<std::pair<const int, int>>> list{};
    for (int i = 0; i < 10; ++i){
        list.push_back(i);
    }
    Node<int>* c_ptr = list.head();
    for (int i = 0; i < list.size(); ++i) {
        std::cout << c_ptr->get_value() << " ";
        c_ptr = c_ptr->next;
    }

    return 0;


}