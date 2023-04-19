#include "todolist.h"
#include <signal.h>
#include <unistd.h>

using namespace std::chrono_literals;


TodoList* argh_the_todo_list_for_quit = nullptr;

void quit_handler(int signal)
{
    const char msg[] = "now slowly terminating ...";
    write(STDOUT_FILENO, msg, sizeof(msg));
    if (argh_the_todo_list_for_quit)
        argh_the_todo_list_for_quit->quit();
}

void yet_another_todo_item(std::atomic<bool>* quit)
{
    for (int i=0; i<1000; i++) {
        std::cout << "hallo" << std::endl;
        std::this_thread::sleep_for(1s);
        if (*quit)
            break;
    }
}
int main()
{
    TodoList tdl;
    argh_the_todo_list_for_quit = &tdl;

    signal(SIGINT, quit_handler);

    tdl.add_item("up 1 to 10",
                 [](std::atomic<bool>* quit){
                     for (int i=1; i<=10; i++) {
                         std::cout << "UP: " << i << std::endl;
                         std::this_thread::sleep_for(1s);
                         if (*quit)
                             break;
                     }
                 });
    tdl.add_item("down 1000 to 980",
                 [](std::atomic<bool>* quit){
                     for (int i=1000; i>=980; i--) {
                         std::cout << "DOWN: " << i << std::endl;
                         std::this_thread::sleep_for(0.5s);
                         if (*quit)
                             break;
                     }
                 });
    tdl.add_item("yet another", yet_another_todo_item);

    tdl.start();

    // ARGHHH!!!!
    // sleep(3);
    // cout << "Requesting termination ..." << endl;
    // quit = true;

    std::cout << "Waiting for termination ... " << std::endl;
    tdl.wait();

    return 0;
}
