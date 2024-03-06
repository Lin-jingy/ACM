#include <bits/stdc++.h>

template<typename KEY, typename VALUE>
class hash_map {
    using Bucket = std::map<KEY, VALUE>;
    using BucketPtr = std::unique_ptr<Bucket>;

private:
    std::vector<BucketPtr> buckets;
    size_t m_size;
    size_t m_capacity;
    size_t hash(KEY key) {
        return std::hash<KEY>()(key);
    }
    
    void resize(size_t new_capacity) {
        std::vector<BucketPtr> new_buckets(new_capacity);
        for(size_t i = 0; i < m_capacity; ++i) {
            if(buckets[i]) {
                for(auto& [_key, _value] : *buckets[i]) {
                    size_t new_hashcode = hash(_key) % new_capacity;
                    if(!new_buckets[new_hashcode]) new_buckets[new_hashcode].reset(new Bucket());
                    new_buckets[new_hashcode]->insert({_key, _value});
                }
            }
        }
        std::swap(buckets, new_buckets);
        m_capacity = new_capacity;
    }
    
public:
    hash_map() : buckets(16), m_size(0), m_capacity(16) {}

    ~hash_map() = default;
    
    size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    bool count(const KEY& key) const {
        size_t hashcode = hash(key) % m_capacity;
        return buckets[hashcode] && buckets[hashcode]->count(key);
    }

    class iterator {
    private:
        typename std::vector<BucketPtr>::iterator bucket_it;
        typename Bucket::iterator map_it;
        const hash_map<KEY, VALUE>* owner;

    public:
        iterator(typename std::vector<BucketPtr>::iterator b_it,
                 typename Bucket::iterator m_it,
                 const hash_map<KEY, VALUE>* owner_ptr)
            : bucket_it(b_it), map_it(m_it), owner(owner_ptr) {}

        iterator& operator++() {
            ++map_it;
            if(map_it == bucket_it->end()) {
                ++bucket_it;
                while(bucket_it != owner->buckets.end() && !bucket_it->get()) {
                    ++bucket_it;
                }
                if(bucket_it != owner->buckets.end()) {
                    map_it = bucket_it->begin();
                }
            }
            return *this;
        }

        bool operator==(const iterator& other) const {
            return bucket_it == other.bucket_it && map_it == other.map_it;
        }

        bool operator!=(const iterator& other) const {
            return !(*this == other);
        }

        std::pair<const KEY&, VALUE&> operator*() const {
            return {*map_it.first, map_it.second};
        }

        const KEY& operator->() const {
            return *map_it.first;
        }

        iterator& operator--() {
            if(map_it == bucket_it->begin()) {
                --bucket_it;
                while(bucket_it != owner->buckets.begin() && !bucket_it->get()) {
                    --bucket_it;
                }
                if(bucket_it != owner->buckets.begin()) {
                    map_it = bucket_it->end();
                }
            }
            --map_it;
            return *this;
        }

        iterator erase() {
            bucket_it->erase(map_it++);
            if(map_it == bucket_it->end()) {
                while(bucket_it != owner->buckets.end() && !bucket_it->get()) {
                    ++bucket_it;
                }
                if(bucket_it != owner->buckets.end()) {
                    map_it = bucket_it->begin();
                }
            }
            --owner->m_size;
            return *this;
        }
    };

    iterator begin() {
        for(auto it = buckets.begin(); it != buckets.end(); ++it) {
            if(it->get()) {
                return iterator(it, it->get()->begin(), this);
            }
        }
        return end();
    }

    iterator end() {
        return iterator(buckets.end(), typename Bucket::iterator(), this);
    }

    void erase(const KEY& key) {
        size_t hashcode = hash(key) % m_capacity;
        if(buckets[hashcode]) {
            buckets[hashcode]->erase(key);
            if(buckets[hashcode]->empty()) {
                buckets[hashcode].reset(); // 释放空的Bucket
            }
        }
    }

    iterator erase(iterator pos) {
        --m_size;
        return pos.erase();
    }

    iterator operator[] (const KEY& key) {
        size_t hashcode = hash(key) % m_capacity;
        if(!buckets[hashcode]) {
            buckets[hashcode].reset(new Bucket());
        }
        if(!buckets[hashcode]->count(key)) {
            ++m_size;
        }
        if(m_size > m_capacity * 0.75) {
            resize(m_capacity * 2);
            hashcode = hash(key) % m_capacity; // 重新计算哈希码
        }
        return iterator(buckets[hashcode], buckets[hashcode][key], this);
    }
};

int main() {
    hash_map<int, int> mp;
    mp[0] = 1;
    mp.erase(mp.begin());

}