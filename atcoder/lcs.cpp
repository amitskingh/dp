/* Radhe Radhe */

#include <bits/stdc++.h>
using namespace std;

#define PreProcess ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) (int) v.size()
#define init(arr, val) memset(arr, val, size(arr))  
#define bits(n) __builtin_popcount(n)
#define desc greater<int>
#define in(arr, n) for(int _ = 0; _ < n; _++) cin >> arr[_]
#define inn(arr, e) for(int _ = 1; _ <= e; _++) cin >> arr[_]

// #define int long long
// #define double long double

// const int mod = 1e9 + 7;
// const int mod = 998244353;

void solve() {

    string s, t;
    cin >> s >> t;

    int n = size(s), m = size(t);

    s = "$" + s;
    t = "#" + t;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string res = "";
    auto getString = [&](auto self, int i, int j)->void {
        if (i == 0 || j == 0) {
            return;
        }
        if (dp[i][j] - 1 == dp[i - 1][j - 1] && s[i] == t[j]) {
            self(self, i - 1, j - 1);
            res += s[i];
        } else if (dp[i][j] == dp[i - 1][j]) {
            self(self, i - 1, j);
        } else {
            self(self, i, j - 1);
        }
        };

    getString(getString, n, m);
    // cout << dp[n][m] << "\n";
    cout << res << "\n";
}

signed main() {
    PreProcess;

    int test = 1;
    // cin >> test;
    for (int t = 1; t <= test; t++) {
        solve();
    }

    return 0;
}