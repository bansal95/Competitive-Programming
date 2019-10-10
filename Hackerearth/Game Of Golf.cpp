/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl
#define ARRAY_SIZE(array) (sizeof(array) / sizeof(array[0]))

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t, k, a, b, c;
	cin >> t;
	while(t--) {
		cin >> k >> a >> b >> c;
		if(a+b+c == k or b-a+c == k or a-b+c == k or a+b-c == k or c-a-b == k or b-a-c == k or a-b-b == k) {
			cout << "WIN\n";
		} else {
			cout << "LOSE\n";
		}
	}

	return 0;
}