#ifndef __HASHMAP_H__
#define __HASHMAP_H__

#include <functional>
#include <vector>

template <class _Key, class _Value, class _Hash = std::hash<_Key>>
class unordered_map {
    struct hash_node {
        _Key key;
        _Value value;
        hash_node *next;
    };
private:
    hash_node* m_buckets;
    size_t m_size;
    size_t m_capacity;
public:
    unordered_map(): m_buckets(nullptr), m_size(0), m_capacity(0) {}
    ~unordered_map();
    class iterator {
    private:
        hash_node* node;
        hash_node* bucket_pos;
    public:
        iterator(hash_node* _node, hash_node* _bucket_pos): node(_node), bucket_pos(_bucket_pos) {}
        ~iterator() = default;
        iterator& operator++();
        iterator operator++(int);
        _Value& operator*() const;
        _Value* operator->() const;
        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);
    };
    iterator begin();
    iterator end();
    _Value& operator[](const _Key& key);
    void erase(const _Key& key);
    iterator erase(iterator it);
    iterator find(const _Key& key);
    size_t size();
    bool empty();
    void clear();
    unordered_map& operator=(const unordered_map& other);
    unordered_map& operator=(unordered_map&& other) noexcept;
    
};


#endif