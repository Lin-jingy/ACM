#include<bits/stdc++.h>

using namespace std;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	if(k < n + m - 2 or k % 2 != (n + m) % 2){
		cout << "NO\n";
		return;
	}
	vector<vector<char>> r(n+1,vector<char>(m+1,'R'));
	vector<vector<char>> c(m+1,vector<char>(n+1,'R'));
	{
		char flag = 'R';
		for(int i=1;i<=m-1;i++){
			r[1][i] = flag;
			flag = (flag=='R'?'B':'R');
		}
		for(int i=1;i<=n-1;i++){
			c[m][i] = flag;
			flag = (flag=='R'?'B':'R');
		}
		flag = 'R';
		for(int i=1;i<=n-1;i++){
			c[1][i] = flag;
			flag = (flag=='R'?'B':'R');
		}
		for(int i=1;i<=m-1;i++){
			r[n][i] = flag;
			flag = (flag=='R'?'B':'R');
		}
		r[2][1] = 'R';
		c[2][1] = 'B';
		c[1][1] = 'B';
	}
	cout << "YES" << '\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			cout << r[i][j] << " \n"[j==m-1];
		}
	}
	for(int j=1;j<=n-1;j++){
		for(int i=1;i<=m;i++){
			cout << c[i][j] << " \n"[i==m];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
    return 0;
}