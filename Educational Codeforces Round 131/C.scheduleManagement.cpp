#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 77 * 17;


int n, m, arr[MAX_N];

void Input() {
    cin >> n >> m;  for (int i = 1; i <= m; i++) cin >> arr[i];
}


int cnt[MAX_N];

void Process() {
    for (int i = 1; i <= n; i++) cnt[i] = 0;

    for (int i = 1; i <= m; i++) cnt[arr[i]]++;

    int low = 0, high = 2 * m, result = 0;

    while (low <= high) {
        int mid = (low + high) >> 1;

        long long extra = 0, need = 0;

        for (int i = 1; i <= n; i++) {
            if (cnt[i] <= mid) extra += (mid - cnt[i]) / 2;
            else need += cnt[i] - mid;
        }

        if (extra >= need) result = mid, high = mid - 1;
        else low = mid + 1;
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
