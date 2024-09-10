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
    vector<int> a(n + 1), dp(n + 1, INT_MAX);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    dp[0] = dp[1] = 0;
    a[0] = INT_MAX;

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i - 2] + abs(a[i] - a[i - 2]), dp[i - 1] + abs(a[i] - a[i - 1]));
    }

    cout << dp[n] << "\n";

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