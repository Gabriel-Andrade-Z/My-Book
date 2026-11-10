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
#define sz(x) (int)(x).size()
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

const int MAXN = 1e5 + 10, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

struct EdmondsKarp {
        struct Edge { 
                int to, cap, rev; // Nó destino, capacidade residual, índice da aresta reversa
        };
    
        int n;
        vector<vector<Edge>> adj;
    
        // Construtor: Inicializa n vértices (seguro para 0-indexado e 1-indexado)
        EdmondsKarp(int _n) : n(_n), adj(_n + 1) {}
    
        // Adiciona uma aresta direcionada de 'u' para 'v' com capacidade 'cap'
        void add_edge(int u, int v, int cap, bool bidir = false) {
                adj[u].push_back({v, cap, (int)adj[v].size()});
                adj[v].push_back({u, bidir ? cap : 0, (int)adj[u].size() - 1});
        }
    
        // Retorna o fluxo máximo de 's' (Source) para 't' (Sink)
        int max_flow(int s, int t) {
                int flow = 0;
                vector<pair<int, int>> p(n + 1); // Guarda {nó pai, índice da aresta no pai}
                while (true) {
                        fill(all(p), make_pair(-1, -1));
                        queue<pair<int, int>> q;
                        q.push({s, oo});
                        p[s] = {-2, -2};
                        int pushed = 0;
                        while (!q.empty() && !pushed) {
                                auto [u, f] = q.front(); q.pop();
                                f(i, 0, sz(adj[u])) {
                                	auto& e = adj[u][i];
                                	// Se o nó não foi visitado e a aresta tem capacidade residual
                                	if (p[e.to].fi == -1 && e.cap > 0) {
	                                        p[e.to] = {u, i};
        	                                int new_f = min(f, e.cap);
                                        	if (e.to == t) { pushed = new_f; break; }
                                        	q.push({e.to, new_f});
                                	}
                                }
                        }
                        // Se não encontramos mais nenhum caminho aumentante, acabou o fluxo
                        if (!pushed) break;
                        flow += pushed;
                        // Backtracking: atualiza as capacidades ao longo do caminho encontrado
                        for (int v = t; v != s; v = p[v].fi) {
                                int u = p[v].fi, idx = p[v].se;
                                int rev_idx = adj[u][idx].rev;
                                adj[u][idx].cap -= pushed;         // Aresta de ida perde capacidade
                                adj[v][rev_idx].cap += pushed;     // Aresta de volta (reversa) ganha capacidade
                        }
                }
                return flow;
        }
};
void solve() {
	
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int tt = 1; if (all_test) cin >> tt;
	while (t--) solve();
	return 0;
}
