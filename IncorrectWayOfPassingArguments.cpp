#include <iostream>
#include <thread>

void fun(int* ptr)
{
    std::cout << "fun -> var value is: " << *ptr << std::endl; //Value of ptr is not available here
    *ptr = 20;
}
 
void startNewThread()
{
    int var = 10;
    std::thread obj1(fun, &var);
    std::cout << "startNewThread -> var value is: " << var << std::endl;
    obj1.detach();
}

int main()
{
    startNewThread();
    return 0;
}
