//
//  main.cpp
//  swap_with_mutexes
//
//  Created by tkvitko on 13.05.2024.
//

#include <iostream>
#include <mutex>

// https://stackoverflow.com/questions/24272641/how-to-use-a-stdmutex-in-a-class-context

class Data {
public:
    int value;
    std::mutex mtx;
    
    Data (int value_) : value(value_) {};
};

void swap_lock(Data& data_0, Data& data_1) {
    std::lock(data_0.mtx, data_1.mtx);
    std::lock_guard(data_0.mtx);
    std::lock_guard(data_1.mtx);

    int tmp = data_0.value;
    data_0.value = data_1.value;
    data_1.value = tmp;
}

void swap_scoped_lock(Data& data_0, Data& data_1) {
    std::scoped_lock scoped_lock(data_0.mtx, data_1.mtx);
    int tmp = data_0.value;
    data_0.value = data_1.value;
    data_1.value = tmp;
}

void swap_uniq_lock(Data& data_0, Data& data_1) {
    std::unique_lock uniq_lock_0(data_0.mtx);
    std::unique_lock uniq_lock_1(data_1.mtx);
    std::lock(uniq_lock_0, uniq_lock_1);
    
    int tmp = data_0.value;
    data_0.value = data_1.value;
    data_1.value = tmp;
}

int main(int argc, const char * argv[]) {
    
    Data data_0(10);
    Data data_1(20);
    
    swap_lock(data_0, data_1);
    std::cout << "data_0: " << data_0.value << "\ndata_1: " << data_1.value << std::endl;
    
    swap_scoped_lock(data_0, data_1);
    std::cout << "data_0: " << data_0.value << "\ndata_1: " << data_1.value << std::endl;
    
    swap_uniq_lock(data_0, data_1);
    std::cout << "data_0: " << data_0.value << "\ndata_1: " << data_1.value << std::endl;
    
    return 0;
}
