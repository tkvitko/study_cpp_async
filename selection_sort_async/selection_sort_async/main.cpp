//
//  main.cpp
//  selection_sort_async
//
//  Created by tkvitko on 16.05.2024.
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <future>


std::vector<int> generate_random_int_vector(size_t size) {
    std::vector<int> vec {};
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(std::rand() % 100);
    }
    return vec;
}

void get_min_element_idx(std::vector<int> vec, size_t from_idx, std::promise<long> min_idx) {
    const auto begin = vec.begin() + from_idx;
    std::cout << std::this_thread::get_id() << std::endl;
    std::vector<int>::iterator result = std::min_element(begin, vec.end());
    min_idx.set_value(std::distance(vec.begin(), result));
//    return std::distance(vec.begin(), result);
}

void swap_elements(size_t first_idx, size_t second_idx, std::vector<int>& vec) {
    int temp = vec[first_idx];
    vec[first_idx] = vec[second_idx];
    vec[second_idx] = temp;
}

void print_vector(const std::vector<int> vec) {
    for (auto& el : vec) {
        std::cout << el << std::endl;
    };
}

int main(int argc, const char * argv[]) {
    
    std::cout << std::this_thread::get_id() << std::endl;
    std::vector<int> test_vec = generate_random_int_vector(10);
    print_vector(test_vec);
    
    for (size_t i = 0; i < test_vec.size(); ++i) {
        // синхронный вариант:
//        size_t min_idx = get_min_element_idx(test_vec, i);
        
        // базовый асинхронный вариант:
//        std::future<long> f(std::async(get_min_element_idx, test_vec, i));
//        const size_t min_idx = f.get();
        
        // вариант с promise
        std::promise<long> min_idx_promise;
        std::future<long> f{min_idx_promise.get_future()};
        std::thread t{std::move(get_min_element_idx), test_vec, i, std::move(min_idx_promise)};
        t.detach();
        const long min_idx{f.get()};
        
        // отладка
//        std::cout << "\n" << min_idx << "\n" << std::endl;

        swap_elements(i, min_idx, test_vec);
    }
    
    std::cout << "\n" <<std::endl;
    print_vector(test_vec);
    
    return 0;
}
