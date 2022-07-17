#include <bits/stdc++.h>

using namespace std;


int n;  string a, b;

void Input() {
    cin >> n >> a >> b;
}


void Process() {
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        cout << -1 << '\n';  return;
    }

    vector<int> c, d;

    for (int i = 1; i < n; i++) {
        if (a[i - 1] != a[i]) c.push_back(i);

        if (b[i - 1] != b[i]) d.push_back(i);
    }

    long long result = -1;

    if (c.size() == d.size()) {
        result = 0;

        for (int i = 0; i < c.size(); i++) result += abs(c[i] - d[i]);
    }

    cout << result << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
