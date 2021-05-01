#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    string s;
    int ans = 0;
    cin >> s;
    rep(int, i, 9) {
        if (s.substr(i, 4) == "ZONe")
            ans++;
    }
    cout << ans << endl;
    return 0;
}