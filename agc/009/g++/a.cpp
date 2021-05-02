#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long n, a[(int)1e5 + 5], b[(int)1e5 + 5], ans = 0;
    cin >> n;
    rep(int, i, n) 
        cin >> a[i] >> b[i];
    
    for(int i = n - 1; i > -1; --i) {
        int mod = ((a[i] + ans) % b[i]);
        ans += mod == 0 ? 0 : b[i] - mod;
    }

    cout << ans;
    return 0;
}