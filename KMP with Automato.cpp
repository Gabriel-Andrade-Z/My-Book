// KMP with Automato
// Complexity: <O(n + Σ⋅m),O(Σ⋅m)>
// Build: O(Σ⋅m), Query: O(1)
// by: Gabeee, thanks: bruno

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
 
struct autKMP {
	vector<vector<int>> nxt;
	autKMP(string &pat) : nxt(26,vector<int>(sz(pat) + 1)) {
		int m = sz(pat);
		vector<int> lps(m + 1); construct_lps(pat + '$',lps);
		nxt[pat[0] - 'a'][0] = 1;
		f (ch,0,26) {
			f (i,1,m + 1) {
				nxt[ch][i] = ch == pat[i] - 'a' ? i + 1 : nxt[ch][lps[i - 1]];	
			}
		}
	}
};

// permite quadrático...
/*
struct autKMP {
        vector<vector<int>> nxt;
        vector<int> lps;
        autKMP(const string &pat) : nxt(26,vector<int>(sz(pat) + 1,0)) {
                int m = sz(pat);
                construct_lps(pat,lps);
                for (int i = 0;i <= m;++i) {
                        for (int ch = 0;ch < 26;++ch) {
                                int j = i;
                                while (j > 0 && (j == m || pat[j] != char('a' + ch))) j = lps[j - 1];
                                if (j < m && pat[j] == char('a' + ch)) ++j;
                                nxt[ch][i] = j;
                        }
                }
        }
};
*/

vector<int> kmp(const string &pat, const string &txt) {
        autKMP aut(pat);
        int n = sz(txt), m = sz(pat), at = 0;
        vector<int> res;
        for (int i = 0;i < n;++i) {
                at = aut.nxt[txt[i] - 'a'][at];
                if (at == m) {
                        res.pb(i - m + 1);
                        at = (m ? aut.lps[m - 1] : 0);
                }
        }
        return res;
}

void solve() {
        string pat, txt; cin >> pat >> txt;
        vector<int> res = kmp(pat, txt);
        fa(x,res) cout << x << ' ';
        cout << '\n';
}

signed main() {
        ios::sync_with_stdio(0);
        cin.tie(nullptr);
        int t = 1; if (all_test) cin >> t;
        while (t--) solve();
        return 0;
}
