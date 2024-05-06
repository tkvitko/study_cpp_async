//
//  main.cpp
//  parallel_calculations
//
//  Created by tkvitko on 05.05.2024.
//

#include <iostream>
#include <vector>
#include <thread>


template <class T>
// суммирование кусочков векторов
void summ_slice(std::vector<T>& first, std::vector<T>& second, int start, int end) {
    for (int i = start; i < end; ++i) {
        first[i] += second[i];
    }
}

template <class T>
void parallel_sum(std::vector<T>& first, std::vector<T>& second, size_t threads) {
    int batch_size = static_cast<int>(first.size() / threads);
    int start = 0;
    int end = batch_size;
    
    // вариант с потоками:
    for (size_t i = 0; i < threads; ++i) {
        std::thread t(summ_slice<int>, std::ref(first), std::ref(second), start, end);
        t.detach();
        start += batch_size;
        end += batch_size;
    }
    
    // вариант без потоков:
//    summ_slice<int>(std::ref(first), std::ref(second), start, end);
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {10, 20, 30};
//    summ(a, b);
    
    std::cout << "Количество аппаратных ядер - " << std::thread::hardware_concurrency() << std::endl;
    parallel_sum(a, b, 1);
    for (auto el : a) {
        std::cout << el << std::endl;
    }
    return 0;
}
