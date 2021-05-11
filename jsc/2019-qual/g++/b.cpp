#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int ans = 0, n, k, arr[2005];
    cin >> n >> k;
    rep(int, i, n) 
        cin >> arr[i];
    
    rep(int, num_i, n)
        repi(int, num_j, num_i + 1, n) 
            if (arr[num_i] < arr[num_j]) {
                ans += (k * (k - 1)) >> 1;
                ans %= (int)(1e9) + 7;
            }
            else if (arr[num_i] > arr[num_j]) {
                ans += (k * (k + 1)) >> 1;
                ans %= (int)(1e9) + 7;
            }
    
    cout << ans;
    return 0;
}