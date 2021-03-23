#include<iostream>
using namespace std;

void func(int n) {
    cout << "The number is: " << n << endl;
}

void wrapper_func(void* func, int n) {
    int n;
    cout << "wrap begin." << endl;
    func(n);
    cout << "wrap end." << endl;
}


int main() {
    wrapper_func();
    wrapper_func(2);
    return 0;
}