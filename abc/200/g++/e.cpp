#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, k, i = 0, num = 0, ans[3] = { 0 }, buf = 3;
    cin >> n >> k;

    auto Increment = [&]() {
        if (ans[1] == k || ans[2] == 1) {
            buf++;
            ans[2] = max(k, buf - ans[0] - 1);
            ans[1] = buf - ans[0] - ans[2];
        }
        else {
            ans[1]++;
            ans[2]--;
        }
    };


    rep(int, i, 3) ans[i] = 1;
    rep(int, i, k - 1) Increment();

    cout << ans[0] << " " << ans[1] << " " << ans[2];

    return 0;
}