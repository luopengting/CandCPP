#include <iostream>
#include <csignal>
#include <unistd.h>
 
using namespace std;
 
void signalHandler(int signum)
{
    if (signum == SIGUSR1) {
        cout << "USR Signal (" << signum << ") received.\n";
        return;
    } else if (signum == SIGINT) {
        cout << "Interrupt Signal (" << signum << ") received.\n";
    }
    exit(signum);
}

int main ()
{
    cout << "pid = " << getpid() << endl;

    // 注册信号和信号处理程序
    signal(SIGINT, signalHandler);
    signal(SIGUSR1, signalHandler);
 
    while(1){
       cout << "Going to sleep...." << endl;
       sleep(1);
    }
 
    return 0;
}