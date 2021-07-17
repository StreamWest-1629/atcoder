#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {
    int n, a, x, y;
    cin >> n >> a >> x >> y;

    cout << min(n, a) * x + max(n - a, 0) * y << endl;
    return 0;
}