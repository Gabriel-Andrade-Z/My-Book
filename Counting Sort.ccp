// Counting Sort Algorithm
// Complexity: <O(n + k), O(k)>
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

const int MAXN = 1e5 + 1, MOD = 1e9 + 7, MODW = 998244353, inf = LLONG_MAX;

int arr[MAXN], cnt[MAXN];

void solve() {
	int n, idx = 0; cin >> n;
	f (i,0,n) { cin >> arr[i]; cnt[arr[i]]++; }
	f (i,0,MAXN) {
		while (cnt[i] > 0) {
			arr[idx++] = i; --cnt[i];
		}
	}
	f (i,0,n) cout << arr[i] << ' '; cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t = 1; if (all_test) cin >> t;
	while (t--) solve();
	return 0;
}
