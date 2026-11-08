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

struct DSU {
        vector<int> p, tam; // 'p' guarda os pais, 'tam' guarda o tamanho do componente
        int comps;          // Quantidade de componentes conexos atuais

        // Construtor: Inicializa N elementos (suporta 0-indexado e 1-indexado)
        DSU(int n) {
                p.assign(n + 1, 0);
                iota(p.begin(), p.end(), 0); // Cada nó é pai de si mesmo inicialmente
                tam.assign(n + 1, 1);        // Todo componente começa com tamanho 1
                comps = n;
        }

        // Find com Path Compression: Encontra a raiz e achata a árvore
        int id(int u) { return (p[u] == u ? u : p[u] = id(p[u])); }

        // Verifica se U e V estão no mesmo componente
        bool same(int u, int v) { return id(u) == id(v); }
    
        // Union by Size: Une os componentes de U e V.
        // Retorna true se houve união, false se já eram do mesmo componente (formariam um ciclo).
        bool join(int u, int v) {
                int U = id(u), V = id(v);
                if(U == V) return false;
                
                // Queremos sempre anexar a árvore menor na raiz da maior para manter a profundidade log(N)
                if(tam[U] < tam[V]) swap(U, V);
        
                p[V] = U;             // V passa a apontar para U
                tam[U] += tam[V];     // Atualiza o tamanho do novo componente raiz
                --comps;              // Diminui a quantidade total de componentes isolados
        
                return true;
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
