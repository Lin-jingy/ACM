#include <bits/stdc++.h>
#define long long long
using namespace std;

int N, mid, ac, bc;
long M, ans, d[47];

vector <long> ka, kb;

void DFS(int L, int R, long sum, vector <long> &k)
{
	if (sum > M) return;
	if (L > R)
	{
		k.push_back(sum);//累计答案 
		return;
	}
	DFS(L+1, R, sum+d[L], k);
	DFS(L+1, R, sum, k);
}

int main()
{

    for(int I = 1; I <= 10; ++I) {
        std::string address1 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/13/data/{}.in", I);
        std::string address2 = std::format("C:/Users/123/Desktop/programming/VScode/ACM/data/13/data/{}.out", I);
        freopen(address1.c_str(), "r", stdin);
        freopen(address2.c_str(), "w", stdout);


        N = mid = ac = bc = 0;
        M = ans = 0;
        memset(d, 0, sizeof(d));
        ka.resize(0), kb.resize(0);


        cin >> N >> M, mid = N >> 1;
        for (int i = 1; i <= N; i++)
            cin >> d[i];
        DFS(1, mid, 0, ka), DFS(mid+1, N, 0, kb);
        sort(ka.begin(), ka.end());
        for (int i = 0; i < kb.size(); i++)
            ans += upper_bound(ka.begin(), ka.end(), M-kb[i]) - ka.begin();
        //要注意upper_bound找的是严格大于M-kb[i]的第一个数，但是vector下标从0开始，所以刚刚好。 
        cout << ans << endl;

        fclose(stdin);
        fclose(stdout);

        std::clog << I << std::endl;
    }
    return 0;

}


	