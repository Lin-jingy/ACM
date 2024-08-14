#include <bits/stdc++.h>


template <size_t base = 26>
class tril {
    using Func = std::function<int(const char)>;
private:
    std::vector<std::array<int, base>> next;
    std::vector<int> exist;
    Func func;
    static int ch(const char x) { return x - 'a'; }
public:
    tril(Func function = ch):next(1), exist(1) {
        func = function;
    }

    void insert(const std::string &s) {
        int p = 0;
        for(auto i:s) {
            int c = func(i);
            if(!next[p][c]) 
                next[p][c] = next.size(), next.emplace_back(), exist.emplace_back();
            p = next[p][c];
        }
        exist[p] = 1;
    }
    int find(const std::string &s) {
        int p = 0;
        for(auto i:s) {
            int c = func(i);
            if(!next[p][c]) return 0;
            p = next[p][c];
        }
        return exist[p];
    }
};

template <size_t base = 26>
class point_tril {
private:
    struct tril_node {
        int count;
        std::array<tril_node *, base> next;
    };
    tril_node *root; 
public:
    point_tril() {
        root = new tril_node();
    }
    ~point_tril() {
        auto dfs = [&](auto self, tril_node *p) {
            if(!p) return ;
            for(int i = 0; i < base; ++i) self(self, p->next[i]);
            delete p;
        };
        dfs(dfs, root);
    }
    void insert(const std::string &s) {
        auto p = root;
        for(auto i:s) {
            int c = i - 'a';
            if(!p->next[c]) p->next[c] = new tril_node();
            p = p->next[c];
        }
        p->count++;
    }
    bool find(const std::string &s) {
        auto p = root;
        for(auto i:s) {
            int c = i - 'a';
            if(!p->next[c]) return false;
            p = p->next[c];
        }
        return p->count;
    }
};

/*  可删除，指针版
template <size_t base = 26>
class point_tril {
private:
    struct tril_node {
        int cnt;
        std::array<tril_node *, base> next;
    };
    tril_node *root; 
public:
    point_tril() {
        int cnt = 0;
        root = new tril_node();
    }
    ~point_tril() {
        auto dfs = [&](auto self, tril_node *p) {
            if(!p) return ;
            for(int i = 0; i < base; ++i) self(self, p->next[i]);
            delete p;
        };
        dfs(dfs, root);
    }
    void insert(int x) {
        auto p = root;
        p->cnt++;
        for(auto i:ch(x)) {
            if(!p->next[i]) p->next[i] = new tril_node();
            p = p->next[i];
            p->cnt++;
        }
    }
    void del(int x) {
        auto p = root;
        p->cnt--;
        for(auto i:ch(x)) {
            p->next[i]->cnt--;
            if(p->next[i]->cnt == 0) {
                auto dfs = [&](auto self, tril_node *p) {
                    if(!p) return ;
                    for(int i = 0; i < base; ++i) self(self, p->next[i]);
                    delete p;
                };
                dfs(dfs, p->next[i]);
                p->next[i] = nullptr;
                return ;
            }
            p = p->next[i];
        }
    }
    int find(int x) {
        auto p = root;
        int ans = 0;
        auto it = ch(x);
        for(int i = 0; i < 32; ++i) {
            if(p->next[it[i]^1]) p = p->next[it[i]^1], ans |= 1 << (31 - i);
            else p = p->next[it[i]];
        }
        return ans;
    }
};

*/