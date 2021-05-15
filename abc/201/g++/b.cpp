#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    pair<string, Int> maximum[2];
    int n;
    cin >> n;
    rep (Int, i, n) {
        string str;
        Int h;
        cin >> str >> h;
        if (maximum[0].second < h) {
            swap(maximum[0], maximum[1]);
            maximum[0] = pair<string, Int>(str, h);
        }
        else if (maximum[1].second < h) {
            maximum[1] = pair<string, Int>(str, h);
        }
    }
    cout << maximum[1].first << endl;
    return 0;
}