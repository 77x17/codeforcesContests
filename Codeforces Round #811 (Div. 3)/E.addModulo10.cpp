#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

const int MAX_N = 2e5 + 77 * 17;


int n, arr[MAX_N];

void Input() {
    cin >> n;  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    int arrMax = 0;

    for (int i = 1; i <= n; i++) if ((arr[i] % 10) & 1) arr[i] = arr[i] + arr[i] % 10;

    for (int i = 1; i <= n; i++) arrMax = max(arrMax, arr[i]);

    for (int i = 1; i <= n; i++) if (arr[i] % 10) {
        arr[i] = arr[i] + ((arrMax - arr[i]) / 20) * 20;

        while (arr[i] % 10 && arr[i] < arrMax) arr[i] = arr[i] + arr[i] % 10;
    }

    for (int i = 1; i < n; i++) if (arr[i] != arr[i + 1]) {
        cout << "NO\n";

        return;
    }

    cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}


