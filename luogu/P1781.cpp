#include<bits/stdc++.h>
using namespace std;
#define int long long 
// struct xx{
//     int flag;
//     string sum;
// }a[21];
// bool fact(xx a,xx b){
//     return a.sum>b.sum;
// }
 
void sort_string(string *in_array, int n, string *out_array)
{
	vector<string> strArray;
	int i,j = 0;
	for (int i = 0; i < n; i++)
	{ 
		strArray.push_back(in_array[i]);
	}
	sort(strArray.begin(), strArray.end());
	vector<string>::iterator st;
	for (st = strArray.begin(); st != strArray.end(); st++)
	{
		//cout << *st << endl;//打印结果
		out_array[j++] = *st;
	}
}
struct pm{
    string score;
    int k;
}a[21];
struct pm1{
    string score;
    int k;
}b[21];
struct pm2{
    string score;
    int k;
}c[21];
int r=0;
signed main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;++i){
        cin>>a[i].score;
        a[i].k=i+1;
    }
    int max=a[0].score.size();
    for(int i=0;i<t;++i){
        if(a[i].score.size()>max)max=a[i].score.size();
    }
    for(int i=0;i<t;++i){
        if(a[i].score.size()==max){
            b[r].score=a[i].score;
            b[r].k=a[i].k;
            r++;
        }
    }
    string str[21];
    int u=0;
    for(int i=0;i<r;++i){
        str[u]=b[i].score;
        u++;
    }
    int flag;
    sort(str,str+u);
    for(int i=0;i<r;++i){
        if(str[r-1]==b[i].score)
            flag=b[i].k;
    }
    cout<<flag<<'\n'<<str[r-1];
    return 0;
}