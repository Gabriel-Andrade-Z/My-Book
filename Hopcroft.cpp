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
#define unique(x) (x).erase(unique((x).begin(), (x).end()), (x).end())
#define f(i,b,e) for (int i = (b); i < (e); ++i)
#define rf(i,b,e) for (int i = (b); i >= (e); --i)
#define fa(i,a) for (auto& i : (a))
#define sz(x) ((int)(x).size())
#define fi first
#define se second
#define mkp make_pair

using namespace std;

using par = array<int,2>;
using ii = pair<int,int>;
using iii = array<int,3>;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef set<int> si;
typedef map<int,int> mii;

bool all_test = 0;

const int MAXN = 3e3 + 10, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

/*
 * Hopcroft-Karp (Maximum Bipartite Matching)
 * Complexidade: O(E * sqrt(V))
 * Nós da esquerda (L): 0 a L-1 | Nós da direita (R): 0 a R-1
 */
struct HopcroftKarp {
        int L, R;
        vvi adj;
        vi mtL, mtR, dist;

        HopcroftKarp(int L, int R) : L(L), R(R), adj(L), mtL(L, -1), mtR(R, -1), dist(L) {}

        void add_edge(int u, int v) {
                adj[u].pb(v);
        }

        bool bfs() {
                queue<int> q;
                f(u, 0, L) {
                        if (mtL[u] == -1) dist[u] = 0, q.push(u);
                        else dist[u] = oo;
                }
                int min_dist = oo;
                while (!q.empty()) {
                        int u = q.front(); q.pop();
                        if (dist[u] >= min_dist) continue;
                        fa(v, adj[u]) {
                                if (mtR[v] == -1) min_dist = dist[u] + 1;
                                else if (dist[mtR[v]] == oo) {
                                        dist[mtR[v]] = dist[u] + 1;
                                        q.push(mtR[v]);
                                }
                        }
                }
                return min_dist != oo;
        }

        bool dfs(int u) {
                fa(v, adj[u]) {
                        if (mtR[v] == -1 || (dist[mtR[v]] == dist[u] + 1 && dfs(mtR[v]))) {
                                mtL[u] = v;
                                mtR[v] = u;
                                return true;
                        }
                }
                dist[u] = oo;
                return false;
        }

        int max_matching() {
                int ans = 0;
                while (bfs()) {
                        f(u, 0, L) if (mtL[u] == -1 && dfs(u)) ans++;
                }
                return ans;
        }
};

void solve() {

}

signed main() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int tc = 1;
        if (all_test) cin >> tc;
        while (tc--) solve();
        return 0;
}
