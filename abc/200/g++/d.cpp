#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using intpair = pair<int, int>;

int main() {
    int n, a[205];
    vector<pair<int, vector<int>>> movable[200];
    vector<vector<int>> mod[200];
    cin >> n;
    rep(int, i, n) {
        cin >> a[i];
        a[i] %= 200;
    }
    rep(int, i, 200) {
        movable[i] = vector<pair<int, vector<int>>>();
        mod[i] = vector<vector<int>>();
    }

    vector<int> zero = vector<int>();
    zero.push_back(0);
    mod[a[0]].push_back(zero);
    movable[0].push_back(pair<int, vector<int>>(a[0], zero));

    auto Solve = [&](int index, int __mod, vector<int> add_vec) {
        __mod %= 200;
        if (mod[__mod].size() > 0) {
            cout << "Yes" << endl;
            cout << mod[__mod][0][0] + 1;
            repi(int, i, 1, mod[__mod][0].size()) {
                cout << " " << mod[__mod][0][i] + 1;
            }
            cout << endl;
            
            rep(int, i, add_vec.size())
                cout << add_vec[i] + 1 << " ";
            cout << index + 1 << endl;
            return true;
        }
        else {
            vector<int> indexes = vector<int>(add_vec);
            indexes.push_back(index);
            mod[__mod].push_back(indexes);
            movable[index].push_back(pair<int, vector<int>>(a[0], indexes));
            return false;
        }
    };

    repi(int, i, 1, n) {
        if (Solve(i, a[i], vector<int>())) return 0;
        rep(int, j, i) 
            rep(int, k, movable[j].size()) {
                int mod = get<0>(movable[j][k]) + a[i];
                vector<int> vec = get<1>(movable[j][k]);
                if (Solve(i, mod, vec)) return 0;
            }
    }

    cout << "No" << endl;
    
    return 0;
}