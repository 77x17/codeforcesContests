#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;

void Input() {
    cin >> n;
}


int calc[] = {0, 2, 1, 1, 2, 2};

void Process() {
    int result = min(n / 3 + calc[n % 3], n / 2 + calc[n % 2]);

    if (n / 3 && n % 3) result = min(result, n / 3 - 1 + calc[3 + n % 3]);

    if (n / 2 && n % 2) result = min(result, n / 2 - 1 + calc[2 + n % 2]);

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
