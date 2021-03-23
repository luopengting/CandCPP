#include "class_constructor/a.h"
#include<iostream>

int main() {
    std::string b = "lpt";
    A aa = A(b);
    std::cout << aa.Value() << std::endl;
    return 0;
}