#include <bits/stdc++.h>

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


signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    point_tril T, T1;
    for(int i = 1; i <= n; ++i) {
        std::string s;
        std::cin >> s;
        T.insert(s);
    }
    int m;
    std::cin >> m;
    while(m--) {
        std::string s;
        std::cin >> s;
        if(T.find(s) and !T1.find(s)) {
            std::cout << "OK\n";
            T1.insert(s);
        } else if(T1.find(s)) {
            std::cout << "REPEAT\n";
        } else {
            std::cout << "WRONG\n";
        }
    }

    return 0;
}