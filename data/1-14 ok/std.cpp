
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for((int)(i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define f first
#define s second
#define inf int(2e9)
#define sz(x) int((x).size())
#define sqr(x) (x) * (x)
#define all(x) (x).begin(), (x).end()

const double eps = 1e-9;
const double pi = acos(-1.0);
typedef long long ll;

int n, k, m;
ll s, a[30], f[100];

vector<ll> d[30];

ll calc(int pos, int cnt, ll sum) {
 	if(sum == s) return 1LL;
 	if(pos == m)  return 0LL;

 	ll res = calc(pos + 1, cnt, sum);

 	if(a[pos] <= 19 && sum + f[a[pos]] <= s && cnt < k) {
 		res += calc(pos + 1, cnt + 1, sum + f[a[pos]]); 	
 	}
 	if(sum + a[pos] <= s) res += calc(pos + 1, cnt, sum + a[pos]);

 	return res;
}

int get_cnt(int x, ll sum) {
      return int(upper_bound(d[x].begin(), d[x].end(), sum) - lower_bound(d[x].begin(), d[x].end(), sum));
}

ll calc2(int pos, int cnt, ll sum) {
 	if(sum == s) return 1LL;
 	if(pos == m) {
 		return get_cnt(k - cnt, s - sum); 	
 	}

 	ll res = calc2(pos + 1, cnt, sum);

 	if(a[pos] <= 19 && sum + f[a[pos]] <= s && cnt < k) {
 		res += calc2(pos + 1, cnt + 1, sum + f[a[pos]]); 	
 	}
 	if(sum + a[pos] <= s) res += calc2(pos + 1, cnt, sum + a[pos]);

 	return res;
}

void rec(int pos, int cnt, ll sum, int K) {
 	if(pos == n) {
 	 	d[K].pb(sum);
 	 	return;
 	}

 	rec(pos + 1, cnt, sum, K);

 	if(a[pos] <= 19 && sum + f[a[pos]] <= s && cnt < K) {
 		rec(pos + 1, cnt + 1, sum + f[a[pos]], K); 	
 	}
 	if(sum + a[pos] <= s) rec(pos + 1, cnt, sum + a[pos], K);
}


int main() {
	#ifdef LOCAL
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif

    for(int I = 1; I <= 100; ++I) {
        // std::clog << I << std::endl;
        std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/14 ok/data/{}.in", I);
        std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/14 ok/data/{}.out", I);

        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);

        n = k = m = 0;
        s = 0;
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        for(int i = 0; i < 30; ++i) d[i].resize(0);


        cin >> n >> k >> s;
        
        for(int i = 0; i < n; ++i) cin >> a[i];

        f[0] = 1LL;
        for(int i = 1; i <= 20; ++i) {
            f[i] = f[i - 1] * i;
        }
        if(n <= 17) {
            m = n;
            cout << calc(0, 0, 0) << std::endl;
            goto AAA;
        }

        m = 15;

        for(int i = 0; i <= k; ++i) {
            rec(15, 0, 0, i);	
            sort(d[i].begin(), d[i].end());
        }


        cout << calc2(0, 0, 0) << std::endl;


        AAA:;


        fclose(stdin);
        fclose(stdout);
        std::clog << I << std::endl;

    }

	

	return 0; 
}