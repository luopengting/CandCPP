#include<vector>
#include<iostream>

int main() {
  std::vector<int> a = {1, 2, 3};
  std::vector<int> b;

//   for( int i=0; i<10; i++ ) {
//     a.push_back(i);
//   }
  a.insert(a.end(), b.begin(), b.end());

  for(int i = 0; i < a.size(); i++) {
    std::cout << a[i] << std::endl;
  }

  std::cout << "---" << std::endl;

  std::vector<int> c = {4, 5, 6};
  a.insert(a.end(), c.begin(), c.end());

  for(int i = 0; i < a.size(); i++) {
    std::cout << a[i] << std::endl;
  }

  std::cout << "---" << std::endl;

  b.insert(b.end(), a.begin(), a.end());

  for(int i = 0; i < b.size(); i++) {
    std::cout << b[i] << std::endl;
  }

  return 0;
}
