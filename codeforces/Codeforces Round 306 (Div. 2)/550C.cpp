#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;

void solve(){
    string a;
    cin >> a;
    if(count(a.begin(), a.end(), '0') != 0){
        cout << "YES\n";
        cout << 0 << '\n';
        return;
    }
	if(count(a.begin(),a.end(),'8') != 0){
		cout << "YES\n";
		cout << 8 <<'\n';
		return;
	}
	for(int j = 0; j < a.size(); ++j){
            for(int k = j + 1; k < a.size(); ++k){
                int sk = (a[j] - '0') * 10 + (a[k] - '0');
                if(sk % 8 == 0){
                    cout << "YES\n";
                    cout << sk << '\n';
                    return;
                }
            }
        }
    for(int i = 0; i < a.size(); ++i){
        for(int j = i + 1; j < a.size(); ++j){
            for(int k = j + 1; k < a.size(); ++k){
                int sk = (a[i] - '0') * 100 + (a[j] - '0') * 10 + (a[k] - '0');
                if(sk % 8 == 0){
                    cout << "YES\n";
                    cout << sk << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--)solve();
    return 0;
}
