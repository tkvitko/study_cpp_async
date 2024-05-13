//
//  main.cpp
//  multi_threads
//
//  Created by tkvitko on 05.05.2024.
//

/* Очередь клиентов
Приложение, которое имитирует очередь в окошко.
Первый поток имитирует клиента: раз в секунду он обращается к счётчику клиентов и увеличивает его на 1.
Второй поток имитирует операциониста: раз в 2 секунды он обращается к счётчику клиентов и уменьшает его на 1.
«Операционист» работает до последнего клиента.
 Счетчик клиентов и операции над ним атомарны.
*/


#include <iostream>
#include <thread>
#include <atomic>


void add_clients(std::atomic<int>& queue) {
    // появление нового клиента в очереди 1 раз в секунду
    int max_client = 10;
    for (size_t i=0; i < max_client; ++i) {
        queue++;
        std::cout << "new client! current queue: " << queue << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void process_clients(std::atomic<int>& queue) {
    // обслуживание одного клиента в очереди 1 раз в 2 секунды
    while (queue != 0) {
        queue--;
        std::cout << "client processed. current queue: " << queue << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}

int main(int argc, const char * argv[]) {
    
    std::atomic<int> queue = 0;
    std::thread clients(add_clients, std::ref(queue));
    clients.detach();
    std::thread operationist(process_clients, std::ref(queue));
    operationist.join();
    
    return 0;
}
