#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

vector<vector<Int>> town;
Int town_n, route_n, ans = 0;

bool Solve(int begin, int end, int depth = 0) {
    if (depth > town_n) return false;

    if (!town[begin][end]) {
        rep(Int, town_i, town_n) 
            if (town_i != begin) 
                if (town[begin][town_i] == 1)
                    if (Solve(town_i, end, depth + 1) == true)
                        town[begin][end] = 1;
                        return true;
        town[begin][end] = -1;
        return false;
    } else 
        return town[begin][end] == 1 ? true : false;
        
}

int main() {
    cin >> town_n >> route_n;

    town = vector<vector<Int>>(town_n);

    rep(Int, town_i, town_n) {
        town[town_i] = vector<Int>(town_n);
        rep(Int, town_j, town_n)
            town[town_i][town_j] = 0;
        town[town_i][town_i] = 1;
    }

    rep(Int, route_i, route_n) {
        Int a, b;
        cin >> a >> b;
        --a, --b;
        town[a][b] = 1;
    }

    rep(Int, town_i, town_n) rep(Int, town_j, town_n) 
        if (Solve(town_i, town_j)) 
            ans++;

    cout << ans << endl;

    return 0;
}