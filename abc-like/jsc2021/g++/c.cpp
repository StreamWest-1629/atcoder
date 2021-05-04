#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

long long PowMod(long long num, long long exp, int mod) {
    num %= mod;
    long long ans = 1;
    while (exp > 0) {
        if (exp & 1) {
            ans *= num;
            ans %= mod;
        }
        num *= num;
        num %= mod;
        exp >>= 1;
    }
    return ans;
}
int main() {

    long long n, p, ans;
    cin >> n >> p;
    ans = (p - 1) * PowMod(p - 2, n - 1, (int)1e9 + 7);
    ans %= (int)1e9 + 7;
    cout << ans;
    return 0;
}
