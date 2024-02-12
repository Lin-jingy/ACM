// #include<bits/stdc++.h>
// #include<unordered_set>

// #define int long long
// using PII = std::pair<int, int>;
// int n, k;
// std::priority_queue<int, std::vector<int>, std::greater<int> >q;
// std::unordered_set<int>s;


// void solve(){
//     std::cin >> n >> k;
//     int x, ans = 0;
//     for(int i = 1; i <= n; ++ i) {
//         std::cin >> x;
//         q.push(x);
//         s.insert(x);
//     }
//     while(ans < k - 1){
//         if(!s.count(q.top() * 2))q.push(q.top() * 2), s.insert(q.top() * 2);
//         ++ans;
//         int mid = q.top();
//         q.pop();
//         if(!s.count(mid + q.top()))q.push(mid + q.top()), s.insert(q.top() + mid);  
//     }
//     std::cout << q.top();
// }

// signed main(){
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     solve();
//     return 0;
// }


#include<bits/stdc++.h>

#define int long long
using PII = std::pair<int, int>;
int n, k, a[12];
std::set<int>s;

void solve(){
    std::cin >> n >> k;
    int ans = 0;
    for(int i = 1; i <= n; ++ i) std::cin >> a[i];
    s.insert(0);
    while(k --){
        for(int i = 1; i <= n; ++ i)s.insert(*s.begin() + a[i]);
        s.erase(s.begin());
    }
    std::cout << *s.begin();
}

signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
    return 0;
}