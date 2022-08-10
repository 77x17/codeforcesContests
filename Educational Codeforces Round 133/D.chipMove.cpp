#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int n, k;

void Input() {
    cin >> n >> k;
}


vector<int> dp, result, sum;

void Process() {
    dp.assign(n + 1, 0);  result.assign(n + 1, 0);  dp[0] = 1;

    for (int x = 0; x + k <= n; x += k++) {
        sum.assign(k + 1, 0);

        for (int i = x; i <= n; i++) {
            int temp = dp[i];

            dp[i] = sum[i % k];

            int j = i % k;

            sum[j] = (sum[j] + temp) % MOD;

            result[i] = (result[i] + dp[i]) % MOD;
        }
    }

    for (int i = 1; i <= n; i++) cout << result[i] << " \n"[i == n];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    Input();

    Process();

    return 0;
}
