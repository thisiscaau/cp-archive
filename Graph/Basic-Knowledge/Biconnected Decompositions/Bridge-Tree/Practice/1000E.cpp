/*
thisiscaau's code
trying my best for a better future
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
ll const mod = 1e9 + 7, MAXN = 3e5 + 5,oo = 3e18;
ll par[MAXN],sz[MAXN],tin[MAXN],low[MAXN];
vector<ll> g[MAXN],tree[MAXN];
ll dis[MAXN];
vector<pair<ll,ll>> bridges;
ll n,m,timer,root,ans;


ll find (ll u){
    return par[u] == u ? u : find(par[u]);
}

void dsu(){
    for (int i = 1 ; i <= n ; i++){
        sz[i] = 1; par[i] = i;
    }
}

bool join (ll u,ll v){
    u = find(u); v = find(v);
    if (u != v){
        if (sz[v] > sz[u]) swap(u,v);
        sz[u] += sz[v];
        par[v] = u;
        return true;
    }
    return false;
}

void tarjan (ll u,ll par = -1){
    tin[u] = low[u] = ++timer;
    for (ll v : g[u]){
        if (v == par) continue;
        if (tin[v] > 0){
            // back edge
            low[u] = min(low[u],tin[v]);
        }
        else {
            tarjan(v,u);
            low[u] = min(low[u],low[v]);
            if (low[v] > tin[u]){
                bridges.pb(mp(u,v));
            }
            else {
                join(u,v);
            }
        }
    }
}

void build(){
    for (ii e : bridges){
        e.fi = find(e.fi); e.se = find(e.se);
        root = e.fi;
        tree[e.fi].pb(e.se); // add tree edge
        tree[e.se].pb(e.fi); // add tree edge
    }
}

void dfs(ll u,ll par = -1){
    for (ll v : tree[u]){
        if (v == par) continue;
        dfs(v,u);
        if (dis[v] + 1 + dis[u] > ans){
            ans = dis[v] + 1 + dis[u];
        }
        if (dis[v] + 1 > dis[u]){
            dis[u] = dis[v] + 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    dsu();
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    tarjan(1);
    build();
    dfs(root);
    cout << ans << endl;
}