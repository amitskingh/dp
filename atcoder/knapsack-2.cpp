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

    int n, w; cin >> n >> w;
    vector<int> val(n + 1), wt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> wt[i] >> val[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(1e6 + 1, 1e15));
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 1e6; j++) {
            if (j >= val[i] && dp[i - 1][j - val[i]] + wt[i] <= w) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - val[i]] + wt[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }

        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= 17; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // bug(dp[6][15]);

    int res = 0;
    for (int i = 0; i <= 1e6; i++) {
        if (dp[n][i] != 1e15) {
            res = i;
        }
    }


    cout << res << "\n";
}

signed main() {
    PreProcess;

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int test = 1;
    // cin >> test;
    for (int t = 1; t <= test; t++) {
        solve();
    }

    return 0;
}