#include<bits/stdc++.h>

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1), p(m + 1);
    for(int i = 1; i <= n; ++i) 
        std::cin >> a[i], p[a[i]] = i;
    
    std::stack<int> s;
    std::unordered_set<int> st;
    for(int i = 1; i <= n; ++i) {
        if(s.empty()) s.push(a[i]), st.insert(a[i]);
        else {
            if(st.count(a[i])) continue;
            while(!s.empty() and s.top() > a[i] and p[s.top()] > i) {
                st.erase(s.top());
                s.pop();
            }
            s.push(a[i]);
            st.insert(a[i]);
        }
    }
    std::vector<int> ans;
    while(!s.empty()) ans.emplace_back(s.top()), s.pop();
    std::reverse(ans.begin(), ans.end());
    for(auto i:ans) std::cout << i << ' ';


    return ;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T = 1;
    //std::cin >> T;
    while(T--) solve();
    return 0;
}