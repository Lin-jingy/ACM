#include <bits/stdc++.h>

template <class _Key, class _Value>
class Biunordered_map {
private:
    std::unordered_map<_Key, _Value> K_V;
    std::unordered_map<_Value, _Key> V_K;
public:
    Biunordered_map() = default;
    ~Biunordered_map() = default;
    void insert(const _Key &key, const _Value &value) {
        K_V.insert({key, value});
        V_K.insert({value, key});
    }
    std::optional<_Key> findKey(const _Value &value) const {
        auto it = V_K.find(value);
        if(it == V_K.end()) return std::nullopt;
        return it->second;
    }
    std::optional<_Value> findValue(const _Key &key) const {
        auto it = K_V.find(key);
        if(it == K_V.end()) return std::nullopt;
        return it->second;
    }
    void erase(const _Key &key, const _Value value) {
        K_V.erase(key);
        V_K.erase(value);
    }
};