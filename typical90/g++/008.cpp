#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)
#define band(a, b) pair<int, int>(a, b)

int main() {
    int n;
    string s;
    vector<long> str_i[7];
    auto atcoder = "atcoder";
    cin >> n;
    rep(int, i, 7) {
        str_i[i] = vector<long>(n);
        rep(int, j, n) 
            str_i[i][j] = 0;
    }
    cin >> s;

    str_i[0][0] = s[0] == atcoder[0] ? 1 : 0;

    repi(int, i, 1, n) 
        str_i[0][i] = str_i[0][i - 1] + (s[i] == atcoder[0] ? 1 : 0);
    
    repi(int, i, 1, 7) {
        
        str_i[i][0] *= str_i[i - 1][0];

        repi(int, j, 1, n) {
            str_i[i][j] = str_i[i][j - 1] + (s[j] == atcoder[i] ? str_i[i - 1][j] : 0);
            str_i[i][j] %= (long)(1e9 + 7);
        }
    }

    long ans = str_i[6][n - 1];
    cout << (ans % (long)(1e9 + 7)) << endl;
    return 0;
}