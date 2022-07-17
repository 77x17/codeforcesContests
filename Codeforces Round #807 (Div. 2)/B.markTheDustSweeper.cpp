#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}


vector<long long> f;

void Process() {
    long long result = 0;

    int l = 1; while (l <= n - 1 && arr[l] == 0) l++;

    for (int i = n - 1; i >= l; i--) if (arr[i] == 0) result++; else result += arr[i];

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
