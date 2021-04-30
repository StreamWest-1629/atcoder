#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < n; ++val)
#define band(a, b) pair<int, int>(a, b)

int main() {
    bitset<55> route[55];
    int length[55][55];
    vector<pair<int, int>> query;
    int h, w, white_n = 0;
    cin >> h >> w;
    rep(int, i, h) {
        string in;
        route[i] = bitset<55>(false);
        cin >> in;
        rep(int, j, w) {
            route[i][j] = (in[j] == '.');
            length[i][j] = -1;
            white_n += (in[j] == '.' ? 1 : 0);
        }
    }

    query = vector<pair<int, int>>();
    query.push_back(band(0, 0));
    length[0][0] = 1;

    auto AddQuery = [&](int y, int x, int l) {
        if (route[y][x] && length[y][x] == -1) {
            length[y][x] = l;
            query.push_back(band(y, x)); 
        }
    };
        
    for (int q_i = 0; q_i < query.size(); q_i++) {
        
        auto que = query[q_i];
        auto len = length[que.first][que.second] + 1;

        if (que.first > 0) 
            AddQuery(que.first - 1, que.second, len);
        if (que.first < h - 1)
            AddQuery(que.first + 1, que.second, len);
        if (que.second > 0)
            AddQuery(que.first, que.second - 1, len);
        if (que.second < w - 1)
            AddQuery(que.first, que.second + 1, len);
    }

    cout << (length[h - 1][w - 1] == -1 ? -1 : white_n - length[h - 1][w - 1]);
    return 0;

}