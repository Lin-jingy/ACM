// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// int a[105][105];
// signed main() {
// 	/*std::ios::sync_with_stdio(false); cin.tie(0);  cout.tie(0);*/
// 	int t; cin >> t;
// 	while (t--) {
// 		memset(a, 0, sizeof(a));
// 		int n; cin >> n;
// 		if (n % 2 == 0) {
// 			for (int i = 0; i < n; ++i) {
// 				for (int j = 0; j < n - 1;) {
// 					scanf("%d", &a[i][j]);
// 					++j;
// 				}
// 			}
// 			for (int i = 0; i < n - 1; ++i) {
// 				map<int, int>m;
// 				for (int j = 0; j < n; ++j) {
// 					m[a[j][i]]++;
// 				}
// 				int ans = 0, flag1 = 0, flag2 = 0;
// 				for (auto i : m) {
// 					if (ans < i.second) { ans = i.second; flag1 = i.first; }
// 					else if (ans == i.second) {
// 						flag2 = i.first;
// 					}
// 				}
// 				if (flag2 == 0)cout << flag1 << ' ';
// 				else {
// 					if (i != 0) {
// 						for (int j = 0; j < n; ++j) {
// 							if (a[j][i] == flag1 and a[j][i - 1] == flag2) { cout << flag2 << ' ' << flag1 << ' '; break; }
// 							else if (a[j][i] == flag2 and a[j][i - 1] == flag1) { cout << flag1 << ' ' << flag2 << ' '; break; }
// 						}
// 					}
// 					else {
// 						for (int j = 0; j < n; ++j) {
// 							if (a[j][i] == flag1 and a[j][i + 1] == flag2) { cout << flag1 << ' ' << flag2 << ' '; break; }
// 							else if (a[j][i] == flag2 and a[j][i + 1] == flag1) { cout << flag2 << ' ' << flag1 << ' '; break; }
// 						}
// 					}
// 				}
// 			}
// 			cout << '\n';
// 		}
// 		else {
// 			for (int i = 0; i < n; ++i) {
// 				for (int j = 0; j < n - 1;) {
// 					scanf("%d", &a[i][j]);
// 					++j;
// 				}
// 			}
// 			int ak[105] = { 0 };
// 			bool dig[105] = { false };
// 			for (int i = 0; i < n - 1; ++i) {
// 				map<int, int>m;
// 				for (int j = 0; j < n; ++j) {
// 					m[a[j][i]]++;
// 				}
// 				int ans = 0, flag1 = 0;
// 				for (auto i : m) {
// 					if (ans < i.second) { ans = i.second; flag1 = i.first; }
// 				}
// 				ak[i] = flag1;
// 				dig[flag1] = true;
// 			}
// 			int kk = 0;
// 			if (a[0][0] == ak[0]) {
// 				for (int i = 0; i < n - 1; ++i) {
// 					if (dig[a[0][i]] == true)cout << ak[i] << ' ';
// 					else { cout << a[0][i] << ' '; kk = i; break; }
// 				}
// 				for (int i = kk; i < n - 1; ++i)cout << ak[i] << ' ';
// 			}
// 			else {
// 				cout << ak[0] << ' ';
// 				for (int i = 0; i < n - 1; ++i) {
// 					cout << a[0][i] << ' ';
// 				}
// 			}
// 			cout << '\n';
// 		}
// 	}
// 	return 0;
// }

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define quick std::ios::sync_with_stdio(false),cin.tie(nullptr); 
signed main(){
    quick;
    int t;cin>>t;
	while(t--){
		int a[105][105]={0};
		int n;cin>>n;
		for(int i=0;i<n;++i)for(int j=0;j<n-1;++j)cin>>a[i][j];
		pair<int,int> x,y;
		y={0,0};
		x={a[0][0],1};
		for(int i=1;i<n;++i){
			if(a[i][0]!=x.first){
				if(y.first==0)y={a[i][0],1};
				else y.second++;
			}else{
				x.second++;
			}
		}
		int rea=0;
		if(x.second>y.second)rea=x.first;
		else rea=y.first;
		for(int i=0;i<n;++i){
			if(a[i][0]!=rea){
				cout<<rea<<' ';
				for(int j=0;j<n-2;++j)cout<<a[i][j]<<' ';
				cout<<a[i][n-2]<<'\n';
			}
		}
	}

    return 0;
}