//
//  main.cpp
//  for_each_async
//
//  Created by tkvitko on 19.05.2024.
//

#include <iostream>
#include <vector>
#include <future>


int test_func(int x) {
    return x * x;
}

template <typename T>
void for_each(typename std::vector<T>::iterator begin,
              typename std::vector<T>::iterator end,
              T (*func)(T)) {
    
    // базовый вариант с циклом:
//    for (typename std::vector<T>::iterator el = begin; el != end; ++el) {
//        *el = func(*el);
//    }
    
    if (end == begin) {
        return;
    } else if (end - begin == 1) {
        *begin = func(*begin);
    } else {
        int size = end - begin;
        int half_size = size / 2;
        
        std::future<void> left(std::async(for_each, begin, begin + half_size, test_func));
        left.wait();
        std::future<void> right(std::async(for_each, begin + half_size, end, test_func));
        right.wait();
    }
}


int main(int argc, const char * argv[]) {
    
    std::vector<int> test_vec = {1, 2, 3, 4};
//    std::vector<int> test_vec = {};
    for_each(test_vec.begin(), test_vec.end(), test_func);
    for (auto& el : test_vec) {
        std::cout << el << std::endl;
    };
    return 0;
}
