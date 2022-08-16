#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, m;

void Input() {
    cin >> n >> m;
}


void Process() {
    if ((n % 2 + m % 2) % 2) cout << "Burenka\n"; else cout << "Tonya\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
