#include <bits/stdc++.h>

using namespace std;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    for (int i = n - 1; i >= 1; i--) {
        int pre = arr[i + 1];

        for (int j = i; j >= 1; j--) {
            int temp = arr[j];  arr[j] = pre - arr[j];  pre = temp;

            if (pre == 0) {
                sort(arr.begin() + j, arr.begin() + i + 1);

                break;
            }
        }

        if (pre != 0) sort(arr.begin() + 1, arr.begin() + i + 1);
    }

    cout << arr[1] << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
