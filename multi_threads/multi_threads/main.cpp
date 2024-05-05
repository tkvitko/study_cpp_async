//
//  main.cpp
//  multi_threads
//
//  Created by tkvitko on 05.05.2024.
//

#include <iostream>
#include <thread>

void add_clients(int& queue) {
    // появление нового клиента в очереди 1 раз в секунду
    int max_client = 10;
    for (size_t i=0; i < max_client; ++i) {
        queue += 1;
        std::cout << "new client! current queue: " << queue << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void process_clients(int& queue) {
    // обслуживание одного клиента в очереди 1 раз в 2 секунды
    while (queue != 0) {
        queue -= 1;
        std::cout << "client processed. current queue: " << queue << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main(int argc, const char * argv[]) {
    
    int queue = 0;
    std::thread clients(add_clients, std::ref(queue));
    clients.detach();
    std::thread operationist(process_clients, std::ref(queue));
    operationist.join();
    
    return 0;
}
