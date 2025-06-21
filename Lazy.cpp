// Segment Tree whit Lazy Propagation
// Complexity: <O(n⋅log(n)),O(n)>
// Build: O(n⋅log(n)), Query: O(log(n))
// by: Gabeee, thanks: Jao
 
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
 
const int MAXN = 2e5 + 10, inf = LLONG_MAX;

int arr[MAXN], calls = 0;
 
struct Node {
	int x;
	Node(int val = 0) : x(val) {}
	Node operator+(const Node b) const { return {x + b.x}; }
};
 
struct SEG {
	Node seg[4*MAXN];
	int lazy[4*MAXN] = {};
	
	void push(int u, int l, int r) {
		if (lazy[u] == 0) return;
		int len = r - l + 1;
		seg[u].x += lazy[u] * len;
		if (l != r) {
			lazy[2*u] += lazy[u];
			lazy[2*u + 1] += lazy[u];
		}
		lazy[u] = 0;
	}
	
	void build(int u, int l, int r) {
		++calls;
		if (l == r) { seg[u] = {arr[l]}; return; }
		int m = (r + l) >> 1ll;
		build(2*u,l,m), build(2*u+1,m+1,r);
		seg[u] = seg[2*u] + seg[2*u+1];
	}
	
	void range_update(int u, int l, int r, int i, int j, int x) {
		push(u,l,r);
		if (r < i || l > j) return;
		if (i <= l && r <= j) {
			lazy[u] += x;
			push(u,l,r);
			return;
		}
		int m = (r + l) >> 1ll;
		range_update(2*u,l,m,i,j,x);
		range_update(2*u+1,m+1,r,i,j,x);
		seg[u] = seg[2*u] + seg[2*u+1];
	}
	
	Node query(int u, int l, int r, int i, int j) {
		push(u,l,r);
		if (l > r || l > j || r < i) return {0};
		if (l >= i && r <= j) return seg[u];
		int m = (r + l) >> 1ll;
		return query(2*u,l,m,i,j) + query(2*u+1,m+1,r,i,j);
	}
} seg;
 
void solve() {
	int n, q = 0; cin >> n;
	f (i,1,n + 1) cin >> arr[i];
	seg.build(1,1,n); // range [1,n]
	while (q--) {
		int op; cin >> op;
		if (op == 1) {
			int a, b, u; cin >> a >> b >> u;
			seg.range_update(1,1,n,a,b,u);
		} else {
			int k; cin >> k;
			cout << seg.query(1,1,n,k,k).x << '\n';
		}
	}
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
