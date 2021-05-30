#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int arg_n, arg_m;
    map<Int, vector<Int>> black = map<Int, vector<Int>>();
    list<Int> white = list<Int>();

    cin >> arg_n, arg_m;

    rep (Int, i, arg_m) {
        Int x, y;
        cin >> x >> y;
        if (black.count(x)) {
            black.at(x).push_back(y);
        } else {
            black.insert(make_pair(x, vector(1, y)));
        }
    }

    for (auto enamy = black.begin(); enamy != black.end(); enamy++) {
        sort((*enamy).second.begin(), (*enamy).second.end());
    }

    Int ans = 0;
    Int before = (arg_n << 1) + 1;

    for (Int )
    
    return 0;
}