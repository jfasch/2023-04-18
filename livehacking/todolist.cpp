#include "todolist.h"

void TodoList::add_item(const std::string& name, std::function<void(std::atomic<bool>*)> func)
{
    _tdl[name] = func;
}

void TodoList::start()
{
    for (auto& [name, item]: _tdl) {
        std::cout << "Start NAME: " << name << std::endl;
        auto func = std::get<0>(item);
        // item = std::make_shared<std::thread>(func);
        item = std::shared_ptr<std::thread>(new std::thread(func, &_quit));
    }
}

void TodoList::wait()
{
    for (auto& [name, item]: _tdl)
        std::get<1>(item)->join();
}

void TodoList::quit()
{
    _quit = true;
}
