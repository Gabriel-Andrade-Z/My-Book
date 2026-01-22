// Fenwick Tree (BIT) - (based 1)
// Complexity: <O(n⋅log(n)),O(n)>
// Build: O(n⋅log(n)), Query: O(log(n))
// by: Gabeee

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ld long double
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

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

struct BIT {
	int n;
	vector<int> bit;

	BIT(int _n=0) { init(_n); }

	void init(int _n) {
		n = _n;
		bit.assign(n + 1, 0);
	}

	void update(int i, int v) {
		while (i <= n) { bit[i] += v; i += i & -i;
		}
	}

	int query(int i) {
		int s = 0;
		while (i > 0) { s += bit[i]; i -= i & -i; }
		return s;
	}

	int query(int l, int r) { return query(r) - query(l - 1); }

	int upper_bound(int x) {
		int p = 0;
		rf (i, __lg(n), 0)
			if (p + (1 << i) <= n && bit[p + (1 << i)] <= x) 
				x -= bit[p += (1 << i)];
		return p;
	}
};

int arr[MAXN];

void solve() {
	int n, q; cin >> n >> q;

	f(i,1,n + 1) cin >> arr[i];

	BIT bit(n);
	f(i,1,n + 1) bit.update(i, arr[i]);

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int i, v; cin >> i >> v;
			bit.update(i, v);
		} else {
			int l, r; cin >> l >> r;
			cout << bit.query(l, r) << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int tc = 1;
	if (all_test) cin >> tc;
	while (tc--) solve();
	return 0;
}

