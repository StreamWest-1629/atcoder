#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    long ans = ((n - 1) << 1);

    repi(int, i, 1, n - 1) 
        ans += n - 1 + ((s[i] == 'U') ?
        i : (n - 1) - i);

    cout << ans << endl;
    return 0;
}