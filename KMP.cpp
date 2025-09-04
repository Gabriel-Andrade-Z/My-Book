// Knuth-Morris-Pratt (KMP) String Matching
// Complexity: <O(n + m),O(m)>
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

void construct_lps(string pat, vector<int> &lps) {
        int j = 0, m = sz(lps); lps[0] = 0;
        f (i,1,m) {
		while (j > 0 && pat[j] != pat[i]) j = lps[j - 1];
		if (pat[j] == pat[i]) ++j;
		lps[i] = j;
	}
}

vector<int> kmp(string &pat, string &txt) {
        int j = 0, n = sz(txt), m = sz(pat);
        vector<int> lps(m), res;
        construct_lps(pat + '$', lps);
	f (i,0,n) {
		while (j > 0 && pat[j] != txt[i]) j = lps[j - 1];
		if (pat[j] == txt[i]) ++j;
		if (j == m) res.pb(i - j + 1);
	}
        return res;
}

void solve() {
        string txt, pat; cin >> pat >> txt;
        vector<int> res = kmp(pat, txt);
        fa(x,res) cout << x << ' '; cout << '\n';
}

signed main() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int t = 1; if (all_test) cin >> t;
        while (t--) solve();
        return 0;
}
