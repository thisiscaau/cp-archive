/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// Parralel binary search practice
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef pair<ii,ll> iii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* disjoin set union */
ll par[MAXN],sz[MAXN],ans[MAXN];
vector<iii> pending;

ll find (ll u){
    return par[u] == u ? u : find(par[u]);
}

bool join(ll u,ll v){
    u = find(u); v = find(v);
    if (u != v){
        if (sz[v] > sz[u]) swap(u,v);
        sz[u] += sz[v];
        par[v] = u;
        // u - v - sz v  -- v must be the smaller one
        pending.pb(mp(mp(u,v),sz[v]));
        return true;
    }
    pending.pb(mp(mp(0,0),-1)); // same set
    return false;
}

void init(ll n){
    for (int i = 1 ; i <= n ; i++){
        par[i] = i; sz[i] = 1;
    }
}

/* declaration */
ll n,m,queries,cnt;
/* workspace */
vector<ll> que[MAXN << 2];
ii g[MAXN];
struct query {
    ll p1,p2,tot;
} q[MAXN];

/* undo disjoin set union */

void undo(){
    ll u,v,size;
    u = pending.back().fi.fi; v = pending.back().fi.se;
    size = pending.back().se;
    pending.pop_back();
    if (size != -1){
        par[v] = v;
        sz[u] -= size;
    }
}

/* Parralel binary search */

void solve(ll id,ll l,ll r){
    if (r == l){
        for (ll i : que[id]){
            ans[i] = r;
        }
        return;
    }
    ll mid = (l+r) >> 1;
    while (cnt < mid){
        cnt++;
        join(g[cnt].fi,g[cnt].se);
    }
    while (cnt > mid){
        undo(); cnt--;
    }
    // Categorize queries
    for (ll i : que[id]){
        ll u = find(q[i].p1), v = find(q[i].p2);
        ll tot = sz[u] + sz[v];
        if (u == v) tot -= sz[v];
        if (tot < q[i].tot){
            que[id << 1 | 1].pb(i);
        }
        else {
            que[id << 1].pb(i); 
        }
    }
    solve(id << 1,l,mid);
    solve(id << 1 | 1,mid+1,r);
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ;i++){
        cin >> g[i].fi >> g[i].se;
    }
    cin >> queries;
    for (int i = 1 ; i <= queries ; i++){
        cin >> q[i].p1 >> q[i].p2 >> q[i].tot;
        que[1].pb(i);
    }
    init(n); solve(1,1,m);
    for (int i = 1 ; i <= queries ; i++){
        cout << ans[i] << endl;
    }
}