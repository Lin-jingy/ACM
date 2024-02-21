#include<bits/stdc++.h>

template<class T>
class vector {
private:
    T* a;//存放数据的容器
    size_t si;//当前的大小
    size_t mx;//容器的大小
    const int k = 2;
    void big() {//执行扩容
        T* mid = (T*)malloc(sizeof(T) * k * mx);
        memcpy(mid, a, mx * sizeof(T));
        mx = k * mx;
        free(a);
        a = mid;
    }
    void check() {
        if(si == mx) big();
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
        for(size_t i = 0; i < si; ++i) a[i] = val;
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
        if(si == 0) return false; 
        --si;
        return true;
    }
    bool empty() {
        if(si == 0) return true;
        else return false;
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
    T& operator[] (int i) {
        return a[i];
    }
    
};



template<class Q>
class priority_queue {
private:
    vector<Q> v;
    void swap(const int a, const int b) {
        Q mid = v[a];
        v[a] = v[b];
        v[b] = mid;
    }
    void push_up(int i) {
        while(i != 1) {
            if(v[i / 2] < v[i]) swap(i, i / 2);
            else break;
            i /= 2;
        }
    }
    void push_down(int i) {
        int n = v.size() - 1; 
        if(2 * i <= n and 2 * i + 1 <= n) {
            if(v[2 * i + 1] < v[2 * i]) {
                if(v[i] < v[2 * i]) swap(i, 2 * i), push_down(2 * i);
            }
            else if(v[2 * i] < v[2 * i + 1]) {
                if(v[i] < v[2 * i + 1]) swap(i, 2 * i + 1), push_down(2 * i + 1);
            } 
            else {
                if(v[i] < v[2 * i]) swap(i, 2 * i), push_down(2 * i);
            }
        }else if(2 * i <= n) {
            if(v[i] < v[2 * i]) swap(i, 2 * i);
        }

    }
public:
    priority_queue() {
        Q x;
        v.push_back(x);
    }
    void push(Q a) {
        v.push_back(a);
        push_up(v.size() - 1);
    }
    bool pop() {
        if(v.size() == 1) return false;
        swap(1, v.size() - 1);
        v.pop_back();
        push_down(1);
        return true;
    }   
    size_t size() {
        return v.size() - 1;
    }
    bool empty() {
        if(v.size() == 1) return true;
        else return false;
    }
    Q top() {
        return v[1];
    }
};