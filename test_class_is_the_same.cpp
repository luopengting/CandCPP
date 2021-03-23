#include<iostream>
class A {};
class B {};
class C : A {};
class D : A {};

bool is_the_same(A a, A b) {
    return typeid(a).hash_code() == typeid(b).hash_code();
}

int main() {
    A a;
    B b;
    C c;
    D d;
    std::cout << "a and b: " << (typeid(a).hash_code() == typeid(b).hash_code()) << std::endl;
    std::cout << "a and c: " << (typeid(a).hash_code() == typeid(c).hash_code()) << std::endl;
    std::cout << "c and d: " << (typeid(a).hash_code() == typeid(c).hash_code()) << std::endl;
    return 0;
}