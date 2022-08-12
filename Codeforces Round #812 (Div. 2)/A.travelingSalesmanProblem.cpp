#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;  vector<array<int, 2>> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, {0, 0});

    for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
}


void Process() {
    int x[2] = {0, 0}, y[2] = {0, 0};

    for (int i = 1; i <= n; i++) {
        x[0] = max(x[0], arr[i][0]),  y[0] = max(y[0], arr[i][1]);

        x[1] = min(x[1], arr[i][0]),  y[1] = min(y[1], arr[i][1]);
    }

    cout << 2 * (x[0] + y[0] - x[1] - y[1]) << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
