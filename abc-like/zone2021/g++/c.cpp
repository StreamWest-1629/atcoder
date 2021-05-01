#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    long n, p[3005][5], ans = 0, buf[5] = { 0 };
    cin >> n;
    rep(int, i, n)
        rep(int, j, 5)
            cin >> p[i][j];
    
    auto result = [&](int a, int b, int c) {
        long res = 1e10;
        rep(int, i, 5)
            res = min(res, max(p[a][i], max(p[b][i], p[c][i])));
        return res;
    };

    long a = 0, b = 1, c = 2;
    long max = result(a, b, c);

    auto maximize = [&](int toa, int tob, int toc, long val) {
        if (val > max) {
            a = toa;
            b = tob;
            c = toc;
            max = val;
        }
    };

    repi(int, i, 3, n) {
        long max_a = result(i, b, c), 
            max_b = result(a, i, c),
            max_c = result(a, b, i);
        if (max_a > max_b) 
            if (max_a > max_c) 
                maximize(i, b, c, max_a);
            else 
                maximize(a, b, i, max_c);
        else
            if (max_b > max_c)
                maximize(a, i, c, max_b);
            else
                maximize(a, b, i, max_c);
    }

    cout << max << endl;
    return 0;
}