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
vector<ll> g[MAXN];
ll in_deg[MAXN];
priority_queue<ll> pq;
ll ans[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= m ; i++){
        ll u,v;
        cin >> u >> v;
        g[v].pb(u);
        in_deg[u]++;
    }
    for (int i = 1 ; i <= n ; i++){
        if (in_deg[i] == 0) pq.push(i);
    }
    ll idx = n;
    while (!pq.empty()){
        ll cur = pq.top(); pq.pop();
        ans[cur] = idx--;
        for (ll v : g[cur]){
            in_deg[v]--;
            if (in_deg[v] == 0) pq.push(v);
        }
    }
    for (int i = 1 ; i <= n ; i++){
        cout << ans[i] << " ";
    }
}