//
//  main.cpp
//  thread_safe_queue
//
//  Created by tkvitko on 27.05.2024.
//

#include <iostream>
#include <queue>
#include <mutex>
#include <vector>
#include <thread>


template <class T>
class SafeQueue {
    // очеред задач
public:
    
    void push(T func) {
        // добавить новую задачу в очередь
        std::lock_guard lock_guard(mutex_);
        queue_.push(func);
    }
    
    T pop() {
        // вынуть задачу из очереди
        auto task = queue_.front();
        queue_.pop();
        return task;
    }
    
    bool isEmpty() {
        // проверить, пуста ли очередь
        return queue_.empty();
    }
    
    
private:
    std::queue<T> queue_;   // внутренняя очередь для хранения задач
    std::mutex mutex_;      // мьютекс для блокировки на момент добалвения новой задачи в очередь
};


class ThreadPoolExecutor {
    // исполнитель задач в нескольких потоках
public:
    
    ThreadPoolExecutor() {
        const int cores_count = std::thread::hardware_concurrency();    // количество аппаратных ядер
        for (size_t i = 0; i != cores_count; ++i) {
            // наполнение вектора, хранящего потоки, задачами на обработку
            
            // не получается передать потоку задачу на выполнение
            // попробовал 2 варианта, справа он них указаны исключения комплитятора
            std::thread t(this->work);  // no matching constructor
            //std::thread t(work);    // reference to non-static member function must be called
            threadsPool_.push_back(t);
        }
    }
    
    ~ThreadPoolExecutor() {
        for (auto& thread : threadsPool_) {
            // ожидание окончания работы потоков
            thread.join();
        }
        threadsPool_.clear();
    }
    
    void submit (std::function<void()> func) {
        // добавление новой задачи в очередь задач
        tasksQueue_.push(func);
    }
    
    void work() {
        while (true) {
            if (!tasksQueue_.isEmpty()) {
                // если в очереди задач есть задачи, вынимаем одну и выполняем
                auto task = tasksQueue_.pop();
                task();
            } else {
                // иначе передаем управление другому потоку
                std::this_thread::yield();
            }
        }
    }

    
private:
    std::vector<std::thread> threadsPool_;          // вектор для хранения потоков обработки задач
    SafeQueue<std::function<void()>> tasksQueue_;   // очередь задач на обработку
    
};


void test_func1() {
    // тестовая функция 1
    std::cout << "Thread id: " << std::this_thread::get_id() << " Function: " << __FUNCTION__ << std::endl;
}

void test_func2() {
    // тестовая функция 2
    std::cout << "Thread id: " << std::this_thread::get_id() << " Function: " << __FUNCTION__ << std::endl;
}


int main(int argc, const char * argv[]) {

    ThreadPoolExecutor threadPool;  // объект исполнителя
    
    while (true) {
        // раз в секунду добавляем обе тестовые задачи в очередь на исполнение
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        threadPool.submit(test_func1);
        threadPool.submit(test_func2);
    }
    
    return 0;
}
