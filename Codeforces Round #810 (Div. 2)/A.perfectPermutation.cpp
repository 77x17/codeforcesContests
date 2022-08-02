#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;

void Input() {
    cin >> n;
}


void Process() {
    for (int i = 2; i <= n; i++) cout << i << ' '; cout << 1 << '\n';
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
