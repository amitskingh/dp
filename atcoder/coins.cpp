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
#define double long double

const int mod = 1e9 + 7;
// const int mod = 998244353;

const int N = 3000;
int n;
vector<double> p(N);
vector<vector<double>> dp(N, vector<double>(N, -1.0));


double find(int i, int h, int t) {
    if (i == n) {
        return 1.0;
    }

    double &ans = dp[h][t];
    if (dp[h][t] != -1.0) {
        return ans;
    }

    ans = 0;
    if (h) {
        ans += find(i + 1, h - 1, t) * p[i];
    }if (t) {
        ans += find(i + 1, h, t - 1) * (1.0 - p[i]);
    }

    return ans;
}


void solve() {
    cin >> n; in(p, n);

    cout << setprecision(10) << fixed;

    double ans = 0;
    for (int i = (n / 2 + 1); i <= n; i++) {
        ans += find(0, i, n - i);
    }

    cout << ans << "\n";
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