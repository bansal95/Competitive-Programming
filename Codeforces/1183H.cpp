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
template <typename s, typename B>
string to_string(pair<s, B> p) {
return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename s>
string to_string(s v) {
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

int solution(string s, int k) {
  const int N = s.size();
  if (k == 0)
    return 1;
  if (N == k)
    return 1;
  if(k==1){
    set<int> se;
    f (i, 0, N){
      se.insert(s[i] - 'a');
    }
    return se.size();
  }

  vector<int> v1(N, 0), v2(N, 0), v3(26, 0);

  v2[N - 1] = 1;
  v3[s[N - 1] - 'a'] = 1;

  for (int i = N - 2; i >= 0; i--) {
    v2[i] = v2[i + 1];
    if (v3[s[i] - 'a'] == 0) {
      v2[i]++;
      v3[s[i] - 'a'] = 1;
    }
  }

  for (int j = 1; j < k; j++) {
    fill(v3.begin(), v3.end(), 0);
    v1[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
      v1[i] = v1[i + 1];
      v1[i] = v1[i] + v2[i + 1];
      v1[i] = v1[i] - v3[s[i] - 'a'];
      v3[s[i] - 'a'] = v2[i + 1];
    }
    v2 = v1;
  }
  return v1[0];
}

int32_t main() {
  fast_io();

  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0;
  for(int i = n; i >= 0; i--){
    int temp = solution(s, i);
      if (temp >= k) {
      ans += k * (n - i);
      break;
    } else {
      ans += temp * (n - i);
      k -= temp;
    }
    if (i == 0) {
      cout << -1 << endl; 
      return 0;
    }
  }
  cout << ans;

  return 0;
}