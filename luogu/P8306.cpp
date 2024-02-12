// #pragma GCC optimize(3)
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include<fstream>

#define int long long
using PII = std::pair<int, int>;
using PSI = std::pair<std::string, int>;
using PIS = std::pair<int, std::string>;
#define ALL(x) x.begin(), x.end()
#define INF LONG_LONG_MAX
#define inf INT_MAX
#define yes std::cout << "Yes\n"
#define no std::cout << "No\n"

class node{
public:
    char x;
    int size;
    std::unordered_map<int, node*>mp;
};

std::unordered_map<char, node*>top;
std::unordered_map<char, int>mp;

void insert(std::string &s){
    node *p;
    mp[s.front()]++;
    if(top.count(s.front())) p = top[s.front()];
    else{
        p = new(node);
        p->size = 0;
        top[s.front()] = p; 
    }
    int len(s.size());
    for(size_t i(0); i < len; ++i) {
        p->x = s[i];
        p->size++;
        if(i == len - 1) break;
        if(p->mp.count(s[i + 1])){
            p = p->mp[s[i + 1]];
        }else{
            node *mid(new(node));
            mid->size = 0;
            p->mp[s[i + 1]] = mid;
            p = mid;
        }
    }
}

int dosum(std::string &s){
    node *p;
    int sum(mp[s.front()]);
    if(top.count(s.front())) p = top[s.front()];
    else return 0;
    int len(s.size());
    for(size_t i(0); i < len; ++i){
        sum = std::min(sum, p->size);
        if(i == len - 1) break;
        if(p->mp.count(s[i + 1])) p = p->mp[s[i + 1]];
        else return 0;
    }
    return sum;
}

void solve(){
    top.clear();
    mp.clear();
    int n, q;
    std::cin >> n >> q;
    while(n--){
        std::string a;
        std::cin >> a;
        insert(a);
    }
    while(q--){
        std::string a;
        std::cin >> a;
        std::cout << dosum(a) << '\n';
    }
}

signed main(){
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    int _ = 1;
    std::cin >> _;
    while (_--) solve();
    return 0;
}
