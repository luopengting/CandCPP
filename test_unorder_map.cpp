#include<iostream>
#include<unordered_map>

#include<functional>
// from boost (functional/hash):
// see http://www.boost.org/doc/libs/1_35_0/doc/html/hash/combine.html template
template <typename T>
inline void hash_combine(std::size_t &seed, const T &val) {
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    std::cout << "seed: " << seed << ", val: " << val << std::endl;
}
// auxiliary generic functions to create a hash value using a seed
template <typename T> inline void hash_val(std::size_t &seed, const T &val) {
    hash_combine(seed, val);
}
template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &... args) {
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &... args) {
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_val(p.first, p.second);
    }
};

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// 
// int main() {
//     unordered_map<pair<ll, ll>, ll, pair_hash> slopeCount;
//     unordered_set<pair<ll, ll>, pair_hash> seen;
//     return 0;
// }
// Reference: [C++ Standard Library: A tutorial and reference, Second version](https://www.mica.edu.vn/perso/Vu-Hai/EE3490/Ref/The%20C++Standard%20Library%20-%202nd%20Edition.pdf) Chapter 7.9.2: Creating and Controlling unordered Container


template <typename T1, typename T2>
inline std::size_t hash_seed(const T1 &val1, const T2 &val2) {
    std::size_t seed = 0;
    hash_combine(seed, val1);
    hash_combine(seed, val2);
    return seed;
}

struct pair_hash_new {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        return hash_seed(p.first, p.second);
    }
};

int main() {
    // can not work
    std::unordered_map<std::pair<std::string, int>, double, pair_hash> container;
    std::pair<std::string, int> a_key(std::string("a"), 1);
    std::pair<std::string, int> b_key(std::string("b"), 2);
    container[a_key] = 1.1;
    container[b_key] = 2.2;
    std::cout << container[a_key] << std::endl;

    std::size_t seed = 0;
    hash_combine(seed, std::string("a"));
    hash_combine(seed, 1);
    std::cout << seed << std::endl;

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
