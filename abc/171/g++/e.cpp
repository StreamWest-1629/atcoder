#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, a[(int)2e5 + 5], sum = 0;
    cin >> n;
    rep(int, i, n) {
        cin >> a[i];
        sum ^= a[i];
    }
    rep(int, i, n) {
        cout << (sum ^ a[i]);
        if (i + 1 == n) 
            cout << endl;
        else 
            cout << " ";
    }
    return 0;
}