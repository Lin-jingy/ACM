//#include<iostream>
//#include<map>
//#include<set>
//using namespace std;
//#define int long long
//int a[100005];
//int k[100005];
//map<int, int>p, mp;
//map<int, int>::iterator it;
//set<int>s;
//signed main() {
//    int n, m; cin >> n >> m;
//    for (int i = 0; i < n; ++i)k[i] = 100001;
//    for (int i = 0; i < n; ++i)cin >> a[i];
//    for (int i = n - 1; i >= 0; --i) {
//        if (p.count(a[i])) {
//            k[i] = p.find(a[i])->second;
//            p[a[i]] = i;
//        }
//        else p[a[i]] = i;
//    }
//    p.clear();
//    int ans = 0;
//    for (int i = 0; s.size() < m && i < n; ++i) {
//        if (s.find(a[i]) == s.end()) {//如果未出现过
//            mp[k[i]] = a[i];
//            s.insert(a[i]);
//            ++ans;
//        }
//        else {//如果出现过
//            mp.erase(mp.find(i));
//            mp[k[i]] = a[i];
//        }
//    }
//    for (int i = m; i < n; ++i) {
//        if (s.find(a[i]) != s.end()) {//存在
//            mp.erase(mp.find(i));
//            mp[k[i]] = a[i];
//        }
//        else {//不存在
//            ans++;
//            it = mp.end();
//            --it;
//            s.erase(s.find(it->second));
//            mp.erase(it);
//            s.insert(a[i]);
//            mp[k[i]] = a[i];
//        }
//    }
//    cout << ans;
//    return 0;
//}
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
int a[100005];
map<int, int>p;
map<int, bool>mp;
priority_queue<pair<int, int>>q;
int k[100005];
long long ans;
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = 1e5 + 9;
    }
    for (int i = n; i >= 1; i--) {
        k[i] = p[a[i]];
        p[a[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (!mp[a[i]]) {
            if (ans >= m) {
                mp[a[q.top().second]] = false;
                q.pop();
            }
            ans++;
            mp[a[i]] = true;
        }
        q.push({ k[i],i });
    }
    cout << ans;
    return 0;
}
