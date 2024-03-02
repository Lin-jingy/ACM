#include <bits/stdc++.h>

template <typename KEY, typename VALUE, typename HASH = std::hash<KEY>>
class unordered_map {
    using Point = std::map<KEY*, VALUE*>*;
    #define FACTOR ((float)0.75)
private:
    size_t m_size;
    size_t m_capacity;
    Point *m_data;
    int hashcode(const KEY &key) {
        int code = HASH(key);
        return (code ^ (code >> 16)) % m_capacity;
    }
    void Expand() {
        if(m_capacity == 0) {
            m_capacity = 1 << 4;
            m_data = new Point[m_capacity];
        }else if(m_capacity * FACTOR < m_data) {
            m_capacity <<= 1;
            Point *mid_data = new Point[m_capacity];
            //TODO
        }
    }
    
public:
    unordered_map() {
        m_size = 0;
        m_capacity = 0;
        m_data = nullptr;
    }
    ~unordered_map() {
        for(int i = 0; i < m_size; ++i) {
            if(!m_data[i]) continue;
            for(auto &[key, value] : m_data[i]) {
                delete key;
                delete value;
            }
        }
        m_size = 0;
        m_capacity = 0;
    }
    void insert(std::pair<KEY*, VALUE*> &node) {
        //TODO
    }


};

int main() {
    std::hash<std::string> H;
    size_t hashcode = H("123123");
}