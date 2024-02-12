#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;
#define int long long 
using PII = pair<int ,int>;
const int N = 105;
int a[N];

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
    int n = read();
    for(int i = 1; i <= n; ++i)a[i] = read();
    for(int i = 1; i <= n; ++i)if(a[i] < 0){
        cout << a[i] << '\n';
        return ;
    }
    sort(a + 1, a + 1 + n, greater<>());
    cout << a[1] << '\n';
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t = 1;
    t = read();
    while(t--)solve();
    return 0;
}
