#include<bits/stdc++.h>
#include<unordered_set>

using i64 = long long;
using i128 = __int128;
std::set<i64>s;

int main() {
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
    for(i64 i(2); i <= 1e6; ++i){
        i128 j = i + 1;
		i128 l = i * i;
		while(j + l <= 1e18)	{
			j += l;
			l *= i;
			s.insert(j);
		}
    }

    int T;
    std::cin >> T;
    while(T--) {
        i64 n;
        std::cin >> n;

        if(s.count(n)) std::cout << "YES\n";
        else if(n >= (i64)1e12) {
            i64 k = 1 - 4 * (1 - n);
			i64 x = 0.5 * (-1 + sqrt(k));
			if(x * x + x + 1 == n) std::cout << "YES\n";
			else std::cout << "NO\n";
        }else std::cout << "NO\n";
    }
}