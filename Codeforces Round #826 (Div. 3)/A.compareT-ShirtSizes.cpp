#include <bits/stdc++.h>
using namespace std;

string s, t;

void Input() {
    cin >> s >> t;
}

int Calc(char x) {
    if (x == 'S') return 0;
    if (x == 'M') return 1;
    if (x == 'L') return 2;
}

void Process() {
    if (s == t) {cout << "=\n"; return;}

    if (Calc(s.back()) == Calc(t.back())) {
        if (Calc(s.back()) == 0) {
            if (s.size() < t.size()) cout << ">\n"; else cout << "<\n";
        } else {
            if (s.size() < t.size()) cout << "<\n"; else cout << ">\n";
        }
    } else {
        if (Calc(s.back()) > Calc(t.back())) cout << ">\n"; else cout << "<\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
