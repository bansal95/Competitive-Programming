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
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long int ll;
#define int ll
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;
typedef vector<ll> vll;

int32_t main()
{
	fast_io();

	int n, b, a; cin >> n >> b >> a;
	int light[n]; f(i, 0, n) cin >> light[i];
	int ans = 0, maxa = a;
	trace(b, a);
	f(i, 0, n) {
		if (light[i]) {
			if (a == maxa) {
				a--; ans++;
			} else if (b) {
				b--;
				if (a < maxa) a++;
				ans++;
			} else if (a) {
				a--; ans++;
			}
		} else {
			if (a) {
				a--; ans++;
			} else if (b) {
				b--; ans++;
			}
		}
		trace(light[i], b, a);
	}
	cout << ans;

	return 0;
}