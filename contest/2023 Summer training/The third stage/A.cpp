#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
using PSI = pair<string, int>;
using PIS = pair<int, string>;
#define inf LONG_LONG_MAX
#define yes cout << "Yes\n"
#define no cout << "No\n"

void solve(){
    int n, k;
    cin >> n >> k;
    string a;
    cin >> a;
    list<int>l;
    set<int>v;
    for(int i = 0; i < n; ++i){
        if(a[i] == '0')l.push_back(i);
        else v.insert(i);
    }
    while(k > 0 and !l.empty() and !v.empty()){
        if(l.front() < *v.begin()){
            l.pop_front();
            continue;
        }
        if(k > l.front() - *v.begin()){
            k -= l.front() - *v.begin();
            swap(a[*v.begin()], a[l.front()]);
            v.insert(l.front());
            l.pop_front(), v.erase(v.begin());
        }else {
            while(k > 0 and !l.empty() and !v.empty()){
                auto it = upper_bound(v.begin(), v.end(), l.front() - k);
                if(it == v.begin())break;
                else {
                    --it;
                    k -= l.front() - *it;
                    swap(a[l.front()], a[*it]);
                    v.insert(l.front());
                    l.pop_front();
                    v.erase(it);
                }
            }
        }
    }
    cout << a << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
