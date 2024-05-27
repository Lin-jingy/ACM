#include <bits/stdc++.h>

using namespace std;

const int N = 2000010;

int mn[N], add[N], cnt[N];

void build(int x, int l, int r) {
  mn[x] = l;
  add[x] = 0;
  cnt[x] = 1;
  if (l < r) {
    int y = (l + r) >> 1;
    build(x + x, l, y);
    build(x + x + 1, y + 1, r);
  }
}

inline void push(int x) {
  if (add[x] != 0) {
    add[x + x] += add[x];
    add[x + x + 1] += add[x];
    add[x] = 0;
  }
}

inline void gather(int x) {
  int a = mn[x + x] + add[x + x];
  int b = mn[x + x + 1] + add[x + x + 1];
  mn[x] = (a < b ? a : b);
  cnt[x] = (a == mn[x] ? cnt[x + x] : 0) + (b == mn[x] ? cnt[x + x + 1] : 0);
}

void modify(int x, int l, int r, int ll, int rr, int value) {
  if (ll <= l && r <= rr) {
    add[x] += value;
    return;
  }
  push(x);
  int y = (l + r) >> 1;
  if (ll <= y) {
    modify(x + x, l, y, ll, rr, value);
  }
  if (rr > y) {
    modify(x + x + 1, y + 1, r, ll, rr, value);
  }
  gather(x);
}

int a[N];
int up[N], down[N];

int main() {
    std::string dataID = "15";
    std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/5/data/{}.in", dataID);
    std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/5/data/{}.out", dataID);
    freopen(address1.data(), "r", stdin);
    freopen(address2.data(), "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    a[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    a[x] = y;
  }
  build(1, 0, n - 1);
  long long ans = 0;
  int cup = 1, cdown = 1;
  up[0] = -1;
  down[0] = -1;
  for (int i = 0; i < n; i++) {
    while (cup >= 2 && a[i] < a[up[cup - 1]]) {
      modify(1, 0, n - 1, up[cup - 2] + 1, up[cup - 1], +a[up[cup - 1]]);
      cup--;
    }
    while (cdown >= 2 && a[i] > a[down[cdown - 1]]) {
      modify(1, 0, n - 1, down[cdown - 2] + 1, down[cdown - 1],
             -a[down[cdown - 1]]);
      cdown--;
    }
    up[cup++] = i;
    down[cdown++] = i;
    modify(1, 0, n - 1, up[cup - 2] + 1, up[cup - 1], -a[up[cup - 1]]);
    modify(1, 0, n - 1, down[cdown - 2] + 1, down[cdown - 1],
           +a[down[cdown - 1]]);
    ans += cnt[1];
  }
  cout << ans << endl;
  return 0;
}
