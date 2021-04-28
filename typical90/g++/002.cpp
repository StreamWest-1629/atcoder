#include <bits/stdc++.h>
using namespace std;

int n;
void Solve(string s, const int& rule) {
    if (rule == 0 && n == s.length())
        cout << s << endl;
    else if (rule == n - s.length())
        Solve(s + ")", rule - 1);
    else if (rule < n - s.length()) {
        Solve(s + "(", rule + 1);
        if (rule > 0) {
            Solve(s + ")", rule - 1);
        }
    }
}

int main() {
  cin >> n;
  Solve("(", 1);
}
