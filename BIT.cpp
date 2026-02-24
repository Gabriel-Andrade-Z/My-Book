// Fenwick Tree (BIT) - (based 1)
// Complexity: <O(n⋅log(n)),O(n)>
// Build: O(n⋅log(n)), Query: O(log(n))
// by: Gabeee

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

const int MAXN = 2e5 + 1, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

int arr[MAXN];
 
struct Node {
    int x;
    Node(int val = 0) : x(val) {} 
 
    Node operator+(const Node b) const { return {x + b.x}; }
    Node operator-(const Node b) const { return {x - b.x}; }
};
 
struct BIT {
    int n; vector<Node> bit;
    BIT(int _n = 0) { init(_n); }

    void init(int _n) {
        n = _n;
        bit.assign(n + 1, Node()); 
    }
 
    void update(int i, Node v) {
        while (i <= n) { bit[i] = bit[i] + v; i += i & -i; }
    }
 
    Node query(int i) {
        Node s = Node(); 
        while (i > 0) { 
            s = s + bit[i]; 
            i -= i & -i; 
        }
        return s;
    }
    Node query(int l, int r) { return query(r) - query(l - 1); }
};
 
void solve() {
    int n, q; cin >> n >> q;
    f (i,1,n + 1) cin >> arr[i];
    BIT bit(n);
    f (i,1,n + 1) bit.update(i,Node(arr[i]));
    while (q--) {
        int op, l, r; cin >> op >> l >> r;
        if (op == 1) {
            bit.update(l,Node(r - arr[l]));
            arr[l] = r; // sempre lembrar (BIT SOMA) (se for fzr update, lembra de mudar).
        } else cout << bit.query(l,r).x << '\n';
    }
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int tc = 1;
	if (all_test) cin >> tc;
	while (tc--) solve();
	return 0;
}

