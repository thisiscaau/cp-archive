/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
// POI ZAM2 2002 IX
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
ll n,m,e,p,b;
ll a[105];
vector<ll> g[105];
ll vis[105][1005],par[105][1005];
queue<ii> q;
vector<ll> path;
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> e >> p >> b;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for (int i = 1 ; i <= m ; i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    q.push(mp(e,a[e])); vis[e][a[e]] = 1; par[e][a[e]] = -1;
    while (!q.empty()){
        ii cur = q.front(); q.pop();
        ll u = cur.fi , w = cur.se;
        for (ll v : g[u]){
            if (w + a[v] <= b && !vis[v][w+a[v]]){
                vis[v][w+a[v]] = 1;
                par[v][w+a[v]] = u;
                q.push(mp(v,w+a[v]));
            }
        }
    }
    ll pos = p, tot = b;
    while (pos != -1){
        path.pb(pos);
        tot -= a[pos];
        pos = par[pos][tot + a[pos]];
    }
    reverse(path.begin(),path.end());
    for (ll u : path) cout << u << " ";
}