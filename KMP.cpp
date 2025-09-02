// Knuth-Morris-Pratt (KMP) String Matching
// Complexity: O(n + m)
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

void construct_lps(string &pat, vector<int> &lps) {
        int len = 0, i = 1; lps[0] = 0;
        while (i < sz(pat)) {
                if (pat[i] == pat[len]) {
                        len++;
                        lps[i] = len;
                        i++;
                } else {
                        if (len != 0) len = lps[len - 1];
                        else {
                                lps[i] = 0;
                                i++;
                        }
                }
        }
}

vector<int> kmp(string &pat, string &txt) {
        int n = sz(txt), m = sz(pat);
        vector<int> lps(m), res;
        construct_lps(pat, lps);
        int i = 0, j = 0;
        while (i < n) {
                if (txt[i] == pat[j]) {
                        i++; j++;
                        if (j == m) {
                                res.pb(i - j);
                                j = lps[j - 1];
                        }
                } else {
                        if (j != 0) j = lps[j - 1];
                        else i++;
                }
        }
        return res;
}

void solve() {
        string txt, pat; cin >> txt >> pat;
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
