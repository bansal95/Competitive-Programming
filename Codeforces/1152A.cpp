// aarsh01rsh@gmail.com
// Aarsh Sharma
#include<bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template < typename Arg1 >
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template < typename Arg1, typename... Args >
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << " | ";
	__f(comma + 1, args...);
}
#else
#define trace(...)
#endif
#define f(i, x, n) for (int i = x; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
	int temp, even_ch = 0, odd_ch = 0, even_key = 0, odd_key = 0;
	f(i, 0, n) {
		cin >> temp;
		if (temp % 2) {
			odd_ch++;
		} else {
			even_ch++;
		}
	}
	f(i, 0, m) {
		cin >> temp;
		if (temp % 2) {
			odd_key++;
		} else {
			even_key++;
		}
	}
	cout << min(odd_ch, even_key) + min(even_ch, odd_key);

	return 0;
}