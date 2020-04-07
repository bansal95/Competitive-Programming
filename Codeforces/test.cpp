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
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

const ll mod = 1e9 + 7;
const ll inf = LLONG_MAX;
const ll N = 1e5 + 10;

int32_t main() {
    fast_io();

    int n, k; cin >> n >> k;
    vector<pll> a(n); f (i, 0, n) { cin >> a[i].F; a[i].S = i; }
    int team = 1;
    sort(all(a));
    set<int> pos;
    f (i, 0, n) pos.insert(i);
    // vll pos(n);
    string ans(n, '0');
    debug(ans);
    for (int i = n-1; i >= 0; i--) {
        if (pos.find(a[i].S) != pos.end()) {
            auto it = pos.find(a[i].S);
            int tk = k;
            vll dels;
            while (tk+1) {
                dels.pb(*it);
                tk--;
                if (it == pos.begin()) break;
                it--;
            }
            it = pos.find(a[i].S);
            tk = k;
            it++;
            while (it != pos.end() and tk) {
                dels.pb(*it);
                tk--;
                it++;
            }
            for (auto it : dels) {
                ans[it] = '0' + team;
                pos.erase(it);
            }
            if (team == 1) team = 2;
            else team = 1;
        }
        debug(ans);
        // if (pos[a[i].S] == 0) {
        //     pos[a[i].S] = team;
        //     int idx = a[i].S + 1;
        //     int tk = k;
        //     while (tk and idx < n) {
        //         if (pos[idx] == 0) {
        //             pos[idx] = team;
        //             tk--;
        //         }
        //         idx++;
        //     }
        //     idx = a[i].S - 1;
        //     tk = k;
        //     while (idx >= 0 and tk) {
        //         if (pos[idx] == 0) {
        //             pos[idx] = team;
        //             tk--;
        //         }
        //         idx--;
        //     }
        //     if (team == 1) team = 2;
        //     else team = 1;
        // }
    }
    cout << ans << endl;

    return 0;
}