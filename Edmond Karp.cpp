// Edmond Karp (Flow)
// Complexity: <O(V⋅E²),O(V²)>
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

const int inf = LLONG_MAX, MAXN = 101;

int n, m, s, t;
int cap[MAXN][MAXN];
vector<int> graph[MAXN];

int bfs(vector<int>& parent) {
	parent = vector<int>(n + 1,-1);
	parent[s] = -2;
	queue<pair<int,int>> q;
	q.push({s,inf});
	while (!q.empty()) {
		int u = q.front().fi, flow = q.front().se;
		q.pop();
		for (int v : graph[u]) {
			if (parent[v] == -1 && cap[u][v] > 0) {
				parent[v] = u;
				int new_flow = min(flow,cap[u][v]);
				if (v == t) return new_flow;
				q.push({v,new_flow});
			}
		}
	}
	return 0;
}

int edmonds_karp() {
	int flow = 0, new_flow;
	vector<int> parent;
	while ((new_flow = bfs(parent)) != 0) {
		flow += new_flow;
		int v = t;
		while (v != s) {
			int u = parent[v];
			cap[u][v] -= new_flow;
			cap[v][u] += new_flow;
			v = u;
		}
	}
	return flow;
}

void solve() {
	cin >> n >> m >> s >> t;
	memset(cap,0,sizeof(cap));
	f (i,1,MAXN) graph[i].clear();
	f (i,0,m) {
		int u, v, c; cin >> u >> v >> c;
		cap[u][v] += c; cap[v][u] += c;
		graph[u].eb(v); graph[v].eb(u);
	}
	int max_flow = edmonds_karp();
	cout << max_flow << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
