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

  int n, m; cin >> n >> m;
  vll a(n+2, 0);
  vector<pll> neg, pos;
  int maxm = n;
  f (_, 0, m) {
    int t, l, r; cin >> t >> l >> r;
    if (t == 0) {
      neg.pb({l, r});
    } else {
      pos.pb({l, r});
    }
  }
  sort(all(pos));
  int lastIdx = 1;
  for (auto &it : pos) {
    if (it.F > lastIdx) {
      f (i, lastIdx, it.F) {
        a[i] = maxm;
        maxm--;
      }
    }
    if (a[it.F] != 0) {
      int tm = a[it.F];
      f (i, it.F, it.S+1) {
        a[i] = tm;
      }
      maxm = tm - 1;
    } else {
      f (i, it.F, it.S+1) {
        a[i] = maxm;
      }
      maxm--;
    }
    debug(it, lastIdx);
    lastIdx = max(lastIdx, it.S+1);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      a[i] = maxm;
      maxm--;
    }
  }
  debug(a);
  for (auto &it : neg) {
    if (is_sorted(a.begin() + it.F, a.begin() + it.S + 1)) {
      cout << "NO" << endl;
      debug(it);
      return 0;
    }
  }
  cout << "YES" << endl;
  f (i, 1, n+1) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}