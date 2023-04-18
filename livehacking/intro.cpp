#include <map>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>
#include <memory>
#include <variant>
#include <unistd.h>

using namespace std;

using namespace std::chrono_literals;



       // int sigaction(int signum, const struct sigaction *restrict act,
       //               struct sigaction *restrict oldact);

       //         void     (*sa_handler)(int);

int main()
{
    bool quit = false;
    
    using todo_item = variant<function<void()>, shared_ptr<thread>>;
    using todo_list = map<string, todo_item>;

    todo_list tdl = {
        { "up 1 to 10",
          {
              [&quit](){
                  for (int i=1; i<=10; i++) {
                      cout << "UP: " << i << endl;
                      std::this_thread::sleep_for(1s);
                      if (quit)
                          break;
                  }
              },
              nullptr,
          }
        },
        { "down 1000 to 980",
          {
              [&quit](){
                  for (int i=1000; i>=980; i--) {
                      cout << "DOWN: " << i << endl;
                      std::this_thread::sleep_for(0.5s);
                      if (quit)
                          break;
                  }
              },
              nullptr,
          },
        },
    };

    // start todo list
    for (auto& [name, item]: tdl) {
        std::cout << "Start NAME: " << name << std::endl;
        auto func = item.first;
        item.second = shared_ptr<thread>(new thread(func));
    }

    // ARGHHH!!!!
    sleep(3);
    cout << "Requesting termination ..." << endl;
    quit = true;

    // wait for threads
    cout << "Waiting for termination ... " << endl;
    for (auto& [name, item]: tdl) {
        std::cout << "Wait for NAME: " << name << std::endl;
        item.second->join();
    }

    return 0;
}
