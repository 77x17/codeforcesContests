#include <bits/stdc++.h>

using namespace std;


int n, l, r;

void Input() {
    cin >> n >> l >> r;
}


void Process() {
    vector<int> result;

    for (int i = 1; i <= n; i++) {
        int e = (r / i) * i;

        if (e >= l) result.push_back(e);
    }

    if (result.size() == n) {
        cout << "YES\n";

        for (int e : result) cout << e << ' ';  cout << '\n';
    } else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
