// C(n,k) with dp
// Complexity: <O(n²),O(1)>
// Precompute: O(n²), Query: O(1)
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

const int MAXN = 3e3 + 1, MOD = 1e9 + 7, MODW = 998244353, inf = LLONG_MAX;

int dp[MAXN][MAXN];

void comp() {
	memset(dp,0,sizeof(dp));
	f (i,0,MAXN) {
		dp[i][0] = 1;
		f (j,1,i + 1) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
	}	
}

void solve() {
	comp();
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		cout << dp[n][k] << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
