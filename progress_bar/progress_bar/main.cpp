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
#include <mutex>
#include <ncurses.h>

std::mutex gMutex;

void draw(int row_number) {
    auto start = std::chrono::steady_clock::now();
    
//    move(row_number, 0);
    int len = 10;
    int position = 0;
    while (position < len) {
        for (size_t i = 0; i < position; ++i) {
            std::cout << "\u2588";
        }
        refresh();
        move(row_number, 0);
        int sleep_milli_seconds = rand() % 1000;
        std::chrono::milliseconds timespan(sleep_milli_seconds);
        std::this_thread::sleep_for(timespan);
        gMutex.lock();
        std::cout << "\r";
        position++;
        if (position != len) {
            std::cout.flush();
        }
        gMutex.unlock();
    }
    
    std::chrono::duration<double> time_diff = std::chrono::steady_clock::now() - start;
    std::cout << "\t" << time_diff.count();
}


int main(int argc, const char * argv[]) {
    
    initscr();
    int row, col;
    getmaxyx(stdscr, row, col);
    std::vector<std::thread> threads;
    int threads_count = 4;
    
    for (size_t i = 0; i < threads_count; ++i) {
        std::thread t(draw, i);
        std::cout << "\n" << i << " " << t.get_id();
        threads.push_back(std::move(t));
    }
    for (auto& el : threads) {
        el.join();
    }
    endwin();
    return 0;
}
