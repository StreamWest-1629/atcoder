#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int n, t[100], sum = 0, count;
    cin >> n;
    rep(Int, i, n) cin >> t[i], sum += t[i];
    
    count = (sum >> 1) + 1;

    vector<bool> res = vector<bool>(count);
    for(auto itr = res.begin(); itr != res.end(); itr++) *itr = false;
    res[0] = true;

    for(int i = 0; i < n; ++i) {
        vector<bool> buf = vector<bool>(count);
        for(auto itr = buf.begin(); itr != buf.end(); itr++) *itr = false;
        for (int j = 0; j < count - (t[i] - 1); j++) 
            if (res[j]) {
                buf[j + t[i]] = true;
            }
        for (int j = 0; j < count; j++)
            if (res[j]) { 
                buf[j] = true;
            }
        
        swap(res, buf);
    };

    for (Int i = count - 1; i > -1; --i)
        if (res[i]) {
            cout << max(i, sum - i);
            return 0;
        }

    return 0;
}