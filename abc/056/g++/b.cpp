#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int i = 0;
    int ans = 0;
    int x;
    cin >> x;
    while (i < x) {
        ans++;
        i += ans;
    }
    cout << ans;
    return 0;
}