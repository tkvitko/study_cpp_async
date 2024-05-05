//
//  main.cpp
//  parallel_calculations
//
//  Created by tkvitko on 05.05.2024.
//

#include <iostream>
#include <vector>
#include <thread>

//template <class T>
//// суммирование векторов
//void summ(std::vector<T>& first, std::vector<T>& second) {
//    for (size_t i = 0; i < first.size(); ++i) {
//        first[i] += second[i];
//    }
//}
//
//template <class T>
//// получение кусочка вектора
//std::vector<T> slice(std::vector<T> vec, int start, int end) {
//    std::vector<T> slice;
//    for (int i = start; i < end; ++i) {
//        slice[i] = vec[i];
//    }
//    return slice;
//}

template <class T>
// суммирование кусоков векторов
void summ_slice(std::vector<T>& first, std::vector<T>& second, int start, int end) {
    for (size_t i = start; i < end; ++i) {
        first[i] += second[i];
    }
}

template <class T>
void parallel_sum(std::vector<T>& first, std::vector<T>& second, size_t threads) {
    int batch_size = static_cast<int>(first.size() / threads);
    int start = 0;
    int end = batch_size;
    
    for (size_t i = 0; i < threads; ++i) {
        std::thread t(summ_slice, std::ref(first), std::ref(second), start, end);
        t.detach();
        start += batch_size;
        end += batch_size;
    }
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 2, 3};
//    summ(a, b);
    
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    parallel_sum(a, b, 8);
    for (auto el : a) {
        std::cout << el << std::endl;
    }
    return 0;
}
