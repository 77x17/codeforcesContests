#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;

void Input() {
    cin >> n;
}


int arr[MAX_N];

void Process() {
    cout << n << '\n';

    for (int i = 1; i <= n; i++) arr[i] = i;

    for (int i = 1; i <= n; i++) {
        swap(arr[1], arr[i]);

        for (int j = 1; j <= n; j++) cout << arr[j] << " \n"[j == n];
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

