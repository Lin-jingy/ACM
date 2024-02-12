#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr)
struct ff{
    int need;
    int t;
}a[150010];
priority_queue<int> q;
bool fact(ff a, ff b){
    return a.t < b.t;
}
signed main(){
    quick;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].need >> a[i].t;
    sort(a, a + n, fact);
    int ans = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        q.push(a[i].need);
        time += a[i].need;
        if (time > a[i].t) time -= q.top(), q.pop();
    }
    cout << q.size();
    return 0;
}