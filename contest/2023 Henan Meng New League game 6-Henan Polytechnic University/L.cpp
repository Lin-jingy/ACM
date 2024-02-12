#include<bits/stdc++.h>

#define int long long 
using namespace std;

int countRangeSumRecursive(vector<int>& sum, int lower, int upper, int left, int right) {
    if (left == right) {
        return 0;
    } else {
        int mid = (left + right) / 2;
        int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
        int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
        int ret = n1 + n2;
        int i = left;
        int l = mid + 1;
        int r = mid + 1;
        while (i <= mid) {
            while (l <= right && sum[l] - sum[i] < lower) l++;
            while (r <= right && sum[r] - sum[i] <= upper) r++;
            ret += (r - l);
            i++;
        }
        vector<int> sorted(right - left + 1);
        int p1 = left, p2 = mid + 1;
        int p = 0;
        while (p1 <= mid || p2 <= right) {
            if (p1 > mid) {
                sorted[p++] = sum[p2++];
            } else if (p2 > right) {
                sorted[p++] = sum[p1++];
            } else {
                if (sum[p1] < sum[p2]) {
                    sorted[p++] = sum[p1++];
                } else {
                    sorted[p++] = sum[p2++];
                }
            }
        }
        for (int i = 0; i < sorted.size(); i++) {
            sum[left + i] = sorted[i];
        }
        return ret;
    }
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    long s = 0;
    vector<int> sum{0};
    for(auto& v: nums) {
        s += v;
        sum.push_back(s);
    }
    return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
}



signed main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n, x;
    std::cin >> n >> x;
    std::vector<int>a(n);
    for(int i = 0; i < n; ++i) std::cin >> a[i];
    std::cout << countRangeSum(a, x, LONG_LONG_MAX) << '\n';
    

    return 0;
}