#include<iostream>
#include<unordered_map>

#include<functional>
// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template
template <typename T>
inline void hash_combine(std::size_t *seed, const T &val) {
    unsigned int magic_constant = 0x9e3779b9;
    int shift_left = 6;
    int shift_right = 2;
    *seed ^= std::hash<T>()(val) + magic_constant + (*seed << shift_left) + (*seed >> shift_right);
    std::cout << "seed: " << *seed << ", val: " << val << std::endl;
}

template <typename T1, typename T2>
inline std::size_t hash_seed(const T1 &val1, const T2 &val2) {
    std::size_t seed = 0;
    hash_combine(&seed, val1);
    hash_combine(&seed, val2);
    return seed;
}

struct pair_hash_new {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_seed(p.first, p.second);
    }
};

int main() {
    std::unordered_map<std::pair<std::string, int>, double, pair_hash_new> container1;
    std::pair<std::string, int> c_key(std::string("a"), 1);
    std::pair<std::string, int> d_key(std::string("d"), 4);
    container1[c_key] = 3.3;
    container1[d_key] = 4.4;
    std::cout << container1[c_key] << std::endl;

    // seed: 14494284463268081198, val: d
    // seed: 12892177462070877926, val: 4
    // seed: 4993892637606504228, val: a
    // seed: 2415882023411841959, val: 1

    return 0;
}
