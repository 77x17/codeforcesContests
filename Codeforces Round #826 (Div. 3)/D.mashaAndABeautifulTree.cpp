#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 262144 + 1;

int n, arr[MAX_N];

void Input() {
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> arr[i];
}

int Calc(int x) {
    if (x == 1) return 0;

    for (int i = 1; i + 1 <= x; i += 2) if (abs(arr[i] - arr[i + 1]) > 1) return -1;

    int result = 0;

    for (int i = 1; i <= x; i += 2) if (arr[i] > arr[i + 1]) result++;

    int cnt = 1;

    for (int i = 1; i <= x; i += 2) arr[cnt++] = ceil(arr[i] / 2.0);

    return result;
}

void Process() {
    int result = 0;

    for (int i = n; i >= 1; i = i / 2) {
        int temp = Calc(i);

        if (temp == -1) {cout << "-1\n"; return;}

        result += temp;
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
