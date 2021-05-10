#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int n, a[100], Area[205], ans = 40000 * 105;
    rep(int, i, 205) 
        Area[i] = i * i;
    cin >> n;
    rep(int, i, n)
        cin >> a[i];
    
    repi(int, i, -100, 101) {
        Int sum = 0;
        rep(int, j, n) 
            sum += Area[abs(a[j] - i)];
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}