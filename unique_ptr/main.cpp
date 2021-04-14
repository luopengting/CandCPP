#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  A(int val) { val_ = val; }
  ~A() {}
private:
  int val_;
};

class B {
public:
  B() {}
  ~B() {}
private:
  std::vector<std::unique_ptr<A>> vec_;
};

int main() {
    {
        std::unique_ptr<int> uptr(new int(10));  //绑定动态对象
        //std::unique_ptr<int> uptr2 = uptr;  //不能賦值
        //std::unique_ptr<int> uptr2(uptr);  //不能拷貝
        std::unique_ptr<int> uptr2 = std::move(uptr); //轉換所有權
        uptr2.release(); //释放所有权
    }
    //超過uptr的作用域，內存釋放

    std::vector<std::unique_ptr<A>> vec;  // OK
    vec.push_back(std::unique_ptr<A>(new A(0)));  // OK

    // B b = B(); // 报错，因为赋值进行了拷贝构造
    B b;
    auto c = std::make_shared<B>(); // OK

    return 0;
}