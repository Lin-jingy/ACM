#include<bits/stdc++.h>

#define int long long

signed main(){
    int n;
    std::cin >> n;

    std::vector<char>a;
    while(n) {
        a.push_back(n % 2 + '0');
        n /= 2;
    }
    while(a.size() < 32) a.push_back('0');
    std::string x[4];
    
    for(int i = 7; i >= 0; --i) x[0] += a[i];
    for(int i = 15; i >= 8; --i) x[1] += a[i];
    for(int i = 23; i >= 16; --i) x[2] += a[i];
    for(int i = 31; i >= 24; --i) x[3] += a[i];

    int xx[4] = {stoll(x[0], nullptr, 2), stoll(x[1], nullptr, 2), stoll(x[2], nullptr, 2), stoll(x[3], nullptr, 2)};

    std::sort(xx, xx + 4);
    std::cout << ((xx[3]<<24) + (xx[2]<<16) + (xx[1]<<8) + xx[0]) << '\n';

    // std::string ans;
    // for(int i = 0; i < 4; ++i) ans += x[i];
    // std::cout << stoll(ans, nullptr, 2) << '\n';

    //std::cout << (8<<24);
    return 0;
}