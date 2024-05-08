//
//  main.cpp
//  parallel_calculations
//
//  Created by tkvitko on 05.05.2024.
//

#include <iostream>
#include <vector>
#include <array>
#include <thread>
#include <random>


template <class T>
void summ_slice(std::vector<T>& first, std::vector<T>& second, int start, int end) {
    // суммирование кусочков векторов
    
    for (int i = start; i < end; ++i) {
        first[i] += second[i];
    }
}

template <class T>
void parallel_sum(std::vector<T>& first, std::vector<T>& second,
                  int threads_count, std::vector<std::thread>& threads) {
    // параллельное суммирование кусочков векторов
    
    int batch_size = static_cast<int>(first.size() / threads_count);
    int start = 0;
    int end = batch_size;
    
    for (size_t i = 0; i < threads_count; ++i) {
        std::thread t(summ_slice<int>, std::ref(first), std::ref(second), start, end);
        t.join();
        threads.push_back(std::move(t));
        start += batch_size;
        end += batch_size;
    }
}

int main(int argc, const char * argv[]) {
    
    // подготовка тестовых данных
    int cores_count = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    std::array<int, 4> vectors_length = {1000, 10000, 100000, 1000000};
    std::array<int, 5> threads_counts = {1, 2, 4, 8, 16};
    // debug
//    std::array<int, 1> vectors_length = {1000};
//    std::array<int, 1> threads_counts = {2};
    
    // вывод заголовка
    std::cout << "Количество аппаратных ядер - " << cores_count << std::endl;
    std::cout << "\n\t";
    for (auto el : vectors_length) {
        std::cout << "\t\t" << el;
    }
    std::cout << std::endl;
    
    // расчёты
    for (auto threads_count : threads_counts) {
    
        std::cout << threads_count << " потоков";
        for (auto lenght : vectors_length) {

            // генерация векторов
            std::vector<int> a(lenght);
            std::vector<int> b(lenght);
            for (size_t i = 0; i < lenght; ++i) {
                a[i] = rand() % 100;
                b[i] = rand() % 100;
            }

            // параллельное сложение
            auto start = std::chrono::steady_clock::now();
            parallel_sum(a, b, threads_count, threads);
            std::chrono::duration<double> time_diff = std::chrono::steady_clock::now() - start;
            std::cout << "\t" << time_diff.count();

        }
        std::cout << std::endl;
    }
    return 0;
}
