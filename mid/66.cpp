#include<cstdio>
#include<cmath>
typedef long long ll;
const int N = 200005;
ll a[N];//第i个墓碑的风水
int q[N];//第i个墓碑所属块
ll sum[N];//整块被加的次数
ll res[N];//整块和
int n, m;
int sq;//块长度，通常用根号n
inline int min(int a, int b) {//最小值
	return a < b ? a : b;
}
void change(int l, int r, int k) {
	for (int i = l; i <= min(q[l] * sq, r); i++) {//对左碎块进行暴力处理
		res[q[i]] -= a[i] * 1ll;
		a[i] += k * 1ll;
		res[q[i]] += a[i] * 1ll;
	}
	if (q[l] != q[r]) {//对右碎块进行暴力处理
		for (int i = (q[r] - 1)*sq + 1; i <= r; i++) {
			res[q[i]] -= a[i] * 1ll;
			a[i] += k * 1ll;
			res[q[i]] += a[i] * 1ll;
		}
	}
	for (int i = q[l] + 1; i < q[r]; i++) {//整块修改块标记
		sum[i] += k * 1ll;
		res[i] += k * sq * 1ll;
	}
}
ll query(int l, int r) {
	ll s = 0;
	for (int i = l; i <= min(q[l] * sq, r); i++) {//左碎块暴力求和
		s += (a[i] + sum[q[i]]) * 1ll;
	}
	if (q[l] != q[r]) {
		for (int i = (q[r] - 1)*sq + 1; i <= r; i++) {//右碎块暴力求和
			s += (a[i] + sum[q[i]]) * 1ll;
		}
	}
	for (int i = q[l] + 1; i < q[r]; i++) {//整块加块和
		s += res[i] * 1ll;
	}
	return s;
}
signed main() {
	scanf("%d%d", &n, &m);
	sq = sqrt(n);//块长度
	for (int i = 1; i <= n; i++) {
		q[i] = (i - 1) / sq + 1;//划分所属块
		scanf("%d", &a[i]);
		res[q[i]] += a[i];//整快和加当前风水值
	}
	while (m--) {//操作应该不用讲了，比较简单
		int opt, q, l, r;
		scanf("%d", &opt);
		if (opt <= 3) {
			if (opt == 1) {
				scanf("%d%d%d", &l, &r, &q);
				change(l, r, q);
			}
			else {//操作2、3当作修改区间[1,1]
				scanf("%d", &q);
				change(1, 1, opt == 2 ? q : -q);
			}
		}
		else {
			if (opt == 4) scanf("%d%d", &l, &r), printf("%lld\n", query(l, r));
			else printf("%lld\n", a[1] + sum[1]);
		}
	}
}