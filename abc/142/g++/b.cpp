#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

Int getGcd(Int a, Int b) {
    return (a % b ? getGcd(b, a % b) : b);
}

Int GetGcd(Int a, Int b) {
    return getGcd(max(a, b), min(a, b));
}

int main() {
    Int a, b, gcd, ans = 1;

    cin >> a >> b;
    gcd = GetGcd(a, b);

    for (Int num_i = 2; num_i * num_i < gcd; num_i++) {
        bool isInclude = false;
        while (!(gcd % num_i)) {
            isInclude = true;
            gcd /= num_i;
        }
        
        if (isInclude) {
            ans++;
        }
    }

    if (gcd > 1) ans++;
    cout << ans << endl;

    return 0;
}