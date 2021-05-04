#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    
    int n, b[100], buf[100] = { 0 }, ans[100] = { 0 };
    cin >> n;
    rep (int, i, n) {
        cin >> b[i];
        buf[i] = i + 1;
    }

    for (int i = n; i > 0; --i) {
        bool slv = false;
        for (int j = n - 1; j > -1 && (!slv); --j) {
            if (buf[j] == b[j]) {
                slv = true;
                ans[i - 1] = buf[j];
                buf[j] = 0;

                repi(int, k, j + 1, n) {buf[k]--;}
            }
        }
        if (!slv) {
            cout << -1 << endl;
            return 0;
        }
    }

    rep(int, i, n) cout << ans[i] << endl;

    return 0;
}