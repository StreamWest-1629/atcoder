#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

void multiple(Int& ans, Int data) {
    ans *= data;
    ans %= (Int)1e9 + 7;
}

Int add(Int a, Int b) {
    return (a + b) % ((Int)1e9 + 7);
}

int main() {

    Int n_white, n_black, k, ans = 1;

    cin >> n_white >> n_black >> k;

    if (!n_black) {
        cout << 1 << endl;
        return 0;
    } else if (!n_white) {
        cout << 1 << endl;
        return 0;
    }

    repi (Int, i, 1, n_white + n_black) {
        multiple(ans, min(i, k));
    }

    cout << ans << endl;
    return 0;
}