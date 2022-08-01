#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 77 * 17;


int n, x;  vector<int> arr;

void Input() {
    cin >> n >> x;

    arr.assign(n + 1, 0);  for (int i = 1; i <= n; i++) cin >> arr[i];
}


int Calc(int& v, int i) {
    set<int> s;

    for (int j = i; j <= n; j++) {
        s.insert(arr[i]);

        int sMin = *s.begin(), sMax = *s.rbegin();

        if (sMin < x && x < sMax) {
            if (sMax - sMin <= 2 * x) v = (sMax + sMin) / 2;
            else return j;
        } else {
            if (sMax - sMin <= x) v = (sMax + sMin) / 2;
            else return j;
        }
    }

    return n + 1;
}

void Process() {
    int result = 0, v = 0;

    Calc(v, 1);

    for (int i = 1; i <= n; i++) if (abs(v - arr[i]) > x) {
        i = Calc(v, i);

        result++;
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

