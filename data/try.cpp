#include <cstdio>

using namespace std;

typedef long long ll;

int n, m;
int a[1 << 20];

const ll MOD = 1000000007;
struct node {
  ll m[2][2];
  ll lz[2][2];
} st[1 << 20];
#define nd(l, r) st[(l + r) | (l != r)]
#define rt nd(l, r)
#define lc nd(l, m)
#define rc nd(m + 1, r)

ll T[2][2] = {{1, 1}, {1, 0}};
void mul(ll z[2][2], ll x[2][2], ll y[2][2]) {
  ll t[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      t[i][j] = 0;
      for (int k = 0; k < 2; k++) {
        t[i][j] = (t[i][j] + x[i][k] * y[k][j]) % MOD;
      }
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      z[i][j] = t[i][j];
    }
  }
}
void pw(ll z[2][2], ll x[2][2], ll y) {
  ll tx[2][2], tz[2][2];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      tx[i][j] = x[i][j];
      tz[i][j] = i == j;
    }
  }
  while (y) {
    if (y & 1) {
      mul(tz, tz, tx);
    }
    mul(tx, tx, tx);
    y >>= 1;
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      z[i][j] = tz[i][j];
    }
  }
}
void bld(int l, int r) {
  rt.m[0][0] = rt.m[1][1] = r - l + 1;
  rt.lz[0][0] = rt.lz[1][1] = 1;
  if (l != r) {
    int m = (l + r) >> 1;
    bld(l, m);
    bld(m + 1, r);
  }
}
void upd(node& n, ll m[2][2]) {
  mul(n.m, n.m, m);
  mul(n.lz, n.lz, m);
}
void upd(int l, int r, int L, int R, ll t[2][2]) {
  if (R < l || r < L) {
    return;
  } else if (L <= l && r <= R) {
    upd(rt, t);
  } else {
    int m = (l + r) >> 1;
    upd(lc, rt.lz);
    upd(rc, rt.lz);
    upd(l, m, L, R, t);
    upd(m + 1, r, L, R, t);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        rt.m[i][j] = (lc.m[i][j] + rc.m[i][j]) % MOD;
        rt.lz[i][j] = i == j;
      }
    }
  }
}
ll qry(int l, int r, int L, int R) {
  if (R < l || r < L) {
    return 0;
  } else if (L <= l && r <= R) {
    return rt.m[1][0];
  } else {
    int m = (l + r) >> 1;
    upd(lc, rt.lz);
    upd(rc, rt.lz);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        rt.lz[i][j] = i == j;
      }
    }
    return (qry(l, m, L, R) + qry(m + 1, r, L, R)) % MOD;
  }
}

int main() {
  scanf("%d%d", &n, &m);
  bld(0, n - 1);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    ll tmp[2][2];
    pw(tmp, T, a[i]);
    upd(0, n - 1, i, i, tmp);
  }
  for (int i = 0; i < m; i++) {
    int op, l, r, x;
    scanf("%d%d%d", &op, &l, &r);
    if (op == 1) {
      scanf("%d", &x);
      ll tmp[2][2];
      pw(tmp, T, x);
      upd(0, n - 1, l - 1, r - 1, tmp);
    } else {
      printf("%d\n", (int)qry(0, n - 1, l - 1, r - 1));
    }
  }
}
