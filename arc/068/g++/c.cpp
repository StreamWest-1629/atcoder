#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long long x, ans, mod;
    cin >> x;
    ans = x / 11;
    ans *= 2;
    mod = x % 11;
    if (mod > 0)
        if (mod < 7)
            ans++;
        else if (mod == 7) 
            ans += 2;
        else 
            ans += 2;

    cout << ans;

    return 0;
}