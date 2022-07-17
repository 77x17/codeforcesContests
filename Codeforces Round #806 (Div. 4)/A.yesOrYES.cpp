#include <bits/stdc++.h>

using namespace std;


string s;

void Input() {
    cin >> s;
}


void Process() {
    for (int i = 0; i <= min(2, (int)s.size()); i++) s[i] = tolower(s[i]);

    if (s == "yes") cout << "YES\n"; else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    if (fopen("Task.inp", "r")) freopen("Task.inp", "r", stdin), freopen("Task.out", "w", stdout);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
