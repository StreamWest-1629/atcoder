#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int a, b, c;
    cin >> a >> b >> c;
    if (a == b) 
        cout << c;
    else if (b == c)
        cout << a;
    else if (c == a)
        cout << b;
    else 
        cout << 0;
    cout << endl;
    return 0;
}