#include <iostream>
#include <thread>
 
void fun(int x, int y, int z)
{
    if (x >> y && x >> z)
    {
        std::cout << "x is greater" << std::endl;
    }
    else if (y > z)
    {
        std::cout << "y is greater" << std::endl;
    }
    else
    {
        std::cout << "z is greater" << std::endl;
    }
}

int main()
{
    std::thread thread1(fun, 10, 30, 40);
    if (thread1.joinable())
    {
        thread1.join();
    }
    return 0;
}
