#include <bits/stdc++.h>

template <bool print>
class Timer {
private:
    std::chrono::system_clock::time_point begin;
public:
    Timer() { begin = std::chrono::system_clock::now(); }
    ~Timer() {
        if(!print) return ;
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration<double, std::nano>(end - begin).count();
        std::clog << "\nThe program takes: " << time / 1e9 << " s\n";
    }
    double get() {
        auto end = std::chrono::system_clock::now();
        auto time = std::chrono::duration<double, std::nano>(end - begin).count();
        return time / 1e9;
    }
};