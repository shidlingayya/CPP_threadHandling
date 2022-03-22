#include <iostream>
#include <thread>

void fun1()
{
    std::cout << "fun1 got executed from " << std::this_thread::get_id() << std::endl;
}

void fun2()
{
    std::cout << "fun2 got executed from " << std::this_thread::get_id() << std::endl;
}

int main()
{
    std::thread thread1(fun1);
    std::thread thread2(fun2);
    std::cout << "Hello World!\n";
    thread1.join();
    thread2.join();
    return 0;
}
