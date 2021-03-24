#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
class Base {
  public:
    Base() {}
    ~Base() {}
    int cnt = 0;
    void PrintValue() {
        std::cout << "Base cnt: " << cnt << std::endl;
    }
    virtual void Add() {
        cnt++;
    }
};
using BasePtr = std::shared_ptr<Base>;

class A: public Base {
  public:
    A() {}
    ~A() {}
    void PrintValue() {
        std::cout << "A cnt: " << cnt << std::endl;
    }
    void Add(int val) {
        cnt += val;
    }
};
using APtr = std::shared_ptr<A>;

class Manager {
  public:
    std::unordered_map<std::string, BasePtr> v;
    void AddInfo(const std::string &key, const BasePtr &info) { v[key] = info; }
    BasePtr &GetInfo(const std::string &key) { return v[key]; }
};

int main(){
    Manager manager = Manager();
    APtr a = std::make_shared<A>();
    a->Add(1);
    a->PrintValue();                   // 1
    std::string a_key = "a";
    manager.AddInfo(a_key, a);

    BasePtr b = manager.GetInfo(a_key);
    b->PrintValue();                   // 1

    APtr bb = std::dynamic_pointer_cast<A> (b);
    bb->PrintValue();                  // 1
    bb->Add(2);
    bb->PrintValue();                  // 3

    b->Add();
    b->PrintValue();                   // 4

    BasePtr c = manager.GetInfo(a_key);
    c->PrintValue();                   // 4

    return 0;
}
