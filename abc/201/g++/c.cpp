#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    string in;
    cin >> in;
    vector<Int> need = vector<Int>();
    vector<Int> disneed = vector<Int>();
    Int ans = 0;

    rep(Int, str_i, 10) {
        switch (in[str_i]) {
            case 'o':
                need.push_back(str_i);
                break;
            case 'x':
                disneed.push_back(str_i);
                break;
        }
    }
    rep(Int, val_i, 10000) {
        Int number[4] = {
            val_i / 1000,
            (val_i % 1000) / 100,
            (val_i % 100) / 10,
            val_i % 10
        };
        auto hasNum = [&](Int check) {
            return number[0] == check ||
                number[1] == check ||
                number[2] == check ||
                number[3] == check;
        };

        rep (Int, arr_i, need.size()) {
            if (!hasNum(need[arr_i]))
                goto __continue;
        }
        rep (Int, arr_i, disneed.size()) {
            if (hasNum(disneed[arr_i]))
                goto __continue;
        }
        ans++;
        __continue:
        ans;
    }
    cout << ans << endl;
    return 0;
}