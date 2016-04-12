#include "simple_timer.h"

bool g_run;

void TimesUp()
{
    std::cout << "Callback in main thread: Time's up" << std::endl;
    g_run = false;
}

int main(int argc, char *argv[])
{
    std::cout << "\n===== Test 1 =====\n" << std::endl;
    g_run = true;
    int i = 0;

    std::cout << "T1: Start a timer for 5 secs" << std::endl;
    SimpleTimer *tr1 = new SimpleTimer(5, &TimesUp);

    std::cout << "T1: Main thread wait for 1 secs" << std::endl;
    sleep(1);

    std::cout << "T1: Time count: " << ++i << std::endl;

    std::cout << "T1: Force to delete timer at " << i  << " secs" << std::endl;
    delete tr1;

    sleep(1);

    std::cout << "\n===== Test 2 =====\n" << std::endl;
    g_run = true;
    i = 0;

    std::cout << "T2: Start a timer for 10 secs" << std::endl;
    SimpleTimer tr2(10, &TimesUp);

    std::cout << "T2: Main thread wait for timer" << std::endl;
    while(g_run) {
        sleep(1);
        std::cout << "T2: Time count: " << ++i << std::endl;
    }

    return 0;
}
