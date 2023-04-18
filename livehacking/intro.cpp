#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>
#include <variant>
#include <unistd.h>

using namespace std::chrono_literals;

class TodoList final
{
public:
    TodoList() = default;
    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;

    void add_item(const std::string& name, std::function<void()> func)
    {
        _tdl[name] = func;
    }

    void start()
    {
        for (auto& [name, item]: _tdl) {
            std::cout << "Start NAME: " << name << std::endl;
            auto func = std::get<0>(item);
            item = std::make_shared<std::thread>(func);
        }
    }

    void wait()
    {
        for (auto& [name, item]: _tdl)
            std::get<1>(item)->join();
    }

private:
    using todo_item = std::variant<std::function<void()>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list _tdl;
};



int main()
{
    bool quit = false;
    
    TodoList tdl;
    tdl.add_item("up 1 to 10",
                 [&quit](){
                     for (int i=1; i<=10; i++) {
                         std::cout << "UP: " << i << std::endl;
                         std::this_thread::sleep_for(1s);
                         if (quit)
                             break;
                     }
                 });
    tdl.add_item("down 1000 to 980",
                 [&quit](){
                     for (int i=1000; i>=980; i--) {
                         std::cout << "DOWN: " << i << std::endl;
                         std::this_thread::sleep_for(0.5s);
                         if (quit)
                             break;
                     }
                 });


    tdl.start();

    // ARGHHH!!!!
    // sleep(3);
    // cout << "Requesting termination ..." << endl;
    // quit = true;

    std::cout << "Waiting for termination ... " << std::endl;
    tdl.wait();

    return 0;
}
