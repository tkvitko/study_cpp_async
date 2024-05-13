//
//  main.cpp
//  parallel_calculations
//
//  Created by tkvitko on 12.05.2024.
//

/*
 Progress bar выполнения расчетов в нескольких потоках
 */
 
#include <iostream>
#include <vector>
#include <array>
#include <thread>
#include <random>
#include <termios.h>


void make_and_draw() {
    auto start = std::chrono::steady_clock::now();
    
    int len = 10;
    int position = 0;
    while (position < len) {
        for (size_t i = 0; i < position; ++i) {
            std::cout << "\u2588";
        }
        std::chrono::milliseconds timespan(100);
        std::this_thread::sleep_for(timespan);
        std::cout << "\r";
        position++;
        if (position != len) {
            std::cout.flush();
        }
    }
    
    std::chrono::duration<double> time_diff = std::chrono::steady_clock::now() - start;
    std::cout << "\t" << time_diff.count();
}


int main(int argc, const char * argv[]) {
    
    std::vector<std::thread> threads;
    int threads_count = 4;
    
    for (size_t i = 0; i < threads_count; ++i) {
        std::thread t(make_and_draw);
        std::cout << "\n" << i << " " << t.get_id();
        t.join();
        threads.push_back(std::move(t));
    }

    return 0;
}
