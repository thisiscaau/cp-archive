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
ll n,m,tc,timer;
vector<ll> g[MAXN];
ll tin[MAXN],low[MAXN];
bool vis[MAXN],arti[MAXN];
/* workspace */

void dfs (ll u,ll p = -1){
    vis[u] = true;
    tin[u] = low[u] = ++timer;
    ll child = 0;
    for (ll v : g[u]){
        if (v == p) continue;
        if (vis[v]){
            // back edge
            low[u] = min(low[u],tin[v]);
        }
        else {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if (tin[u] <= low[u] && p != -1){
                arti[u] = true;
            }
            child++;
        }
    }
    if (p == -1 && child > 1){
        arti[u] = true;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    for (int i = 1 ; i <= n ; i++){
        if (!vis[i]) dfs(i);
    }
    for (int i = 1 ; i <= n ; i++){
        cout << arti[i] << " ";
    }
}