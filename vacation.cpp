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

#define int long long
// #define double long double

// const int mod = 1e9 + 7;
// const int mod = 998244353;

void solve() {

    int n; cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i - 1];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i - 1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i - 1];
    }

    int res = max({ dp[n][0], dp[n][1], dp[n][2] });

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