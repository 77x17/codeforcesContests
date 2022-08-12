#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}


vector<int> pre, suf, a, b;

void Process() {
    int spe;

    for (int i = 1; i <= n; i++) spe = max(spe, arr[i]);

    pre.clear();  suf.clear();

    for (int i = 1; i <= n; i++) {
        if (arr[i] != spe) pre.push_back(arr[i]);
        else {
            for (int j = i + 1; j <= n; j++) suf.push_back(arr[j]);

            break;
        }
    }

    a = pre;  sort(a.begin(), a.end());

    b = suf;  sort(b.begin(), b.end(), greater<int>());

    if (a == pre && b == suf) cout << "YES\n"; else cout << "NO\n";
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t; while (t--) {
        Input();

        Process();
    }

    return 0;
}
