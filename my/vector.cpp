#include <bits/stdc++.h>
#include <stdexcept>

namespace STL{


template <typename T>
class vector {
public:
    vector();
    ~vector();
    void push_back(const T& value);
    void pop_back();
    T& at(size_t pos);
    T& operator[] (size_t pos);
    T& front();
    T& back();
    bool empty();
    size_t size();
    void swap(vector<T> other);

private:
    T *data;
    size_t m_size;
    size_t m_capacity;
    void expand(size_t n);
};

template <typename T>
void vector<T>::expand(size_t n) {
    m_capacity = n;
    T *copy_data = new T[m_capacity];
    memcpy(copy_data, data, sizeof(data));
    delete[] data;
    data = copy_data;
}

template<typename T>
vector<T>::vector() {
    m_size = 0;
    m_capacity = 0;
}


template<typename T>
vector<T>::~vector() {
    m_size = 0;
    m_capacity = 0;
    delete[] data;
}

template<typename T>
void vector<T>::push_back(const T& value) {
    if(m_size == m_capacity) expand();
    data[m_size++] = value;
}

template<typename T>
void vector<T>::pop_back() {
    m_size--;
}

template<typename T>
T& vector<T>::at(size_t pos) {
    if(pos >= m_size) {
        throw std::out_of_range("out of range");
    }
    return data[pos];
}

template<typename T>
T& vector<T>::operator[](size_t pos) {
    return data[pos];
}

template<typename T>
T& vector<T>::front() {
    return data[0];
}

template<typename T>
T& vector<T>::back() {
    return data[m_size - 1];
}

template<typename T>
bool vector<T>::empty() {
    return m_size == 0;
}

template<typename T>
size_t vector<T>::size() {
    return m_size;
}

template<typename T>
void vector<T>::swap(vector<T> other) {
    
}


}

