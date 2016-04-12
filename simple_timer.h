#include <iostream>

#include <boost/thread/thread.hpp>

class SimpleTimer
{
public:
    SimpleTimer(int secs, void (*callback)());
    virtual ~SimpleTimer();

private:
    void Handler(int secs, void (*callback)());

private:
    boost::thread t_;
};
