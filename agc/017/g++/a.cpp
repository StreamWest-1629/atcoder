#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int arg_n, arg_p, arg_a[55], count = 0, ans = 0;
    Int dp[50][2] = { 0 };

    cin >> arg_n >> arg_p;
    rep (Int, i, arg_n) cin >> arg_a[i];

    dp[0][0]++;
    dp[0][arg_a[0] & 1]++;
    
    repi (Int, cockie_i, 1, arg_n) {
        Int before[] = {
            dp[cockie_i - 1][0],
            dp[cockie_i - 1][1]
        };

        dp[cockie_i][0] += before[0];
        dp[cockie_i][1] += before[1];
        if (arg_a[cockie_i] & 1) {
            dp[cockie_i][0] += before[1];
            dp[cockie_i][1] += before[0];
        } else {
            dp[cockie_i][0] += before[0];
            dp[cockie_i][1] += before[1];
        }        
    }
    
    cout << dp[arg_n - 1][arg_p] << endl;
    return 0;
}