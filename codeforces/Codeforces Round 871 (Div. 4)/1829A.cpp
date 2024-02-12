#include<bits/stdc++.h>

std::string a = "codeforces";

int main(){
    int T = 1;
    std::cin >> T;
    while(T--){
        std::string s;
        std::cin >> s;
        int ans = 0;
        for(int i = 0; i < s.size(); ++i) if(a[i] != s[i]) ++ans;
        std::cout << ans << '\n';
    }
    
    return 0;
}