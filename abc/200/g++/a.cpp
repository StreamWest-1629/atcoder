#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int in;
    cin >> in;
    cout << (in - 1) / 100 + 1 << endl;
    return 0;
}