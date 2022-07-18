#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18 + 7;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


vector<long long> a, b;

void Process() {
    if (n & 1) {
        long long result = 0;

        for (int i = 2; i < n; i += 2) {
            int e = max(arr[i - 1], arr[i + 1]) + 1;

            result += max(0, e - arr[i]);
        }

        cout << result << '\n';
    } else {
        a.assign(n + 2, 0);  b.assign(n + 2, 0);

        for (int i = 2; i < n; i += 2) {
            int e = max(arr[i - 1], arr[i + 1]) + 1;

            a[i] = a[i - 2] + max(0, e - arr[i]);
        }

        for (int i = n - 1; i >= 3; i -= 2) {
            int e = max(arr[i - 1], arr[i + 1]) + 1;

            b[i] = b[i + 2] + max(0, e - arr[i]);
        }

        long long result = INF;

        for (int i = 0; i < n; i += 2) {
            result = min(result, a[i] + b[i + 3]);
        }

        cout << result << '\n';
    }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
