#include <bits/stdc++.h>
#include <chrono>
#include "my/Timer.cpp"



int main (){
    Timer _;
    int k = time(0);
    int sum = 0;
    for(int i = 1; i <= 1e8; ++i) {
        k = k >> 21 ^ 32 | 22;
        sum += k;
    }
    std::cout << sum << '\n';
}