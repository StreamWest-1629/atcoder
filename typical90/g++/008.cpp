#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < n; ++val)
#define band(a, b) pair<int, int>(a, b)

int main() {
    int n;
    string s;
    vector<long> str_i[6];
    auto atcoder = "atcoder";
    cin >> n;
    rep(int, i, 6) {
        str_i[i] = vector<long>(n);
        rep(int, j, n) 
            str_i[i][j] = 0;
    }
    cin >> s;

    rep(int, j, 6)
        str_i[j][0] = (s[0] == atcoder[j] ? 1 : 0);

    repi(int, i, 1, n) {
        rep(int, j, 6) 
            str_i[j][i] = str_i[j][i - 1] + (s[i] == atcoder[j] ? 1 : 0);
    }

    rep(int, i, n) 
        repi(int, j, 1, 6) {
            str_i[j][i] *= str_i[j - 1][i];
            str_i[j][i] %= (long)1e9 + 7;
        }
    
    long ans = 0;
    rep(int, i, n)
        ans += (s[i] == atcoder[6] ? str_i[5][i] : 0);

    ans %= (long)1e9 + 7;
    cout << ans << endl;
    return 0;
}