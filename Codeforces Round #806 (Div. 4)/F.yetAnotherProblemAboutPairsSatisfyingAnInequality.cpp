#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {cin >> arr[i]; arr[i]++;}
}


struct FenwickTree {
    int n; vector<int> bit;

    FenwickTree(int n = 0): n(n) {
        bit.assign(n + 1, 0);
    }

    void update(int i, int val) {
        for (; i <= n; i += i & -i) bit[i] += val;
    }

    long long get(int i) {
        long long ans = 0;

        for (; i > 0; i -= i & -i) ans += bit[i];

        return ans;
    }
} BIT;

void Process() {
    long long result = 0;

    BIT = FenwickTree(n + 1);

    for (int i = 1; i <= n; i++) if (arr[i] <= i) {
        result += BIT.get(arr[i] - 1);

        BIT.update(i + 1, 1);
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
