#include <bits/stdc++.h>

using namespace std;


int n, m;  vector<int> arr;

void Input() {
    cin >> n >> m;  arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    set<int> s;

    for (int i = 1; i <= n; i++) {
        int a = min(arr[i], m + 1 - arr[i]);

        int b = max(arr[i], m + 1 - arr[i]);

        if (a == b) {
            s.insert(a);
        } else {
            if (s.find(a) == s.end()) s.insert(a);
            else s.insert(b);
        }
    }

    string result;  while (m--) result.push_back('B');

    for (auto e : s) result[e - 1] = 'A';

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
