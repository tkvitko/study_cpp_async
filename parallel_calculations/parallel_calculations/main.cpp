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
void parallel_sum(std::vector<T>& first, std::vector<T>& second,
                  int threads_count, std::vector<std::thread> threads) {
    
    int batch_size = static_cast<int>(first.size() / threads_count);
    int start = 0;
    int end = batch_size;
    
    // вариант с потоками:
    for (size_t i = 0; i < threads_count; ++i) {
        std::thread t(summ_slice<int>, std::ref(first), std::ref(second), start, end);
        t.detach();
        threads.push_back(std::move(t));
        start += batch_size;
        end += batch_size;
    }
    
    // вариант без потоков:
//    summ_slice<int>(std::ref(first), std::ref(second), start, end);
}

int main(int argc, const char * argv[]) {
    
    int cores_count = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {10, 20, 30};
//    summ(a, b);
    
    std::cout << "Количество аппаратных ядер - " << cores_count << std::endl;
    parallel_sum(a, b, 2, threads);
    for (auto el : a) {
        std::cout << el << std::endl;
    }
    return 0;
}
