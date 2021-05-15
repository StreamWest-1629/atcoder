#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    if (a[1] - a[0] == a[2] - a[1]) 
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    return 0;
}