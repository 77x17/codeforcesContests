#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, x;  vector<int> arr;

void Input() {
    cin >> n >> x;

    arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    int Max = 0, Min = INT_MAX, result = 0;

    for (int i = 1; i <= n; i++) {
        Max = max(Max, arr[i]);

        Min = min(Min, arr[i]);

        if (Max - Min > 2 * x) {
            result++;

            Max = Min = arr[i];
        }
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

