#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, m;  vector<int> arr;

void Input() {
    cin >> n >> m;  arr.assign(m + 1, 0);

    for (int i = 1; i <= m; i++) cin >> arr[i];
}


vector<int> f;

void Process() {
    sort(arr.begin() + 1, arr.end());

    f.clear();

    for (int i = 2; i <= m; i++) f.push_back(arr[i] - arr[i - 1] - 1);

    if (arr[1] + n - arr[m] - 1 > 0) f.push_back(arr[1] + n - arr[m] - 1);

    sort(f.begin(), f.end(), greater<int>());

    int result = 0, cnt = 0;

    for (int x : f) {
        if (x - cnt * 2 > 0) {
            int temp = max(1, x - cnt * 2 - 1);

            result += temp;
        }

        cnt += 2;
    }

    cout << n - result << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
