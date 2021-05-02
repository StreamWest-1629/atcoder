#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, ans = 0;
    cin >> n;
    vector<int> p[5];
    rep(int, i, 5) {
        p[i] = vector<int>(n);
    }
    
    rep(int, i, n) rep(int, j, 5)
        cin >> p[j][i];
    
    for (int bit_i = (1 << 29); bit_i > 0; bit_i >>= 1) {
        int res = 0;
        int buf = ans | bit_i;
        int array[32] = { 0 };

        rep(int, i, n) {
            int add = 0;
            rep(int, j, 5) 
                if (p[j][i] >= buf) {
                    add |= (1 << j);
                }
            array[add]++;
        }

        rep(int, i, 30) 
            repi(int, j, i + 1, 31)
                repi(int, k, j + 1, 32)
                    if ((i | j | k) == 31)
                        if (array[i] && array[j] && array[k]) {
                            ans = buf;
                            goto jump;
                        }
        jump:;
    }
    cout << ans;
    return 0;
}