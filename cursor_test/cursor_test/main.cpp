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
#include <ncurses.h>
#include <thread>



int main(int argc, const char * argv[]) {
    
    initscr();
    move(100, 100);
    printw("Hello world");
    refresh(); // обновить экран
//    std::cout << "1";
//    std::chrono::milliseconds timespan(1000);
//    std::this_thread::sleep_for(timespan);
//
//    move(0, 0);
//    std::cout << "2";
//    std::this_thread::sleep_for(timespan);
    
    
//    getch(); // ждём нажатия символа
//    endwin(); // завершение работы с ncurses

    return 0;
}
