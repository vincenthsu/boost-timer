#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/mutex.hpp>

#include "simple_timer.h"

SimpleTimer::SimpleTimer(int secs, void (*callback)())
    : t_(boost::bind(&SimpleTimer::Handler, this, secs, callback))
{
    std::cout << "> Timer create" << std::endl;
}

SimpleTimer::~SimpleTimer()
{
    t_.interrupt();
    std::cout << "> Timer destory" << std::endl;
}

void SimpleTimer::Handler(int secs, void (*callback)())
{
    std::cout << "> Timer start to wait for " << secs << " secs." << std::endl;

    boost::posix_time::ptime now =
        boost::posix_time::second_clock::local_time();

    try {
        boost::this_thread::sleep_for(boost::chrono::seconds(secs));
        std::cout << "> Timer run callback" << std::endl;
        callback();
    }
    catch (...) {
        boost::posix_time::ptime tick =
            boost::posix_time::second_clock::local_time();
        std::cout << "> Timer is interrupted when running "
            << (tick - now).total_seconds() << " secs" << std::endl;
    }

    std::cout << "> Timer stop" << std::endl;
}
