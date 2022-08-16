#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n;  vector<int> arr;

void Input() {
    cin >> n;  arr.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) cin >> arr[i];
}


void Process() {
    int result = 0;

    for (int k = 0; k <= 30; k++) {
        vector<int> s;

        for (int i = 1; i <= n; i++) s.push_back(arr[i] & (1 << k));

        int cnt = s[0] != 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == 0) result += ceil(cnt / 2.0), cnt = 0;
            else {
                if (s[i - 1] == s[i]) cnt++;
                else {
                    result += ceil(cnt / 2.0);

                    cnt = 1;
                }
            }
        }

        result += ceil(cnt / 2.0);
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
