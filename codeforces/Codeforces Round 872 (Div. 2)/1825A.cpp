#include<bits/stdc++.h>

using namespace std;

signed main(){
    //ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
		string a;
		cin >> a;
		int len = a.size();
		for(int i = 1; i < len; ++ i){
			if(a[i - 1] != a[i]){
				cout << len - 1 << '\n';
				goto A;
			}
		}
		cout << "-1\n";
		A:;
	}
    return 0;
}
