#include <iostream>
#include <vector>
#include <thread>
void fun1()
{
    std::cout << " Thread " << std::this_thread::get_id() << " is invoked" << std::endl;
}

int main()
{
    std::thread thread1(fun1);
    thread1.join();
    thread1.join(); //Program will crash
    return 0;
}
