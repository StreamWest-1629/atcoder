#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << x << endl;
    } else {
        if (x != 0 && y != 0) cout << 0 << endl;
        if (x != 1 && y != 1) cout << 1 << endl;
        if (x != 2 && y != 2) cout << 2 << endl;
    }
    return 0;
}