#pragma once
#ifndef __HASHMAP_H__
#define __HASHMAP_H__
#include <map>
#include <vector>

static unsigned int _stl_prime[] = {
    17, 33, 53, 97, 193, 389,
    769, 1543, 3079, 6151, 12289,
    24593, 49157, 98317, 196613, 393241,
    786433, 1572869, 3145739, 6291469, 12582917,
    25165843, 50331653, 100663319, 201326611, 402653189,
    805306457, 1610612741, 3221225473, 4294967291
};

template <class _Key, class _Value, class _Hash = std::hash<_Key>>
class hashmap {
    using Bucket = std::map<_Key, _Value>;
    using Key_Value = std::pair<_Key, _Value>;
private:
    std::vector<Bucket*> m_buckets;
    size_t m_size;
    size_t point;
    size_t hash(_Key key);
    void resize(size_t size);
public:
    hashmap();
    ~hashmap();
    class iterator {
    private:
        typename std::vector<Bucket*>::iterator bucket_it;
        typename Bucket::iterator entry_it;
        hashmap<_Key, _Value>* it;
    public:
        iterator(typename std::vector<Bucket*>::iterator bi,
            typename Bucket::iterator ei,
            hashmap<_Key, _Value>* _it)
            : bucket_it(bi), entry_it(ei), it(_it) {}
        ~iterator() = default;
        iterator& operator++();
        iterator operator++(int);
        Key_Value& operator*() const;
        Key_Value* operator->() const;
        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);
    };
    iterator begin();
    iterator end();
    typename Bucket::mapped_type& operator[](const _Key& key);
    void erase(const _Key& key);
    iterator erase(iterator it);
    iterator find(const _Key& key);
    size_t size();
    bool empty();
    void clear();
    hashmap& operator=(const hashmap& other);
    hashmap& operator=(hashmap&& other) noexcept;
};

#endif