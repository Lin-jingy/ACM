#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int p1,p2,p3;
    string str;
    cin>>p1>>p2>>p3>>str;
    int len=str.size();
    for(int i=0;i<len;++i){
        if(str[i]=='-' && i!=0 && i!=len-1 && str[i-1]!='-'){
            int first=str[i-1],last=str[i+1];
            if(first+1==last)continue;
            if(first>=last||(first>='0'&&first<='9'&&last>'9')||(first>='A'&&first<='Z'&&last>'Z')){cout<<'-';continue;}
            string ans="";
            if(p3==2){
                for(int j=last-1;j>first;--j){
                    for(int k=0;k<p2;++k){
                        if(p1==1 && (j>='a' && j<='z' || j>='0' && j<='9'))ans+=(char)j;
                        else if(p1==1 && (j>='A' && j<='Z'))ans+=((char)j+'a'-'A');
                        else if(p1==2 && (j>='a' && j<='z'))ans+=((char)j+('A'-'a'));
                        else if(p1==2 && (j>='A' && j<='Z' || j>='0' && j<='9'))ans+=(char)j;
                        else if(p1==3)ans+='*';
                    }
                }
            }else{
                for(int j=first+1;j<last;++j){
                   for(int k=0;k<p2;++k){
                        if(p1==1 && (j>='a' && j<='z' || j>='0' && j<='9'))ans+=(char)j;
                        else if(p1==1 && (j>='A' && j<='Z'))ans+=((char)j+'a'-'A');
                        else if(p1==2 && (j>='a' && j<='z'))ans+=((char)j+('A'-'a'));
                        else if(p1==2 && (j>='A' && j<='Z' || j>='0' && j<='9'))ans+=(char)j;
                        else if(p1==3)ans+='*';
                    }
                }
            }
            cout<<ans;
        }else {
            cout<<str[i];
        }
    }
    return 0;
}