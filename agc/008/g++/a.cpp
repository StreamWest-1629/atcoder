#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int x, y, ans;
    cin >> x >> y;

    if (0 <= x)
        if (x <= y)
            ans = y - x;
        else if (y > 0) 
            ans = 2 + (x - y);
        else
            ans = 1 + abs(x + y);
    else 
        if (y < x) 
            ans = 2 + (x - y);
        else if (y <= 0)
            ans = y - x;
        else 
            ans = 1 + abs(x + y);

    cout << ans << endl;

    return 0;
}