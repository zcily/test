#include <iostream>
#include <ctime>
#include <unistd.h>
#include <sys/time.h>

using namespace std;

double getCurrentTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / (1000.0 * 1000.0);
}

int main(int argc, char**argv)
{
    double time_old = getCurrentTime();
    usleep(1000 * 1000 * 2);
    double time_now = getCurrentTime();
    cout << "time : " << time_now - time_old << endl;
    return 0;
}
