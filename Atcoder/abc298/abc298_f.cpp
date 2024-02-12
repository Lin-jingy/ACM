// #include<bits/stdc++.h>
// #include<unordered_map>

// #define int long long 
// using namespace std;
// using PII = pair<int, int>;
// const int N = 2e5 + 5;

// struct hash_pair { 
//     template <class T1, class T2> 
//     size_t operator()(const pair<T1, T2>& p) const
//     { 
//         auto hash1 = hash<T1>{}(p.first); 
//         auto hash2 = hash<T2>{}(p.second); 
//         return hash1 ^ hash2; 
//     } 
// }; 

// class node{
// public:
//     int first,second;
//     friend bool operator < (node a, node b){
//         return a.second > b.second;
//     }
// };

// unordered_map<PII, int, hash_pair>mp;
// unordered_map<int, int>mx, my;
// set<node>sx, sy;

// void solve(){
//     int n;
//     cin >> n;
//     int x, y, v;
//     while(n--){
//         cin >> x >> y >> v;
//         mx[x] += v;
//         mx[y] += v;
//     }
//     for(auto i : mx)sx.insert({i.first,i.second});
//     for(auto i : my)sy.insert({i.first,i.second});
//     int ans = 0;
//     for(auto i:sx){
//         for(auto j:sy){
//             int flag = 0;
//             if(mp.count({i.first, j.first})){
//                 //if(flag)break;
//                 if(i.second + j.second - mp[{x, y}] > ans) ans = i.second + j.second - mp[{x, y}];
//             }
//             else {
//                 flag = 1;
//                 if(i.second + j.second > ans)ans = i.second + j.second;
//                 //else break;
//             }
//             //else if(!mp.count({i.first, j.first}) and i.second + j.second < ans)break;
//         }
//     }
//     cout << ans;
// }

// signed main(){
//     ios::sync_with_stdio(0),cin.tie(0);
//     solve();
//     return 0;
// }

#include <bits/stdc++.h>
#include<unordered_map>

#define int long long

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const std::pair<T1, T2>& p) const
    { 
        auto hash1 = std::hash<T1>{}(p.first); 
        auto hash2 = std::hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 

signed main(){
    
    int n, x, y, z, ans(0);
	std::cin >> n;
	
    std::unordered_map<int, int> R, C;
    std::vector<std::pair<int, int>> r, c; 
    std::unordered_map<std::pair<int, int>, int, hash_pair> mp;
    
	for (int i = 1; i <= n; i ++ ){
		std::cin >> x >> y >> z;	
		mp[{x, y}] = z;
		R[x] += z;
		C[y] += z;
	}
	
	for (auto e : R) r.push_back({e.second, e.first});
	for (auto e : C) c.push_back({e.second, e.first});
	
	std::sort(r.begin(), r.end(), std::greater<>());
	std::sort(c.begin(), c.end(), std::greater<>());
	
	for (auto _r : r){
		for (auto _c : c){
			if (!mp.count({_r.second, _c.second})){
				ans = std::max(ans, _r.first + _c.first);
				break;
			}
			else ans = std::max(ans, _r.first + _c.first - mp[{_r.second, _c.second}]);	
        }
    }
	
    std::cout << ans;
	
	return 0;
}