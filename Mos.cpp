// Mo's Algorithm (base application)
// Complexity: <O(n⋅√n),O(n)>
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

const int MAXN = 1e5 + 10;

int n, q, k, block, cnt = 0;
int arr[MAXN], freq[MAXN], ans[MAXN]; // ai ≤ 10⁵

struct Query {
	int l, r, pos, block;
	bool operator<(const Query& b) const {
		if (block != b.block) return block < b.block;
		return (block & 1) ? r < b.r : r > b.r;
	}
};

void add(int i) {
	int x = arr[i];
	if (x < k && freq[x] == 0) ++cnt;
	++freq[x];
}

void rem(int i) {
	int x = arr[i];
	--freq[x];
	if (x < k && freq[x] == 0) --cnt;
}

void solve() {
	cin >> n >> q >> k;
	f (i,0,n) cin >> arr[i];
	block = floor(sqrt(n));
	vector<Query> qrys;
	f (i,0,q) {
		int l, r; cin >> l >> r; --l, --r;
		qrys.pb({l,r,i,l/block});
	}
	sort(all(qrys));
	int l = 0, r = -1;
	for (auto q : qrys) {
		while (r < q.r) add(++r);
		while (l > q.l) add(--l);
		while (l < q.l) rem(l++);
		while (r > q.r) rem(r--);
		ans[q.pos] = cnt;
	}
	f (i,0,q) cout << ans[i] << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
