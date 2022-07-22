#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 77 * 17;

const int LOG = log(MAX_N) / log(2) + 1;


int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;  for (int i = 1; i <= m; i++) cin >> arr[i];
}


int sparse[MAX_N][LOG];

int getMax(int l, int r) {
    int k = log(r - l + 1) / log(2);

    return max(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

void Process() {
    for (int i = 1; i <= m; i++) sparse[i][0] = arr[i];

    for (int k = 0; k < LOG; k++) {
        for (int i = 1; i + (1 << (k + 1)) <= m; i++) {
            sparse[i][k + 1] = max(sparse[i][k], sparse[i + (1 << k)][k]);
        }
    }

    int q; cin >> q; while (q--) {
        int x[2], y[2], k; cin >> x[0] >> y[0] >> x[1] >> y[1] >> k;

        if (abs(x[0] - x[1]) % k || abs(y[0] - y[1]) % k) {cout << "NO\n";  continue;}

        int delta = n - (n - x[0]) % k;

        if (getMax(min(y[0], y[1]), max(y[0], y[1])) < delta) cout << "YES\n"; else cout << "NO\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
