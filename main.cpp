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

long factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
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

    std::map<int, int, std::less<int>, MapAllocator<std::pair<const int, int>>> my_map;
    for (int i = 0; i <= 10; ++i) {
        my_map[i] = factorial(i);
    }

    for (const auto &[k, v]: my_map)
        std::cout << k << "->" << v << std::endl;

    unidirectionalList<int, MapAllocator<std::pair<const int, int>>> list{};
    for (int i = 0; i < 10; ++i) {
        list.push_back(i);
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (auto iter: list) {
        std::cout << iter.get_value() << " ";
    }

    return 0;


}