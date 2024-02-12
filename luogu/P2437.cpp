#include<bits/stdc++.h>
#define int long long
using namespace std;
// int sum=0;
// void fact(int m,int x){
//     if(x>m+1){
//         fact(m,x-1);
//         fact(m,x-2);
//     }else sum++;
// }
// signed main(){
//     int n,m;
//     cin>>m>>n;
//     fact(m,n);
//     cout<<sum;
//     return 0;
// }
string reverseStr(string input){
 
    string output = "";
    for(int i = 0; i < input.length(); i++){
        output.insert(output.begin(),input[i]);
    }
    return output;
 
}
int charToInt(char c){
    return c - '0';
}
 
char intToChar(int n){
    return '0' + n;
}
string sumofStr(string _s1, string _s2){
    string s1 = reverseStr(_s1);
    string s2 = reverseStr(_s2);
    int pMax = s1.length() > s2.length() ? s2.length() : s1.length();
    string sumStr = "";
    int p;
    int carry = 0;
    int temp = 0;
    for(p = 0; p < pMax; p++){
        temp = charToInt(s1[p]) + charToInt(s2[p]) + carry;
        carry = temp / 10;
        sumStr.insert(sumStr.begin(),intToChar(temp % 10));
    }
    if(p < s1.length()){
        for(; p < s1.length(); p++){
            temp = charToInt(s1[p]) + carry;
            carry = temp / 10;
            sumStr.insert(sumStr.begin(),intToChar(temp % 10));
        }
    }
    if(p < s2.length()){
        for(; p < s2.length(); p++){
            temp = charToInt(s2[p]) + carry;
            carry = temp / 10;
            sumStr.insert(sumStr.begin(),intToChar(temp % 10));
        }
    }
    if(carry > 0){
        sumStr.insert(sumStr.begin(),intToChar(carry % 10));
        carry /= 10;
    }
    return sumStr;
}

signed main(){
    string a[1005]={};
    a[0]='1';
    a[1]='1';
    int n,m;
    cin>>m>>n;
    int xt=n-m;
    if(xt==1){cout<<'1';return 0;}
    if(xt==2){cout<<'2';return 0;}
    for(int i=2;i<xt+1;++i){
        a[i]=sumofStr(a[i-1],a[i-2]);
    }
    cout<<a[xt];
    return 0;
}