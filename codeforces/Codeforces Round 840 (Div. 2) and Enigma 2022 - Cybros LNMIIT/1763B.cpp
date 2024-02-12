// #include<bits/stdc++.h>
// #include<unordered_map>
// #include<unordered_set>

// using namespace std;
// #define int long long 
// using PII = pair<int ,int>;

// class node{
// public:
//     int last, pow;
//     friend bool operator <(node a, node b){
//         if(a.pow != b.pow)return a.pow < b.pow;
//         else return a.last > b.last;
//     } 
// }a[100005];

// unordered_map<int, int>mp;

// void solve(){
//     int n, k;
//     cin >> n >> k;
//     mp.clear();
//     for(int i = 1; i <= n; ++ i)cin >> a[i].last;
//     for(int i = 1; i <= n; ++ i)cin >> a[i].pow;
//     for(int i = 1; i <= n ; ++ i){
//         if(!mp.count(a[i].pow))mp[a[i].pow] = a[i].last;
//         else if(a[i].last > mp[a[i].pow])mp[a[i].pow] = a[i].last;
//     }
//     int flag = 0;
//     while(1){
//         int h = 0, p = INT_MAX;
//         for(auto st : mp){
//             if(st.first < p)p = st.first, h = st.second;
//         }
//         int sum = 0;
//         if(flag)k -= p, flag = 0;
//         while(h > 0 and k > 0){
//             h -= k;
//             sum += k;
//             if(h != 0)k -= p;
//             else flag = 1;
//         }
//         if(k <= 0){
//             cout << "NO\n";
//             return;
//         }
//         for(auto it = mp.begin(); it != mp.end(); ){
//             if(it->second > sum)it->second -= sum, ++ it;
//             else it = mp.erase(it);
//         }
//         if(mp.empty()){
//             cout << "YES\n";
//             return;
//         }
//     }
//     return;
// }

// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     int t = 1;
//     cin >> t;
//     while(t--)solve();
//     return 0;
// }


#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<PII>v(n), a(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
    }
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    map<int, int>mp;
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());
    int idx = 0, ans = 0, l = 0;
    while (idx < n && k > 0){
        ans += k;
        while (idx < n && v[idx].first <= ans){
            mp[v[idx].second] = 1;
            idx++;
        }
        if (idx >= n){
            cout << "YES" << endl;
            return;
        }
        while (l < n && mp.count(a[l].second))l++;
        if (l < n){
            k -= a[l].first;
        }
    }
    if (idx >= n)cout << "YES" << endl;
    else cout << "NO" << endl;
}


signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
