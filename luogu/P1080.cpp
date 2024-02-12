#include<bits/stdc++.h>
#define int long long
using namespace std;
string High_precision_multiplication(string a, string b) {
    string ra(a.rbegin(), a.rend());//对a，b进行逆向操作，方便计算
    string rb(b.rbegin(), b.rend());
    if (a == "0" || b == "0")return "0";
    int maxlen, minlen;
    string rmax, rmin;
    if (a.size() > b.size()) {
        maxlen = a.size();
        minlen = b.size();
        rmax = ra;
        rmin = rb;
    }
    else {
        maxlen = b.size();
        minlen = a.size();
        rmax = rb;
        rmin = ra;
    }
    // cout<<rmin<<' '<<rmax;
    int answer[10000] = {};//注意此处的长度大小要大于要求的长度
    for (int i = 0; i < minlen; ++i) {
        for (int j = 0; j < maxlen; ++j) {
            answer[i + j] += ((int)rmin[i] - '0') * ((int)rmax[j] - '0');
        }
    }
    //  for(int i=0;i<5;++i)cout<<answer[i]<<' ';
    int flag = 0;
    for (int i = 0; i < minlen + maxlen - 1; ++i) {
        flag = i;
        while (answer[i] > 9) {
            answer[i] -= 10;
            answer[i + 1]++;
            flag = i + 1;
        }
    }
    string str;
    str.resize(flag+1);
    for (int i = 0; i <= flag; ++i) {
        str[i] = (char)(answer[i]) + '0';
    }
    string ranswer(str.rbegin(), str.rend());
    return ranswer;
}
string High_precision_division(string aa, int b) {
    char a1[10001];
    int c[10001]={}, d=0, a[10001]={}, len, lenc;
    int alen = aa.length ();
    for (int i = 0; i < alen; ++i) {
        a1[i] = aa[i];
    }
    len = strlen(a1);//把被除数的位数存在len里
    for (int i = 1; i <= len; i++) a[i] = a1[i - 1] - '0';//将被除数一位一位放入a数组
    for (int i = 1; i <= len; ++i)//这一个循环是关键，将被除数一位一位除以除数，不过除，向下
    {                                //一位借位，d为余数，c数组为商
        c[i] = (d * 10 + a[i]) / b;
        d = (d * 10 + a[i]) % b;
    }
    lenc = 1;
    while (c[lenc] == 0 && lenc < len)lenc++;//整理位数，删除前导0
    string answer="";
    for (int i = lenc; i <= len; ++i)answer += to_string(c[i]);; //输出结果
    return answer;
}
string compare(string a,string b){//高精度比较,输出大的
    if(a.size()>b.size())return a;
    else if(a.size()<b.size()) return b;
    else{
        if(a>b)return a;
        else return b;
    }
}
struct people{
    int left,right;
    int k;
}peo[1005];
bool fact(people a,people b){
    return a.k<b.k;
}
signed main(){
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=0;i<n;++i){
        cin>>peo[i].left>>peo[i].right;
        peo[i].k=peo[i].left*peo[i].right;
    }
    sort(peo,peo+n,fact);
    string answer;
    answer=to_string(a);
    string min="0";
    for(int i=0;i<n;++i){
        answer=High_precision_multiplication(answer,to_string(peo[i].left));
        min=compare(min,High_precision_division(answer,peo[i].left*peo[i].right));
    }
    cout<<min;
    return 0;
}