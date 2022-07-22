#include <bits/stdc++.h>

using namespace std;


string s;

void Input() {
     cin >> s;
}


void Process() {
    int l = s.size() / 2 - count(s.begin(), s.end(), '('), r = s.size() / 2 - count(s.begin(), s.end(), ')');

    if (l == 0 || r == 0) {cout << "YES\n";  return;}

    int a = -1, b = -1;

    for (int i = 0; l >= 1; i++) if (s[i] == '?') {
        s[i] = '(';  a = i;  l--;
    }

    for (int i = s.size() - 1; r >= 1; i--) if (s[i] == '?') {
        s[i] = ')';  b = i;  r--;
    }

    int cnt = 0, minCnt = 0;

    swap(s[a], s[b]);

    for (int i = 0; i < s.size(); i++) {
        (s[i] == '(') ? cnt++ : cnt--;

        minCnt = min(minCnt, cnt);
    }

    cout << (minCnt != 0 ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
