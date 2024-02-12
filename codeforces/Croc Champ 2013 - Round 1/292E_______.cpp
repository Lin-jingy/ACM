#include<bits/stdc++.h>
#include<unordered_map>
 
using namespace std;
#define int long long 
using PII = pair<int,int>;
 
class node{
public:
	int l, r, bl;
	friend bool operator< (node a, node b){
		if(a.l != b.l)return a.l < b.l;
		else if(a.r != b.r)return a.r > b.r;
		else return a.bl < b.bl;
	}
};
 
int a[100005];
int b[100005];
int c[100005];
vector<node>s;
unordered_map<int,int>mp;
 
void solve(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++ i)cin >> b[i];
	for(int i = 1; i <= n; ++ i)cin >> a[i];
	while(k--){
		int op;
		cin >> op;
		if(op == 1){
			int l1, l2, len;
			cin >> l1 >> l2 >> len;
			int r2 = l2 + len - 1;
			if(len == 1){
				mp[l2] = 1, a[l2] = b[l1];
			}
			else{
				for(auto it = mp.begin(); it != mp.end();) 
					if(l2 <= it->first and r2 >= it->first)it = mp.erase(it);
					else ++ it;
				s.push_back({l2, r2, l1});
			}
			
		}else{
			int pos;
			cin >> pos;
			if(mp.count(pos)){
				cout << a[pos] << '\n';
				continue;
			}
			for(int k = (int)s.size() - 1; k >= 0; -- k){
				auto i = s[k];
				if(i.l <= pos and i.r >= pos){
					cout << b[pos - i.l + i.bl] << '\n';
					goto A;
				}
			}
			cout << a[pos] << '\n';
			A:;
		}
	}
}
 
signed main(){
	ios::sync_with_stdio(false),cin.tie(0);
	solve();
	return 0;
}