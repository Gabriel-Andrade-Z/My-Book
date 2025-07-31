// Brea-First Seach (BFS)
// Complexity: <O(E + V),O(V)>
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

void solve() {
	int n, m; cin >> n >> m;
	vector<bool> vis(n + 1,0);
	vector<vector<int>> graph(n + 1);
	f (i,0,m) {
		int u, v; cin >> u >> v;
		graph[u].eb(v); graph[v].eb(u);
	}
	queue<int> q;
	q.push(1); vis[1] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fa (v,graph[u]) {
			if (!vis[v]) vis[v] = 1, q.push(v);
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
