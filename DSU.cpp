// Disjoint Set Union (DSU)
// Complexity: <O(α(n)), O(α(n))>
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

const int MAXN = 1e5 + 1, MOD = 1e9 + 7, MODW = 998244353, inf = LLONG_MAX;

int id[MAXN], sz[MAXN];

int find(int x) {
	return id[x] = (id[x] == x ? x : find(id[x]));
}

void uni(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return;
	if (sz[x] > sz[y]) swap(x,y);
	id[x] = y;
	sz[y] += sz[x];
}

void solve() {
	f (i,0,MAXN) id[i] = i, sz[i] = 1;
	int n, m; cin >> n >> m;
	f (i,0,m) {
		int u, v; cin >> u >> v;
		uni(u,v);
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
