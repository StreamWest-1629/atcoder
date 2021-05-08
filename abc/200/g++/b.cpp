#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long long n, k;
    cin >> n >> k;
    rep(int, i, k) {
        if (n % 200 == 0) {
            n /= 200;
        } else {
            n = n * 1000 + 200;
        }
    }
    cout << n;
    return 0;
}