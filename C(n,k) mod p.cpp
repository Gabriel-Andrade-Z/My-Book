// C(n,k) mod p (Lucas Theorem)
// Complexity: <O(p²⋅logₚ(n)),O(p²)>
// by: Gabeee

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define pb push_back
#define eb emplace_back
#define is insert
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define f(i,b,e) for (int i = (b);i < (e);++i)
#define rf(i,b,e) for (int i = (b);i >= (e);--i)
#define fa(i,a) for (auto i : (a))
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define mkp make_pair

#define debug(x) cerr << #x << " = " << (x) << endl;

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool all_test = 0;

const int MAXN = 1e5 + 1, MOD = 1e9 + 7, MODW = 998244353, inf = LLONG_MAX;

int C(int n, int k, int p) {
        if (k > n) return 0;
        if (n == 0 || k == 0) return 1;
        int dp[n + 1]; 
        memset(dp,0,sizeof(dp)); dp[0] = 1;
        f (i,1,n + 1) {
                rf (j,min(i,k),0) {
                        dp[j] = (dp[j] + dp[j - 1]) % p;
                }
        }
        return dp[k];
}

int CmodP(int n, int k, int p) {
        if (k > n) return 0;
        if (k == 0 || n == 0) return 1;
        int ni = n % p, ki = k % p;
        return (CmodP(n / p,k / p,p)*C(ni,ki,p)) % p;
}

void solve() {
        int n, k, p; cin >> n >> k >> p;
        cout << CmodP(n,k,p) << '\n';
}

signed main() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int t = 1; if (all_test) cin >> t;
        while (t--) solve();
        return 0;
}
