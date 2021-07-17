#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

template<typename Ty>
using in = const Ty&;

int main() {

    int height, width, c; Int ans = LONG_LONG_MAX;
    int grid[1000][1000] = { 0 };

    cin >> height >> width >> c;
    rep(int, i, height) rep(int, j, width) cin >> grid[i][j];

    rep(long long, stHeight, height) rep(long long, stWidth, width) {
        
        int filled[1000][1000] = { 0 };
        queue<pair<int, int>> que = queue<pair<int, int>>();

        filled[stHeight][stWidth] = grid[stHeight][stWidth];

        que.push(make_pair(stHeight, stWidth));

        while(que.size()) {
            
            auto at = que.front();
            que.pop();

            if (at.first > 0)
                if (filled[at.first - 1][at.second] == 0) {

                    auto length = abs(stHeight - (at.first - 1)) + abs(stWidth - at.second) + grid[stHeight][stWidth] + grid[at.first - 1][at.second];
                    filled[at.first - 1][at.second] = length;

                    if (length < ans) {
                        ans = length;
                    }
                    if (length - grid[at.first - 1][at.second] < ans) {
                        que.push(make_pair(at.first - 1, at.second));
                    }
                }
            if (at.first < height - 1)
                if (filled[at.first + 1][at.second] == 0) {

                    auto length = abs(stHeight - (at.first + 1)) + abs(stWidth - at.second) + grid[stHeight][stWidth] + grid[at.first + 1][at.second];
                    filled[at.first + 1][at.second] = length;

                    if (length < ans) {
                        ans = length;
                    }
                    if (length - grid[at.first + 1][at.second] < ans) {
                        que.push(make_pair(at.first + 1, at.second));
                    }
                }
            if (at.second > 0)
                if (filled[at.first][at.second - 1] == 0) {

                    auto length = abs(stHeight - at.first) + abs(stWidth - (at.second - 1)) + grid[stHeight][stWidth] + grid[at.first][at.second - 1];
                    filled[at.first][at.second - 1] = length;

                    if (length < ans) {
                        ans = length;
                    }
                    if (length - grid[at.first][at.second - 1] < ans) {
                        que.push(make_pair(at.first, at.second - 1));
                    }
                }
            if (at.second < width - 1)
                if (filled[at.first][at.second + 1] == 0) {

                    auto length = abs(stHeight - at.first) + abs(stWidth - (at.second + 1)) + grid[stHeight][stWidth] + grid[at.first][at.second + 1];
                    filled[at.first][at.second + 1] = length;

                    if (length < ans) {
                        ans = length;
                    }
                    if (length - grid[at.first][at.second + 1] < ans) {
                        que.push(make_pair(at.first, at.second + 1));
                    }
                }
            
        }
        
    }

    cout << ans << endl;

    return 0;
}