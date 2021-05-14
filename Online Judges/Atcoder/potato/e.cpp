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
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,m,tc;
vector<ll> g[MAXN];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        ll p1,p2,tot; cin >> p1 >> p2 >> tot;
    }
}