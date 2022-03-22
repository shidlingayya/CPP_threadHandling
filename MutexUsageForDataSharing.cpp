#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// mutex used to lock other threads from gaining access to shared resource
mutex m_mutex;

// shared print function for cout
void shared_print(char c, int v) {
    m_mutex.lock(); // locks other threads from using resource, uncomment to see ipc sequence complications
    cout << c << v << "\n";
    m_mutex.unlock(); // unlocks resource so that another thread can have access, uncomment to see ipc sequence complications
}

// function for sequence
void foo(char d, int a) {
    for (int i = 1; i <= a; i++) {
        shared_print(d, i);
    }
}

int main()
{
    thread th2(foo, 'A', 5); // child thread - 1
    thread th3(foo, 'B', 5); // child thread - 2

    th2.join(); // main thread, waits for child to finish
    th3.join(); // main thread, waits for child to finish
    return 0;
}