/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
/* workspace */
string s,t;
ll sa[MAXN],sb[MAXN],ta[MAXN],tb[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> s >> t;
    s = '#' + s; t = '#' + t;
    for (int i = 1 ; i <= s.size() - 1 ; i++){
        sa[i] = sa[i-1] + (s[i] == 'A');
        sb[i] = sb[i-1] + (s[i] == 'B');
    }
    for (int i = 1 ; i <= t.size() - 1 ; i++){
        ta[i] = ta[i-1] + (t[i] == 'A');
        tb[i] = tb[i-1] + (t[i] == 'B');
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        ll a,b,c,d; cin >> a >> b >> c >> d;
        // left 1 - right 1 - left 2 - right 2
        ll t1,t2,t3,t4;
        t1 = sa[b] - sa[a-1]; // count a
        t2 = sb[b] - sb[a-1]; // count b
        t3 = ta[d] - ta[c-1]; // count a 
        t4 = tb[d] - tb[c-1]; // count b
        if (abs((t1*2+t2) - (t3*2+t4)) % 3 == 0) cout << "YES" << endl;
        else if (abs((t1+t2*2) - (t3+t4*2)) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}