#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int arr[2][2];

void Input() {
    cin >> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];
}


void Process() {
    cout << ceil((arr[0][0] + arr[0][1] + arr[1][0] + arr[1][1]) / 3.0) << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
