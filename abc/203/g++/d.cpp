#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int n, k;
    cin >> n >> k;
    Int a[805][805];
    rep (Int, i, n) rep(Int, j, n) 
        cin >> a[i][j];
    
    auto Calc = [&](const Int& x, const Int& y) {
        vector<Int> val = vector<Int>(k * k);
        Int inc = 0;
        repi (Int, min_y, y, y + k)
            repi (Int, min_x, x, x + k)
                val[inc++] = a[min_y][min_x];
        sort(val.begin(), val.end());
        return val[(k * k) - ((k * k) >> 1)];

    };

    auto Count = [&](const Int& x, const Int& y, const Int& min) {
        Int ans = 0;
        repi(Int, count_y, y, y + k) {
            ans += (min < a[count_y][x] ? 1 : 0);
        }
        return ans;
    };

    Int ans = LONG_LONG_MAX;

    rep (Int, a_y, n - k + 1) {    
        
        ans = min(Calc(a_y, 0), ans);

        repi (Int, a_x, 1, n - k + 1) {
            if (Count(a_x - 1, a_y, ans) > Count(a_x + k - 1, a_y, ans)) {
                ans = min(Calc(a_y, a_x), ans);
            }
        }
    }

    cout << ans << endl;
    return 0;
}