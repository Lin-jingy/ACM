#include<bits/stdc++.h>
using namespace std;
#define int long long
bool con[22][22];//判断两个地窖有无连接
int a[22], n;
int max1;//存储最大值
string ans;
struct fact {
	int k;//当前地窖位置
	bool flag[22];
	string road;//记录访问过的位置
	int sum;//计算当前获取的地雷数
};
stack<fact>q;
signed main() {
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i < n; ++i) {//输入部分
		for (int j = i + 1; j <= n; ++j) {
			cin >> con[i][j];
		}
	}
	//dfs
	for (int i = 1; i <= n; ++i) {//入口
		fact x;
		x.k = i;
		x.sum = a[i];
		x.road = to_string(i);
		q.push(x);
		while (!q.empty()) {
			x.k = q.top().k;
			x.flag[x.k] = 1;
			copy(begin(q.top().flag),end(q.top().flag),x.flag);
			x.sum = q.top().sum;
			x.road = q.top().road;
			if (x.sum > max1) {
				max1 = x.sum;
				ans = x.road;
			}
			q.pop();
			for (int j = x.k + 1; j <= n; ++j) {
				if (!x.flag[j] && (con[x.k][j])) {//遍历未被访问且有连接路径
					q.push(x);
					q.top().k = j;
					q.top().flag[i] = 1;
					q.top().sum += a[j];
					q.top().road += ' ' + to_string(j);
				}
			}
		}
	}
	cout << ans << '\n' << max1;
	return 0;
}
