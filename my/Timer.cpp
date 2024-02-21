#include <bits/stdc++.h>

class Timer {
private:
    std::chrono::system_clock::time_point begin;
public:
    Timer() { begin = std::chrono::system_clock::now(); }
    ~Timer() {
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration<double, std::nano>(end - begin).count();
        std::cout << "\nThe program takes: " << time / 1e9 << " s\n";
    }
};