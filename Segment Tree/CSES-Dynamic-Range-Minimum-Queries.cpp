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
#define left node << 1,tl,tm
#define right node << 1 | 1,tm+1,tr
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
ll a[MAXN];
ll st[4*MAXN];
/* workspace */
void build(ll node = 1,ll tl = 1,ll tr = n){
    if (tl == tr){
        st[node] = a[tl];
        return;
    }
    ll tm = (tl+tr) >> 1;
    build(left); build(right);
    st[node] = min(st[node << 1],st[node << 1 | 1]);
}
void upd(ll pos,ll val,ll node = 1,ll tl = 1,ll tr = n){
    if (tl > pos || tr < pos) return;
    if (tl == tr){
        st[node] = val;
        return;
    }
    ll tm = (tl+tr) >> 1;
    upd(pos,val,left); upd(pos,val,right);
    st[node] = min(st[node << 1],st[node << 1 | 1]);
}
ll mi(ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (l > r || l > tr || tl > r) return inf;
    if (l <= tl && tr <= r) return st[node];
    ll tm = (tl+tr) >> 1;
    return min(mi(l,r,left),mi(l,r,right));
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    build();
    for (int i = 1 ; i <= m ; i++){
        ll op,u,v; cin >> op >> u >> v;
        if (op == 1) upd(u,v);
        else cout << mi(u,v) << endl;
    }
}