// C(n,k)
// Complexity: <O(n),O(n)>
// Precompute: O(n), Query: O(1)
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

const int MAXN = 1e5 + 10, MOD = 1e9 + 7;

int fact[MAXN], invfact[MAXN];

int fpow(int b, int e) {
	int res = 1;
	b %= MOD;
	while (e > 0) {
		if (e & 1) res = res * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return res;
}

int modinv(int x) { return fpow(x,MOD - 2); }

void comp() {
	fact[0] = 1;
	f (i,1,MAXN) fact[i] = fact[i - 1] * i % MOD;
	invfact[MAXN - 1] = modinv(fact[MAXN - 1]);
	rf (i,MAXN - 2,0) invfact[i] = invfact[i + 1]*(i + 1) % MOD;
}

int C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return (fact[n] * invfact[k] % MOD) * invfact[n - k] % MOD;
}

void solve() {
	comp();
	int q; cin >> q;
	while (q--) {
		int n, k; cin >> n >> k;
		cout << C(n,k) << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
