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

inline int change(int x){
    if(x == 2)return 1;
    else return 2;
}

void solve(){
    string a[3];
    cin >> a[1] >> a[2];
    int dif(0);
    for(size_t i(0); i < (size_t)a[1].size(); ++i) if(a[1][i] != a[2][i]) ++ dif;
    int t, q;
    cin >> t >> q;
    int time(0);
    queue<PII>dq;
    while(q--){
        ++time;
        if(!dq.empty() and dq.front().second <= time){
            if(a[1][dq.front().first] != a[2][dq.front().first]) ++dif;
            dq.pop(); 
        }
        int op;
        cin >> op;
        if(op == 1){
            int pos;
            cin >> pos;
            --pos;
            dq.push({pos, time + t});
            if(a[1][pos] != a[2][pos]) --dif;
        }else if(op == 2){
            int pos1, x1, pos2, x2;
            cin >> pos1 >> x1 >> pos2 >> x2;
            --x1, --x2;
            dif += a[2][x1] == a[1][x1]; 
			dif += a[2][x2] == a[1][x2]; 
			swap (a[pos1][x1], a[pos2][x2]);
			dif -= a[2][x1] == a[1][x1]; 
			dif -= a[2][x2] == a[1][x2]; 
        }else{
            if(dif == 0)yes;
            else no;
        }
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--)solve();
    return 0;
}
