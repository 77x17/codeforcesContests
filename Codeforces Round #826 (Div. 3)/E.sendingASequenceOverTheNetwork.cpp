#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200000 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    vector<int> s;

    for (int i = 1; i <= n; i++) {
        s.push_back(arr[i]);

        if (s.size() >= 2 && s.front() == s.size() - 1) s.clear();

        if (s.size() >= 2 && s.back() == s.size() - 1) s.clear();
    }

    if (s.empty()) {cout << "YES\n"; return;}

    s.clear();

    for (int i = 1; i <= n; i++) {
        s.push_back(arr[i]);

        if (s.size() >= 2 && s.front() == s.size() - 1) s.clear();

        if (s.size() >= 2 && s.back() == s.size() - 1) s.clear();
    }

    if (s.empty()) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
