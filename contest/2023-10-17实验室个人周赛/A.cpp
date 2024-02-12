// #include<bits/stdc++.h>

// #define int long long 
// const int mod = 1e9 + 7;

// int qpow(int a, int b) {
//     int sum = 1;
//     while(b) {
//         if(b & 1) sum = sum * a % mod;
//         b >>= 1;
//         a = a * a % mod;
//     }
//     return sum;
// }

// signed main(){
//     std::string s;
//     std::cin >> s;
//     int n = s.size();
//     s = '0' + s + '0';
//     if(n == 1 and s[1] == '?') {
//         std::cout << 2 << '\n';
//         return 0;
//     }else if(n == 1) {
//         std::cout << 0 << '\n';
//         return 0;
//     }
//     for(int i = 1; i <= n; ++i) {
//         if(s[i] == '?') {
//             if(s[i - 1] == '0' and s[i + 1] == '1') s[i] = '0';
//             else if(s[i - 1] == '0' and s[i + 1] == '*') s[i] = '1';
//             else if(s[i - 1] == '1' and s[i + 1] == '0') s[i] = '0';
//             else if(s[i - 1] == '*' and s[i + 1] == '0') s[i] = '1';
//             else if(s[i - 1] == '0' and s[i + 1] == '0') s[i] = '1';
//         }
//         if(s[i] == '2') {
//             if(s[i - 1] == '?') s[i - 1] = '*';
//             if(s[i - 1] != '?' and s[i - 1] != '*') {
//                 std::cout << "0\n";
//                 return 0;
//             }
//             if(s[i + 1] == '?') s[i + 1] = '*';
//             if(s[i + 1] != '?' and s[i + 1] != '*') {
//                 std::cout << "0\n";
//                 return 0;
//             }
//         }
//         if(s[i] == '0') {
//             if(s[i - 1] == '*' or s[i + 1] == '*') {
//                 std::cout << "0\n";
//                 return 0;
//             }
//         }
//         if(s[i] == '1') {
//             if(s[i - 1] == '*' and s[i + 1] == '*') {
//                 std::cout << "0\n";
//                 return 0;
//             }else if(s[i - 1] == '1' and s[i + 1] == '?') s[i + 1] = '*';
//             else if(s[i - 1] == '?' and s[i + 1] == '1') s[i - 1] = '*';
//             else if(s[i - 1] == '0' and s[i + 1] == '?') s[i + 1] = '*';
//             else if(s[i - 1] == '?' and s[i + 1] == '0') s[i - 1] = '*';

//         }
//     }
//     int ans = 0;
//     int k = 0;
//     for(int i = 1; i <= n; ++i) {
//         if(s[i] == '?') goto A;
//     }
//     std::cout << 0 << '\n';
//     return 0;
//     A:;
//     for(int i = 1; i <= n; ++i) {
//         if(s[i] == '?' and s[i - 1] == '1' and s[i + 1] == '1') k++;
//         else if(s[i] == '?') ans ++;
//     }
//     std::cout << qpow(2, ans - k) << '\n';
//     return 0;
// }


#include<bits/stdc++.h>

#define int long long 
const int mod = 1e9 + 7;

signed main(){
    std::string s;
    std::cin >> s;
    int n = s.size();
    s = ' ' + s;
    std::vector<std::array<int, 5>> dp(n + 1);
    dp[0][0] = dp[0][4] =  1;
    for(int i = 1; i <= n; i++){
        if(s[i] == '?') {
            dp[i][0] = dp[i][4] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i][3] = dp[i - 1][2];
            dp[i][2] = dp[i - 1][2] + dp[i - 1][3] + dp[i - 1][4];
        }
        else if(s[i] == '0') dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        else if(s[i] == '1') dp[i][1] = dp[i - 1][2], dp[i][4] = dp[i - 1][0] + dp[i - 1][1];
        else if(s[i] == '*') dp[i][2] = dp[i - 1][3] + dp[i - 1][2] + dp[i - 1][4];
        else if(s[i] == '2') dp[i][3] = dp[i - 1][2];
        for(int j = 0; j < 5; ++j) dp[i][j] %= mod;
    }
    std::cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
}