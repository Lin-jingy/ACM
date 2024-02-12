#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int, int>;
int a[100005], st[100005];
vector<int>v;

int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}

void solve(){
    int n = read(), m = read();
    v.clear();
    for(int i = 1; i <= n; ++ i){
        a[i] = read();
        if(a[i] > 0)st[i] = 1, v.emplace_back(a[i]);
        else st[i] = 0;
    }
    int l = 0, r = 0;
    for(int i = 1; i <= n; ++ i){
        if(a[i] == -1)l++;
        else if(a[i] == -2)r++;
    }
    sort(v.begin(),v.end());
    int kl = l + 1, kr = n - 1 - r;
    int pos = v[0];
    if(kl - 1 < n - kr)pos = 1;
    else pos = n;
    for(int i = 0; i < v.size(); ++ i){
        if(v[i] >= kl and v[i] <= kr){pos = v[i]; break;}
        else{
            if(kl < kr){
                int kk = abs(v[i] - kl);
                int kkk = abs(v[i] - kr);
                if(pos == 1 or pos == n and min(kk,kkk) - 1 < pos)pos = v[i];
                else if(min(kk,kkk) < pos)pos = v[i];
            }
        }
    }
    if(pos == 1 and st[1] == 0)--r;
    if(pos == n and st[n] == 0)--l;
    int ans = 1;
    for(int i = pos - 1; i > 1; -- i){
        if(l <= 0)break;
        ++ans;
        if(st[i] == 0)--l;
    }
    for(int i = pos + 1; i < n; ++ i){
        if(r <= 0)break;
        ++ans;
        if(st[i] == 0)--r;
    }
    if(r > 0 and pos != 1)++ans, --r;
    else if(l > 0 and pos != 1)++ans, --l;
    if(l > 0 and pos != n)++ans;
    else if(r > 0 and pos != n)++ans;
    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    t = read();
    while(t--)solve();
    return 0;
}