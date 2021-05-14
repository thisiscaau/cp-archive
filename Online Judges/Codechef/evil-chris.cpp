/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
typedef pair<ii,ii> quad;
typedef pair<ll,ii> tup;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,d,q;
set<ii> g;
ll sc[MAXN];
// disjoint set union
struct union{
    ll sz;
    struct node {
        ll par,sum;
    };
    vector<node> dsu;
    union (ll k){
        sz = k;
        for (int i = 0 ; i < k ; i++){
            node tmp; tmp.par = i;
            tmp.sum = 0; dsu.pb(tmp); 
        }
    }
    void reset(ll k){
        dsu.clear(); sz = k;
        for (int i = 0 ; i < k ; i++){
            node tmp; tmp.par = i;
            tmp.sum = 0; dsu.pb(tmp);
        }
    }

    ll find (ll u){
        return dsu[u].par == u ? u : find(dsu[u].par);
    }

    void join(ll u,ll v){
        u = find(u); v = find(v);
        if (u == v) return;
        if (rand() & 1) swap(u,v);
        dsu[v].par = u;
        dsu[u].sum += dsu[v].sum;
    }
    
    bool same (ll u,ll v){
        return dsu[u].par == dsu[v].par;
    }

    void add(ll u,ll val){
        u = find(u);
        dsu[u].sum += val;
    }

    ll get(ll u){
        u = find(u);
        return dsu[u].sum;
    }
};
union dsu(MAXN);

ll cal(ll a,ll b){
    return dsu.get(a) + dsu.get(b);
}

void clr(){
    dsu.reset(n);
    for (int i = 0 ; i < n ; i++){
        dsu.add(i,sc[i]);
    }
    for (ii e : g){
        dsu.join(e.fi,e.se);
    }
}

// workspace
vector<tup> query;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> d >> q;
    for (int i = 0 ; i < n ; i++){
        cin >> sc[i];
    }
    for (int i = 0 ; i < m ; i++){
        ll u,v; cin >> u >> v;
        u--; v--;
        g.insert(mp(u,v));
        g.insert(mp(v,u));
    }
    for (int i = 0 ; i < d ; i++){
        ll t,u,v; cin >> t >> u >> v; u--;
        if (t == 1){
            v--; g.erase(mp(u,v)); g.erase(mp(v,u));
        }
        else {
            sc[u] -= v;
        }
        query.pb(mp(t,mp(u,v)));
    }
    for (int i = 0 ; i < k ; i++){
        ll p1,p2,tot;
        cin >> p1 >> p2 >> tot;
        p1--; p2--;
        ques
    }
    reverse(query.begin(),query.end());
    clr();

}