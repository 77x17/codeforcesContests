#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> a, b;

void Input() {
    cin >> n;  a.assign(n + 1, 0);  b.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> a[i];  for (int i = 1; i <= n; i++) cin >> b[i];
}


void Process() {
    multiset<int, greater<int>> target, arr;

    for (int i = 1; i <= n; i++) {
        while (not (a[i] & 1)) a[i] /= 2;

        target.insert(a[i]);  arr.insert(b[i]);
    }

    bool ok = true;

    for (auto u : arr) if (ok) {
        ok = false;

        while (not target.count(u)) {
            if (u == 1) break;

            u /= 2;
        }

        if (target.count(u)) target.erase(target.find(u)), ok = true;
    }

    cout << (ok ? "YES" : "NO") << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
