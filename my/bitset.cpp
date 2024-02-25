#include <bits/stdc++.h>

class bitset {
private:
    std::vector<std::bitset<64>> m_data;
    size_t m_size;
public:
    bitset(size_t size) {
        m_size = size;
        m_data.assign(m_size / 64 + 1, {});
    }
    ~bitset();

    std::bitset<64>::reference operator[](size_t pos) { 
        return m_data[pos / 64][pos % 64]; 
    }

    bool any() const {
        for(auto i:m_data) if(i.any()) return true;
        return false;
    }

    bool all() const {
        for(auto i:m_data) if(!i.all()) return false;
        return true;
    }

    bool none() const {
        for(auto i:m_data) if(!i.none()) return false;
        return true;
    }

    size_t count() const{
       size_t sum = 0;
       for(auto i:m_data) sum += i.count();
       return sum;
    }

    constexpr size_t size() const noexcept {
        return m_size;
    }

};
