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

const int MAXN = 2e5 + 10, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

struct SEG {
        struct Node {
                int sum;
                bool is_null;

                Node() : sum(0), is_null(true) {}
                Node(int val) : sum(val), is_null(false) {}

                Node operator+(const Node& b) const {
                        if (is_null) return b;
                        if (b.is_null) return *this;
                        return Node(sum + b.sum);
                }
        };

        int n;
        vector<Node> tree;

        SEG(int n) : n(n), tree(4 * n + 5) {}
        
        SEG(const vi& v) {
                bool is_one = (sz(v) > 1 && v[0] == 0);
                n = is_one ? sz(v) - 1 : sz(v);
                tree.resize(4 * n + 5);
                build(1, 1, n, v, is_one);
        }

        void build(int u, int l, int r, const vi& v, bool is_one) {
                if (l == r) { 
                        tree[u] = Node(is_one ? v[l] : v[l - 1]); 
                        return; 
                }
                int m = (l + r) >> 1;
                build(2 * u, l, m, v, is_one);
                build(2 * u + 1, m + 1, r, v, is_one);
                tree[u] = tree[2 * u] + tree[2 * u + 1];
        }

        void update(int u, int l, int r, int id, int val) {
                if (l == r) { tree[u] = Node(val); return; }
                int m = (l + r) >> 1;
                if (id <= m) update(2 * u, l, m, id, val);
                else update(2 * u + 1, m + 1, r, id, val);
                tree[u] = tree[2 * u] + tree[2 * u + 1];
        }

        Node query(int u, int l, int r, int ql, int qr) {
                if (ql > r || qr < l) return Node();
                if (ql <= l && r <= qr) return tree[u];
                int m = (l + r) >> 1;
                return query(2 * u, l, m, ql, qr) + query(2 * u + 1, m + 1, r, ql, qr);
        }

        // Walk 1: Menor índice i in [ql, qr] tal que soma acumulada no range >= target
        int lower_bound(int u, int l, int r, int ql, int qr, int& target) {
                if (ql > r || qr < l || tree[u].sum < target) {
                        if (!(ql > r || qr < l)) target -= tree[u].sum; // Desconta o bloco explorado
                        return -1;
                }
                if (l == r) return l;

                int m = (l + r) >> 1;
                int left_res = lower_bound(2 * u, l, m, ql, qr, target);
                if (left_res != -1) return left_res;
                return lower_bound(2 * u + 1, m + 1, r, ql, qr, target);
        }

        // Walk 2: Menor índice i in [ql, qr] tal que soma acumulada no range > target
        int upper_bound(int u, int l, int r, int ql, int qr, int& target) {
                if (ql > r || qr < l || tree[u].sum <= target) {
                        if (!(ql > r || qr < l)) target -= tree[u].sum;
                        return -1;
                }
                if (l == r) return l;

                int m = (l + r) >> 1;
                int left_res = upper_bound(2 * u, l, m, ql, qr, target);
                if (left_res != -1) return left_res;
                return upper_bound(2 * u + 1, m + 1, r, ql, qr, target);
        }

        // Chamadas públicas (1-indexed)
        void update(int id, int val) { update(1, 1, n, id, val); }
        Node query(int l, int r) { return query(1, 1, n, l, r); }
        
        // Retorna o 1º índice em [ql, qr] cuja soma acumulada dentro de [ql, qr] é >= k
        int lower_bound(int ql, int qr, int k) {
                int target = k;
                return lower_bound(1, 1, n, ql, qr, target);
        }

        // Retorna o 1º índice em [ql, qr] cuja soma acumulada dentro de [ql, qr] é > k
        int upper_bound(int ql, int qr, int k) {
                int target = k;
                return upper_bound(1, 1, n, ql, qr, target);
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
