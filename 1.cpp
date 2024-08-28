#include <bits/stdc++.h>

int main() {
    std::allocator<int> alloc;
    int *p = alloc.allocate(1);
    *p = 10;
    std::cout << *p << '\n';
    alloc.deallocate(p, 1);
}