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

struct Dinic {
        struct Edge { 
                int to, cap, rev; // Nó destino, capacidade residual, índice da aresta reversa
        };
    
        int n;
        vector<vector<Edge>> adj;
        vector<int> level, ptr;
    
        // Construtor: Inicializa n vértices (seguro para 0-indexado e 1-indexado)
        Dinic(int _n) : n(_n), adj(_n + 1), level(_n + 1), ptr(_n + 1) {}
    
        // Adiciona uma aresta direcionada de 'u' para 'v' com capacidade 'cap'
        void add_edge(int u, int v, int cap, bool bidir = false) {
                adj[u].push_back({v, cap, (int)adj[v].size()});
                adj[v].push_back({u, bidir ? cap : 0, (int)adj[u].size() - 1});
        }
    
        // BFS: Constrói o grafo de níveis
        bool bfs(int s, int t) {
                fill(all(level), -1);
                level[s] = 0;
                queue<int> q;
                q.push(s);            
                while (!q.empty()) {
                        int u = q.front(); 
                        q.pop();
                        f(i, 0, sz(adj[u])) {
                                auto& e = adj[u][i];
                                // Se a aresta tem capacidade e o nó vizinho não foi visitado
                                if (e.cap > 0 && level[e.to] == -1) {
                                        level[e.to] = level[u] + 1;
                                        q.push(e.to);
                                }
                        }
                }
                return level[t] != -1; // Retorna true se alcançou o Sink
        }
    
        // DFS: Encontra caminhos aumentantes usando o grafo de níveis
        int dfs(int u, int t, int pushed) {
                if (pushed == 0 || u == t) return pushed;       
                // ptr[u] guarda a última aresta processada para evitar refazer trabalho (dead-end optimization)
                for (int& cid = ptr[u]; cid < sz(adj[u]); ++cid) {
                        auto& e = adj[u][cid];
                        int tr = e.to;
                        // Só avança se estiver indo para o próximo nível e houver capacidade
                        if (level[u] + 1 != level[tr] || e.cap == 0) continue;
                        int push = dfs(tr, t, min(pushed, e.cap));
                        if (push == 0) continue;
                        e.cap -= push;             // Aresta de ida perde capacidade
                        adj[tr][e.rev].cap += push; // Aresta de volta ganha capacidade
                        return push;
                }
                return 0;
        }
        // Retorna o fluxo máximo de 's' (Source) para 't' (Sink)
        int max_flow(int s, int t) {
                int flow = 0;
                // Enquanto houver caminho de s para t no grafo de níveis
                while (bfs(s, t)) {
                        fill(all(ptr), 0); // Reseta os ponteiros da DFS para a nova fase
                        while (int pushed = dfs(s, t, oo)) {
                                flow += pushed;
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
	int tc = 1;
	if (all_test) cin >> tc;
	while (tc--) solve();
	return 0;
}
