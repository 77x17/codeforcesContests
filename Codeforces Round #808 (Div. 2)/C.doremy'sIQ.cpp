#include <bits/stdc++.h>

using namespace std;


int n, q;  vector<int> arr;

void Input() {
    cin >> n >> q;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


string result;

void Process() {
    int iq = 0; result.assign(n, '0');

    for (int i = n; i >= 1; i--) {
        if (arr[i] > iq) {if (iq < q) iq++, result[i - 1] = '1';}
        else result[i - 1] = '1';
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
