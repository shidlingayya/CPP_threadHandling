#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>
class Example
{
public:
    void operator ()()
    {
        std::cout << "Worker Thread " << std::this_thread::get_id() << " is Executing" << std::endl;
    }
};

int main()
{
    std::vector<std::thread> thread_list;
    for (auto i = 0; i < 5; i++)
    {
        thread_list.push_back(std::thread(Example()));
    }

    std::for_each(thread_list.begin(), thread_list.end(), std::mem_fn(&std::thread::join));

    return 0;
}
