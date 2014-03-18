#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

using namespace std;


long getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec % 100 * 1000 * 1000 + tv.tv_usec;
}

int main(int argc, char**argv)
{
    time_t old_time, now_time;
    long time_old = getCurrentTime();
    usleep(1000 * 1000 * 2);
    long time_now = getCurrentTime();
    return 0;
}
