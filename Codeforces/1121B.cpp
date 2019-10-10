/*aarsh01rsh@gmail.com
Aarsh Sharma*/
#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define debug(x) cout << (#x) << " is " << (x) << endl

typedef long long int ll;
#define int ll
typedef pair < ll, ll > pll;
typedef vector < vector < ll > > matrix;
typedef vector < ll > vll;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vll count(200000);
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            count[a[i]+a[j]]++;
        }
    }
    sort(count.rbegin(), count.rend());
    cout << count[0];

    return 0;
}