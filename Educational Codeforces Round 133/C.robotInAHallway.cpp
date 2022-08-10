#include <bits/stdc++.h>

using namespace std;


int m;  vector<int> arr[2];

void Input() {
    cin >> m;  arr[0].assign(m, 0);  arr[1].assign(m, 0);

    for (int i = 0; i <= 1; i++) for (int j = 0; j <= m - 1; j++) cin >> arr[i][j];
}


vector<int> dp[2];

void Process() {
    dp[0].assign(m + 1, 0);  dp[1].assign(m + 1, 0);

    arr[0][0]--;

    for (int i = 0; i <= 1; i++) for (int j = m - 1; j >= 0; j--) {
        dp[i][j] = max(max(arr[i][j] + 2 * (m - j) - 1, dp[i][j + 1] + 1), arr[i ^ 1][j]);
    }

    int result = INT_MAX, cur = 0;

    for (int i = 0; i <= m - 1; i++) {
        int j = i & 1;

        result = min(result, max(cur, dp[j][i]));

        cur = max(cur, arr[j][i] + 2 * (m - i) - 1);

        cur = max(cur, arr[j ^ 1][i] + 2 * (m - i) - 2);
    }

    cout << result + 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
