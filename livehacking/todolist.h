#pragma once

#include <memory>
#include <iostream>
#include <map>
#include <variant>
#include <functional>
#include <thread>
#include <atomic>

class TodoList final
{
public:
    TodoList() { _quit = false; }
    TodoList(const TodoList&) = delete;
    TodoList& operator=(const TodoList&) = delete;

    // blah function: receive bool&, which points to a boolean
    // variable which is usually false, and is set to true once quit
    // has been requested.
    void add_item(const std::string& name, std::function<void(std::atomic<bool>*)> func);
    void start();
    void wait();
    void quit();

private:
    using todo_item = std::variant<std::function<void(std::atomic<bool>*)>, std::shared_ptr<std::thread>>;
    using todo_list = std::map<std::string, todo_item>;

    todo_list _tdl;
    std::atomic<bool> _quit;
};
