#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {
    Int n, q, a[100005], k[100005];
    map<Int, Int> memo;

    cin >> n >> q;
    rep(int, i, n) cin >> a[i];
    rep(int, i, q) cin >> k[i];

    auto Solve = [&](Int val) {
        if (memo.count(val) > 0) return memo[val];
        else {
            
            Int result = val, added = 0;
            do {

                Int count = n;
                count -= (a + n) - upper_bound(a, a + n, val);
                added = count - added;
                result += added;

            } while(added > 0);

            memo.insert(make_pair(val, result));
            return result;
        }
    };

    rep(int, que_i, q) {
        Int ans = 0;
        for (Int bit_i = 1LL << 62; bit_i > 0; bit_i >>= 1) {
            Int buffer = ans | bit_i;
            Int result = Solve(buffer);
            if (result <= k[que_i]) ans = buffer;
        }
        cout << ans << endl;
    }

    return 0;
}