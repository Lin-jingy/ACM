#include<bits/stdc++.h>

#define int long long 

int qpow(int a, int b){
    int sum = 1;
    while(b){
        if(b & 1) sum *= a;
        b >>= 1;
        a *= a;
    }
    return sum;
}

void solve(){
    std::string s;
    int l, r;
    std::cin >> s >> l >> r;

    auto calc = [&](int x){
        bool zero(s.front() == '0');
        auto num(stoll(s));
        int lenx(std::to_string(x).size());
        int lens(s.size());
        int ans(0);

        for(int i(0); i <= lenx - lens; ++i){
            int mid =  x % qpow(10, i + lens) / qpow(10, i);
            int front = x / qpow(10, i + lens);
            int back = x % qpow(10, i);
            if(num < mid) ans += (front + 1 - zero) * qpow(10, i);
            else if(num == mid) ans += (front - zero) * qpow(10, i) + back + 1;
            else ans += (front - zero) * qpow(10, i);
        }
        return ans;
    };
        
    std::cout << calc(r) - calc(l - 1) << '\n';


}

signed main(){
    int T;
    std::cin >> T;
    while(T--) solve();
    return 0;
}