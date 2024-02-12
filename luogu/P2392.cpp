
//不成立
// #include<iostream>
// #include<algorithm>
// using namespace std;
// #define int long long
// int s1, s2, s3, s4;
// int a[22], b[22], c[22], d[22];
// int fact(int x[], int len1) {
//     int left = 0, right = 0;
//     int time = 0;
//     for (int i = len1 - 1;;) {
//         if (i <= -1) {
//             time += (left > right ? left : right);
//             return time;
//         }
//         if (left == 0) { left = x[i--]; continue; }
//         if (right == 0) { right = x[i--]; continue; }
//         if (left != 0 && right != 0) {
//             int min1 = (left > right ? right : left);
//             left -= min1;
//             right -= min1;
//             time += min1;
//         }
//     }
//     return 0;
// }
// signed main() {
//     cin >> s1 >> s2 >> s3 >> s4;
//     for (int i = 0; i < s1; ++i)cin >> a[i];
//     for (int i = 0; i < s2; ++i)cin >> b[i];
//     for (int i = 0; i < s3; ++i)cin >> c[i];
//     for (int i = 0; i < s4; ++i)cin >> d[i];
//     sort(a, a + s1); sort(b, b + s2); sort(c, c + s3); sort(d, d + s4);
//     cout << fact(a, s1) + fact(b, s2) + fact(c, s3) + fact(d, s4);
//     return 0;
// }