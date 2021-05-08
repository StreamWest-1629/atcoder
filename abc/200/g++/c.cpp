#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, mod[205] = { 0 };
    long long ans = 0;
    cin >> n;
    rep(int, i, n) {
        long long a;
        cin >> a;
        mod[a % 200]++;
    }
    rep(int, i, 205) {
        ans += (mod[i] * (mod[i] - 1)) / 2;
    }

    cout << ans;
    
    return 0;
}