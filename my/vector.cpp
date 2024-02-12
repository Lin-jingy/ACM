#include <bits/stdc++.h>

template <class T>
class vector {
private:
    T* a;       // 存放数据的容器
    size_t si;  // 当前的大小
    size_t mx;  // 容器的大小
    const int k = 1.5;
    void big() {  // 执行扩容
        T* mid = (T*)malloc(sizeof(T) * k * mx);
        memcpy(mid, a, mx * sizeof(T));
        mx = k * mx;
        free(a);
        a = mid;
    }
    void check() {
        if (si == mx) big();
    }

public:
    vector() {
        mx = 100;
        si = 0;
        a = (T*)malloc(sizeof(T) * mx);
    }
    vector(size_t x) {
        si = x;
        mx = si;
        a = (T*)malloc(sizeof(T) * mx);
    }
    vector(size_t x, T val) {
        si = x;
        mx = si;
        a = (T*)malloc(sizeof(T) * mx);
        for (size_t i = 0; i < si; ++i) a[i] = val;
    }
    ~vector() {
        free(a);
    }
    void push_back(T x) {
        check();
        ++si;
        a[si - 1] = x;
    }
    bool pop_back() {
        if (si == 0) return false;
        --si;
        return true;
    }
    bool empty() {
        if (si == 0)
            return true;
        else
            return false;
    }
    T front() {
        return a[0];
    }
    T back() {
        return a[si - 1];
    }
    void clear() {
        free(a);
        si = 0;
        mx = 100;
        a = (T*)malloc(sizeof(T) * mx);
    }
    size_t size() {
        return si;
    }
    T& operator[](int i) {
        return a[i];
    }
};
