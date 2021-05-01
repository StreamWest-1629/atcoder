#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, d, h;
    cin >> n >> d >> h;
    double ans = 0.0, dd = (double)d, hd = (double)h;
    rep (int, i, n) {
        double dn, hn;
        cin >> dn >> hn;
        ans = max(ans, ((hd - hn) / (dd - dn)) * (-dd) + hd);
    }

    cout << ans << endl;
    return 0;
}