#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string ans;

    if (c % 2 == 0) {
        a = abs(a);
        b = abs(b);
    }

    if (a > b) ans = ">";
    else if (a < b) ans = "<";
    else ans = "=";

    cout << ans << endl;

    return 0;
}