#include <bits/stdc++.h>

template <typename T>
class vector{
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
public:
    vector() : m_data(nullptr), m_size(0), m_capacity(0) {}
    vector(size_t size) {
        m_size = size;
        m_capacity = size;
        m_data = (T*)malloc(m_capacity * sizeof(T));
    }
    vector(size_t size, const T& value) {
        m_size = size;
        m_capacity = size;
        m_data = (T*)malloc(m_capacity * sizeof(T));
        for(size_t i = 0; i < m_size; ++i) m_data[i] = value;
    }
    vector(const vector<T> &other) {
        m_size = other.m_size;
        m_capacity = other.m_size;
        m_data = (T*)malloc(m_capacity * sizeof(T));
        memcpy(m_data, other.m_data, m_size * sizeof(T));
    }
    ~vector() {
        if(m_data != nullptr) free(m_data);
    }
    
    T& at(size_t pos) {
        if(pos >= m_size) throw std::out_of_range("array out of range");
        return m_data[pos];
    }
    T& operator[](size_t pos) {
        return m_data[pos];
    }
    T& front() {
        return m_data[0];
    }
    T& back() {
        return m_data[m_size - 1];
    }
    T* data() {
        return m_data;
    }
    bool empty() {
        return m_size == 0;
    }
    size_t size() {
        return m_size;
    }
    size_t capacity() {
        return m_capacity;
    }
    void reserve(size_t size) {
        if(size <= m_capacity) return;
        T *copy_data = (T*)malloc(m_capacity * sizeof(T));
        memcpy(copy_data, m_data, m_size * sizeof(T));
        free(m_data);
        m_data = copy_data;
    }
    void clear() {
        if(m_data != nullptr) free(m_data), m_data = nullptr;
        m_size = 0;
        m_capacity = 0;
    }
    void push_back(const T& value) {
        if(m_size + 1 >= m_capacity) {
            if(m_capacity == 0) m_capacity = 1;
            else m_capacity *= 2;
            T *copy_data = (T*)malloc(m_capacity * sizeof(T));
            memcpy(copy_data, m_data, m_size * sizeof(T));
            free(m_data);
            m_data = copy_data;
        }
        m_data[m_size++] = value;
    }
    void pop_back() {
        m_size--;
    }
    void erase(size_t pos) {
        memove(m_data + pos, m_data + pos + 1, m_size - pos);
        --m_size;
    }

    void assign(size_t size, const T &value) {
        clear();
        m_size = size;
        m_capacity = size;
        m_data = (T*)malloc(m_capacity * sizeof(T));
        for(size_t i = 0; i < m_size; ++i) m_data[i] = value;
    }


    void swap(vector<T> &other) {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_data, other.m_data);
    }

    void operator= (const vector<T> &other) {
        clear();
        m_size = other.m_size;
        m_capacity = other.m_size;
        m_data = (T*)malloc(m_capacity * sizeof(T));
        memcpy(m_data, other.m_data, m_size * sizeof(T));
    }

    bool operator== (const vector<T> &other) {
        return memcmp(m_data, other.m_data, m_size * sizeof(T)) == 0;
    }
    bool operator!= (const vector<T> &other) {
        return memcmp(m_data, other.m_data, m_size * sizeof(T)) != 0;
    }

    friend std::ostream &operator<<(std::ostream &out, const vector<T> &arr) {
		for(int i = 0; i < arr.m_size; ++i) out << arr.m_data[i] << " ";
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
        return iterator(m_data + m_size);
    }
    iterator erase(iterator pos) {
        memove(pos + 1, pos, m_size - pos);
        return pos;
    }
};
