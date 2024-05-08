//
//  main.cpp
//  threads_test
//
//  Created by tkvitko on 07.05.2024.
//

#include <iostream>
#include <vector>
#include <thread>


template <class T>
void summ_slice(std::vector<T>& first, std::vector<T>& second, int start, int end) {
    for (int i = start; i < end; ++i) {
        first[i] += second[i];
    }
}


int main(int argc, const char * argv[]) {
    
    auto cores_count = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {10, 20, 30};
    
    int batch_size = static_cast<int>(a.size() / cores_count);
    int start = 0;
    int end = batch_size;
    std::thread t(summ_slice<int>, std::ref(a), std::ref(b), start, end);
    threads.push_back(std::move(t));
    
    return 0;
}
