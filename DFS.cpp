// Depth-First Seach (DFS)
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

int n, m;
vector<bool> vis;
vector<vector<int>> graph;

void dfs(int u) {
	vis[u] = true;
	for (auto v : graph[u]) {
		if (!vis[v]) dfs(v);
	}
}

void solve() {
	cin >> n >> m;
	vis = vector<bool>(n + 1,0);
	graph = vector<vector<int>>(n + 1);
	f (i,0,m) {
		int u, v; cin >> u >> v;
		graph[u].eb(v); graph[v].eb(u);
	}
	dfs(1);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
