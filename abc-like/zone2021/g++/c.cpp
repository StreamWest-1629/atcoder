#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> p[5];
    rep(int, i, 5) p[i] = vector<int>(n);
    
    rep(int, i, n) rep(int, j, 5)
        cin >> p[j][i];
    
    for (int bit_i = (1 << 30); bit_i > 0; bit_i >>= 1) {
        int res = 0;
        int buf = ans | bit_i;
        rep(int, i, n) rep(int, j, 5)
            res |= (p[j][i] >= buf ? (1 << j) : 0);
        if (res == 0x1f)
            ans = buf;
    }
    cout << ans;
    return 0;
}