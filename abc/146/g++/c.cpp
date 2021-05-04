#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    unsigned long long a, b, x, ans = 0;
    cin >> a >> b >> x;

    auto IsGood = [&](unsigned long long num) {
        int d = 1;
        for (unsigned long long max = 10; max <= num; max *= 10) 
            ++d;
        return (b * d <= x - a * num) && (a < x / num);
    };

    if (IsGood((int)1e9)) 
        ans = (int)1e9;
    else 
        for (unsigned long long i = 1 << 30; i > 0; i >>= 1) 
            if (IsGood(ans | i)) 
                ans |= i;
    
    cout << ans << endl;

    return 0;
}