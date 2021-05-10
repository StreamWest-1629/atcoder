#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {

    Int n, m, count = 1;
    vector<vector<Int>> map;
    queue<int> choice = queue<int>();
    vector<Int> ans;

    cin >> n >> m;
    map = vector<vector<Int>>(n);
    ans = vector<Int>(n);
    rep(int, i, n) {
        map[i] = vector<Int>();
        ans[i] = -1;
    }
    rep(int, i, m) {
        Int a, b;
        cin >> a >> b;
        a--, b--;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    rep(int, i, map[0].size()) 
        if (ans[map[0][i]] == -1) {
            ans[map[0][i]] = 1;
            choice.push(map[0][i]);
        }
    while (!choice.empty()) {
        auto choose = choice.front();
        choice.pop();
        rep(int, i, map[choose].size()) 
            if (ans[map[choose][i]] == -1) {
                ans[map[choose][i]] = choose + 1;
                choice.push(map[choose][i]);
                count++;
            }
    }

    cout << "Yes" << endl;
    repi(int, i, 1, n)
        cout << ans[i] << endl;
    return 0;
}