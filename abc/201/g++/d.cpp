#include <bits/stdc++.h>
using namespace std;

#define rep(type, val, n) for(type val = 0; val < n; ++val)
#define repi(type, val, init, end) for(type val = init; val < end; ++val)

using Int = long long;
using uInt = unsigned long long;

int main() {
    Int area_h, area_w;
    bitset<2005> map_a[2005];
    vector<Int> maybe[2005];
    vector<Int> enamy[2005];

    cin >> area_h >> area_w;

    rep(Int, y, area_h) {
        string s;
        map_a[y] = bitset<2005>();
        maybe[y] = vector<Int>(area_w);
        enamy[y] = vector<Int>(area_w);

        cin >> s;
        rep(Int, x, area_w) 
            map_a[y][x] = (s[x] == '+');        
    }

    for (int y = area_h - 1; y > -1; y--) 
        for (int x = area_w - 1; x > -1; x--) {
            maybe[y][x] = map_a[y][x] ? 1 : -1;
            if (x < area_w - 1) {
                enamy[y][x] += maybe[y][x + 1];
                if (x < area_w - 2) {
                    maybe[y][x] += maybe[y][x + 2];
                }
            }
            if (y < area_h - 1) {
                enamy[y][x] += maybe[y + 1][x];
                if (y < area_h - 2) {
                    maybe[y][x] += maybe[y + 2][x];
                }
            }
            if (x < area_w - 1 && y < area_h - 1) {
                maybe[y][x] += maybe[y + 1][x + 1];
            }
        }
    
    Int ans[2] = { 0 };
    Int pos[2] = { 0 };
    rep (Int, count, (area_h + area_w) << 1) {
        if (pos[0] < area_h - 1 && pos[1] < area_w - 1) {
            if (maybe[pos[0] + 1][pos[1]] - enamy[pos[0] + 1][pos[1]] > maybe[pos[0]][pos[1] + 1] - enamy[pos[0] + 1][pos[1]]) {
                pos[0]++;
            }
            else if (maybe[pos[0] + 1][pos[1]] - enamy[pos[0] + 1][pos[1]] < maybe[pos[0]][pos[1] + 1] - enamy[pos[0] + 1][pos[1]])
                pos[1]++;
            else {
                if (maybe[pos[0] + 1][pos[1]] > maybe[pos[0]][pos[1] + 1]) {
                    pos[0]++;
                }
                else if (maybe[pos[0] + 1][pos[1]] < maybe[pos[0]][pos[1] + 1])
                    pos[1]++;
                
            }
        }
        else if (pos[0] < area_h - 1) 
            pos[0]++;
        else if (pos[1] < area_w - 1)
            pos[1]++;
        else
            break;
        ans[count & 1] += (map_a[pos[0]][pos[1]] ? 1 : -1);
    }

    if (ans[0] > ans[1])
        cout << "Takahashi" << endl;
    else if (ans[1] > ans[0])
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;

    return 0;
}