#include<string>

class A
{
private:
    std::string a_{""};
public:
    A(std::string a);
    ~A();
    std::string Value() { return a_; }
};
A::A(std::string a)
{
    a_ = a;
}
A::~A()
{
}
