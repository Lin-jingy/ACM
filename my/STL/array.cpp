#include <bits/stdc++.h>

template <typename T, size_t N>
class array {
private:
    T m_data[N];
public:
    array() {}
    array(const array<T, N>&other) {
        memcpy(m_data, other.m_data, N * sizeof(T));
    }
    array(T *other) {
        memcpy(m_data, other, N * sizeof(T));
    }
    ~array() {}
    
    T& at(size_t pos) {
        if(pos >= N) throw std::out_of_range("array out of range");
        return m_data[pos];
    }
    T& operator[](size_t pos) {
        return m_data[pos];
    }
    T& front() {
        return m_data[0];
    }
    T& back() {
        return m_data[N - 1];
    }
    T* data() {
        return m_data;
    }
    bool empty() {
        return N == 0;
    }
    size_t size() {
        return N;
    }

    void swap(array<T, N> &other) {
        std::swap(m_data, other.m_data);
    }

    void operator= (const array<T, N> &other) {
        memcpy(m_data, other.m_data, N * sizeof(T));
    }

    void operator= (const T *other) {
        memcpy(m_data, other, N * sizeof(T));
    }

    bool operator== (const array<T, N> &other) {
        return memcmp(m_data, other.m_data, N * sizeof(T)) == 0;
    }
    bool operator!= (const array<T, N> &other) {
        return memcmp(m_data, other.m_data, N * sizeof(T)) != 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const array<T, N> &arr) {
		for(int i = 0; i < N; ++i) out << arr.m_data[i] << " ";
        return out;
	}

    class iterator {
    private:
        T *m_point;
    public:
        iterator() :m_point(nullptr){}
        iterator(T *point) :m_point(point){}
        ~iterator(){}
        bool operator== (const iterator &other){
            return m_point == other.m_point;
        }
        bool operator!= (const iterator &other){
            return m_point != other.m_point;
        }
        iterator operator= (const iterator &other){
            m_point = other.m_point;
            return *this;
        }
        iterator operator++(){
            ++m_point;
            return *this;
        }
        iterator operator++(int){
            iterator it = *this;
            ++m_point;
            return it;
        }
        iterator operator+(int i){
            m_point += i;
            return *this;
        }
        iterator& operator+=(int i){
            m_point += i;
            return *this;
        }
        iterator operator-(int i){
            m_point -= i;
            return *this;
        }
        iterator& operator-=(int i){
            m_point -= i;
            return *this;
        }
        size_t operator- (const iterator &other) {
            return m_point - other.m_point;
        }
        T& operator*(){
            return *m_point;
        }
        T* operator->(){
            return m_point;
        }
    };
    iterator begin() {
        return iterator(m_data);
    }
    iterator end() {
        return iterator(m_data + N);
    }

};
