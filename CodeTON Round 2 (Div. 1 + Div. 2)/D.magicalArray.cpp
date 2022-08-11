#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, m;  vector<vector<int>> arr;

void Input() {
    cin >> n >> m;  arr.assign(n + 1, vector<int> (m + 1, 0));

    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> arr[i][j];
}


vector<array<long long, 2>> result;

void Process() {
    for (int i = 1; i <= n; i++) {
        long long sum = 0;

        for (int j = 1; j <= m; j++) sum += 1LL * arr[i][j] * (j - 1);

        result.push_back({sum, i});
    }

    sort(result.begin(), result.end());

    cout << result.back()[1] << ' ' << result.back()[0] - result.front()[0] << '\n';

    result.clear();
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
