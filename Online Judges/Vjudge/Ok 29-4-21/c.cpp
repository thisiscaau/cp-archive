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
ll n,m,k;
set<ii> forbid;
set<ll> g;
/* workspace */
bool check(ll u,ll v){
    // check if there is edge
    if (u < v) swap(u,v);
    return forbid.find(mp(u,v)) == forbid.end();
}
void dfs(ll u){
    if (g.find(u) != g.end()) g.erase(u);
    vector<ll> adj;
    for (ll v : g) {
        if (check(u,v)){
            adj.pb(v);
        }
    }
    for (ll v : adj) g.erase(v);
    for (ll v : adj) dfs(v);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    ll mx_deg = n - 1; // maximum degree
    for (int i = 1 ; i <= m ; i++){
        ll u,v; cin >> u >> v;
        ll uu = max(u,v), vv = min(u,v);
        if (vv == 1) mx_deg--;
        forbid.insert(mp(uu,vv));
    }
    for (int i = 2 ; i <= n ; i++) g.insert(i);
    // exclusion
    if (mx_deg < k) {
        cout << "impossible";
        return 0;
    }
    // dfs
    ll ccp = 0;
    for (int i = 2 ; i <= n ; i++){
        if (check(1,i) && g.find(i) != g.end()){
            dfs(i); ccp++;
        }
    }
    if (!g.empty()){
        cout << "impossible";
        return 0;
    }
    if (ccp > k){
        cout << "impossible";
        return 0;
    }
    cout << "possible";
}