#include <bits/stdc++.h>

#define fi first

#define se second

using namespace std;


int n;  long long k;  vector<int> arr;

void Input() {
    cin >> n >> k;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

void Process() {
    long long result = 0, sum = 0;

    for (int i = 1; i <= n; i++) sum += arr[i];

    result = max(result, sum - k * n);

    int m = n;

    for (int i = n; i >= 1; i--) {
        sum -= arr[i];

        long long add = 0;

        for (int j = i; j <= m; j++) arr[j] /= 2, add += arr[j];

        result = max(result, sum + add - k * (i - 1));

        if (arr[m] == 0) m--;
    }

    cout << result << '\n';
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
