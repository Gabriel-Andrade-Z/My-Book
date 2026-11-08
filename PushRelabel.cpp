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

// Push-Relabel otimizado com Highest Label e Gap Heuristic
// Complexidade de tempo: O(V^2 * sqrt(E))
struct PushRelabel {
        struct Edge {
                int dest, back;
                int f, c;
        };
        int n;
        vector<vector<Edge>> g;
        vector<int> ec;  // excesso de fluxo (excess)
        vector<int> ptr; // ponteiro da aresta atual
        vector<vector<int>> hs; // buckets de n´ós ativos separados por altura
        vector<int> H;   // altura (height)

        PushRelabel(int n) : n(n), g(n), ec(n), ptr(n), hs(2 * n), H(n) {}

        void add_edge(int s, int t, int cap, int rcap = 0) {
                if (s == t) return;
                g[s].pb({t, sz(g[t]), 0, cap});
                g[t].pb({s, sz(g[s]) - 1, 0, rcap});
        }

        void add_flow(int u, int idx, int f) {
                Edge &e = g[u][idx];
                Edge &back = g[e.dest][e.back];
                // Se o vizinho não tinha excesso e é adicionado fluxo, ele se torna ativo
                if (!ec[e.dest] && f) hs[H[e.dest]].pb(e.dest);
                e.f += f; e.c -= f; ec[e.dest] += f;
                back.f -= f; back.c += f; ec[u] -= f;
        }

        int flow(int s, int t) {
                H[s] = n; 
                ec[t] = 1; // Protege o sumidouro de ir para a fila de ativos
                vector<int> co(2 * n); 
                co[0] = n - 1;
                f (i, 0, n) ptr[i] = 0;
                f (i, 0, sz(g[s])) add_flow(s, i, g[s][i].c); // Satura saída da fonte

                for (int hi = 0;;) {
                        while (hs[hi].empty()) {
                                if (!hi--) return -ec[s]; // Retorna max flow = -excesso na fonte
                        }
                        int u = hs[hi].back(); 
                        hs[hi].pop_back();
                        while (ec[u] > 0) { // Descarrega (discharge) u
                                if (ptr[u] == sz(g[u])) {
                                        H[u] = 1e9; 
                                        f (i, 0, sz(g[u])) {
                                                auto &e = g[u][i];
                                                if (e.c && H[u] > H[e.dest] + 1) {
                                                        H[u] = H[e.dest] + 1;
                                                        ptr[u] = i;
                                                }
                                        }
                                        // Gap Heuristic: Se um nível ficar vazio, desconecta a parte superior
                                        if (++co[H[u]], !--co[hi] && hi < n) {
                                                f (i, 0, n) {
                                                        if (hi < H[i] && H[i] < n) {
                                                                --co[H[i]]; H[i] = n + 1;
                                                        }
                                                }
                                        }
                                        hi = H[u];
                                } else {
                                        auto &e = g[u][ptr[u]];
                                        if (e.c && H[u] == H[e.dest] + 1) {
                                                add_flow(u, ptr[u], min(ec[u], e.c));
                                        } else {
                                                ++ptr[u];
                                        }
                                }
                        }
                }
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
