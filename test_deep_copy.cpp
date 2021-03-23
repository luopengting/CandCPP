#include<vector>
#include<memory>

struct Address {
  Address() {}
  Address(void *address_addr, size_t address_size) : addr(address_addr), size(address_size) {}
  void *addr;
  size_t size;
};
using AddressPtr = std::shared_ptr<Address>;

using AddressPtrList = std::vector<AddressPtr>;
struct GPUMemInfo {
  AddressPtrList *inputs_;
  AddressPtrList *workspaces_;
  AddressPtrList *outputs_;
};

int main() {
    int a[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 0; i < 9; i++) {

    }

    return 0;
}
