#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int num, ans = 0;
    cin >> num;
    rep(Int, i, num) {
        int a;
        cin >> a;
        ans += max(0, a - 10);
    }

    cout << ans << endl;
    return 0;
}