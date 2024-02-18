#include <iostream>
#include <vector>

namespace in {
    template<typename T>
    static void input(T &x) {
        std::cin >> x;
    }
    static void input(std::vector<int> &p) {
        int x;
        std::cin >> x;
        p.push_back(x);
    }
}