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
ll const inf = 1e9 + 7, MAXN = 1e4 + 5;
/* declaration */
ll n,m,t;
ll cw[MAXN];
ll par[MAXN];
ll d[MAXN];
ll tot[MAXN]; // total cow going through
/* workspace */
vector<ii> g[MAXN];
vector<ll> gg[MAXN]; 
map<ll,bool> vis;
void dfs(ll node,ll par){
    tot[node] += cw[node];
    for (ll nxt : gg[node]){
        if (nxt == par) continue;
        dfs(nxt,node);
        tot[node] += tot[nxt];
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("shortcut.in","r",stdin);
    freopen("shortcut.out","w",stdout);
    cin >> n >> m >> t;
    for (int i = 1 ; i <= n ; i++) cin >> cw[i];
    for (int i = 1 ; i <= m ; i++){
        ll u,v,w; cin >> u >> v >> w;
        g[u].pb(mp(w,v));
        g[v].pb(mp(w,u));
    }
    memset(par,-1,sizeof(par));
    memset(d,inf,sizeof(d));
    d[1] = 0; vis[1] = true;
    priority_queue<ii,vii,greater<ii>> pq;
    pq.push(mp(0,1));
    while (!pq.empty()){
        ii cur = pq.top(); pq.pop();
        vis[cur.se] = true;
        if (d[cur.se] != cur.fi) continue;
        for (ii nxt : g[cur.se]){
            if (vis[nxt.se]) continue;
            if (d[cur.se] + nxt.fi < d[nxt.se]){
                d[nxt.se] = d[cur.se] + nxt.fi;
                par[nxt.se] = cur.se;
                pq.push(mp(d[nxt.se],nxt.se));
            }
            else if (d[nxt.se] == nxt.fi + d[cur.se] && cur.se < par[nxt.se]){
                par[nxt.se] = cur.se;
                pq.push(mp(d[nxt.se],nxt.se));
            }
        }
    }
    for (int i = 2 ; i <= n ; i++){
        gg[i].pb(par[i]);
        gg[par[i]].pb(i);
    }
    dfs(1,-1);
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++){
        ans = max(ans,tot[i]*(d[i] - t));
    }
    cout << ans;
}