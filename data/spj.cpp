#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
const int MAX = 1e9 * 2;
const int N = 1e6 + 10;

int l[N], r[N], c[N], v[N];
string has[30];
int n, l,a,b;
int main(int argc, char *argv[])
{
	registerTestlibCmd(argc, argv);
	inf.name = ouf.name = ans.name = "";
	int n = inf.readInt();
	// inf.readSpace();
	int l = inf.readInt();
	// inf.readEoln();
	int a=inf.readInt();
	int b=inf.readInt();
	string v1 = ans.readLine();
	// ans.readEoln();
	string v2 = ouf.readLine();
	// ouf.readEoln();
	if (v1!=v2) quitf(_wa, "WA");
	string sta1="Hardly win";
	string sta2="Doomed to Die";
	string sta3="So Easy";
	if (v2==sta2) quitf(_ok, "AC");
	for (int i=1; i<=l; i++){
		has[i]=readToken();
	}
	if (v2==sta1){
		int flag=0;
		for (int i=1; i<=n; i++){
			int nowa=a,nowb=b;
			for (int j=1; j<=l; j++){
				string now=ouf.readToken();
				if (now=="Attack" && has[j]=="Attack") nowa--;
				if (now=="Attack" && has[j]=="Parry") nowb--;
				if (nowa==0 || nowb==0) break;
			}
			if (nowa==0) {
				flag=1;
				break;
			}
		}
		if (flag) quitf(_ok, "AC");
		else quitf(_wa, "WA");
	}
	if (v2==sta3){
		int flag=1;
		for (int i=1; i<=n; i++){
			int nowa=a,nowb=b;
			for (int j=1; j<=l; j++){
				string now=ouf.readToken();
				if (now=="Attack" && has[j]=="Attack") nowa--;
				if (now=="Attack" && has[j]=="Parry") nowb--;
				if (nowa==0 || nowb==0) break;
			}
			if (nowa!=0) {
				flag=0;
				break;
			}
		}
		if (flag) quitf(_ok, "AC");
		else quitf(_wa, "WA");
	}
	return 0;
}
