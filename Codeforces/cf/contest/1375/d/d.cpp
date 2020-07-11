// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

string to_string(string s) {
    return '"' + s + '"';
}
string to_string(char ch) {
    string s(1, ch);
    return '\'' + s + '\'';
}
string to_string(const char *s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#define f(i, x, n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

int mex(vll a) {
    vll count(a.size() + 1);
    for (auto el : a) count[el]++;

    for (int i = 0; i < count.size(); i++) {
        if (!count[i]) return i;
    }
    return a.size();
}

int32_t main() {
    fast_io();

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll a(n); f (i, 0, n) cin >> a[i];
        vll ans;
        // debug(a);

        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (m[a[i]]) {
                a[i] = mex(a);
                // cout << i+1 << " ";
                ans.pb(i+1);
            }
            m[a[i]] = 1;
        }
        f (i, 0, n) {
            if (a[i] == n) {
                // cout << i+1 << " ";
                ans.pb(i+1);
                a[i] = mex(a);
            }
        }

        debug(a);

        vll vis(a.size());

        for (int i = n-1; i >= 0; i--) {
            if (vis[i]) continue;
            int pos = i;
            while(!vis[pos]) {
                // cout << pos+1 << " ";
                ans.pb(pos+1);
                vis[pos] = 1;
                pos = a[pos] % a.size();
            }
        }

        cout << ans.size() << endl;
        for (auto el : ans) cout << el << " ";
        cout << endl;
    }

    return 0;
}
