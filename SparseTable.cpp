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

using ii = pair<int,int>;
using iii = array<int,3>;

const int MAXN = 2e5 + 10, LOG = 20, MOD = 1e9 + 7, MODW = 998244353, oo = 1ll << 60;

const ld pi = acos(-1.0);

int arr[MAXN];

struct Node {
    int x;
    Node(int val = oo) : x(val) {};
    Node operator+(const Node b) { return {min(x,b.x)}; }
};

struct SparseTable {
    int n, k;
    vector<vector<Node>> st;
    void build(int _n) {
        n = _n; k = __lg(n) + 1;
        st.assign(k,vector<Node>(n + 1));
        f (i,1,n + 1) st[0][i] = arr[i];
        f (j,1,k) {
            f (i,1,n - (1 << j) + 2) {
                st[j][i] = st[j - 1][i] + st[j - 1][i + (1 << (j - 1))];
            }
        }
    }
    Node query(int l, int r) {
        if (l > r) return {oo};
        int j = __lg(r - l + 1);
        return st[j][l] + st[j][r - (1 << j) + 1];
    }
} st;

void solve() {
    int n, q; cin >> n >> q;
    f (i,1,n + 1) cin >> arr[i];
    st.build(n);
    while (q--) {
        int l, r; cin >> l >> r;
        cout << st.query(l,r).x << '\n';
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

