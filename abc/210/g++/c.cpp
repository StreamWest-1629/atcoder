#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {

    int nCandy, kSelect, candies[3 * (int)1e5], buf = 0, ans = 0;
    map<int, int> count = map<int, int>();

    cin >> nCandy >> kSelect;
    rep(int, iCandy, nCandy) 
        cin >> candies[iCandy];

    rep(int, iCandy, kSelect) {
        if (count.count(candies[iCandy]) == 0) {
            count.insert(make_pair(candies[iCandy], 1));
            buf++;
        } else {
            count[candies[iCandy]]++;
        }
    }

    ans = buf;

    repi(int, iCandy, kSelect, nCandy) {
        
        count[candies[iCandy - kSelect]]--;
        if (count[candies[iCandy - kSelect]] == 0) {
            count.erase(candies[iCandy - kSelect]);
            buf--;
        }

        if (count.count(candies[iCandy]) == 0) {
            count.insert(make_pair(candies[iCandy], 1));
            buf++;
            ans = max(ans, buf);
        } else {
            count[candies[iCandy]]++;
        }
    }

    cout << ans << endl;

    return 0;
}