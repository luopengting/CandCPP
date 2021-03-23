#include <iostream>
#include <string>
#include <unordered_map>
class A {
 public:
  A() {}
  ~A() {}
  std::string &GetContainer(std::string name) { return container_[name]; };
  void Update(std::string name, std::string value) { container_[name] = value; }
  std::unordered_map<std::string, std::string> container_;
 private:
  
};

int main() {
    A a;
    a.Update("a", "a1");
    a.Update("b", "b1");

    std::string &s = a.GetContainer("a");
    s = "a2";

    std::cout << a.GetContainer("a") << std::endl;

    return 0;
}