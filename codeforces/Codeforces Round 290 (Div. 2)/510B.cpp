#include <bits/stdc++.h>

using namespace std;
int n, m;
bool vis[55][55], flag;
char a[55][55];
int fx[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool check(int xx, int yy, char p) {return xx >= 1 and xx <= n and yy >= 1 and yy <= m and a[xx][yy] == p;}

void dfs(int x, int y, int k, char p) {
	for(int i = 0;i <= 3;i++) {
		int xx = x + fx[i][0];
		int yy = y + fx[i][1];
		if((i == 0 and k == 1) or (i == 1 and k == 0) or (i == 2 and k == 3) or (i == 3 and k == 2)) continue;
		if(check(xx, yy, p)) {
			if(vis[xx][yy]){
				flag = true;
				return;
			}
			vis[xx][yy] = true;
			dfs(xx, yy, i, p);
			if(flag) return;
		}
	}
}
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
	for(int i = 1; i <= n; i++) {
		for(int j = 1;j <= m;j++) {
			if(!vis[i][j]) dfs(i, j, -1, a[i][j]);
			if(flag) {
				cout << "Yes" << '\n';
				return 0;
			}
		}
	}
	cout << "No" << '\n';
}