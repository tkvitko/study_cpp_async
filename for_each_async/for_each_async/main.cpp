//
//  main.cpp
//  for_each_async
//
//  Created by tkvitko on 19.05.2024.
//

#include <iostream>
#include <vector>


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
    
    if (end - begin == 1) {
        *begin = func(*begin);
    } else {
        
        int size = end - begin;
        int half_size = size / 2;

        std::vector<int> left_part(0);
        std::vector<int> right_part(0);
        for (size_t i = 0; i < size; ++i) {
            if (i < half_size) {
                left_part.push_back(*begin);
            } else {
                right_part.push_back(*begin);
            }
            begin++;
        }
        
        for_each(left_part.begin(), left_part.end(), test_func);
        for_each(right_part.begin(), right_part.end(), test_func);
    }
}



int main(int argc, const char * argv[]) {
    
    std::vector<int> test_vec = {1, 2, 3, 4};
    for_each(test_vec.begin(), test_vec.end(), test_func);
    for (auto& el : test_vec) {
        std::cout << el << std::endl;
    };
    return 0;
}
