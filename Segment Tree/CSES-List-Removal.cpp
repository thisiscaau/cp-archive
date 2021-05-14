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
ll n,m,tc,pos;
ll a[MAXN];
ll st[4*MAXN];
/* workspace */
void build(ll node = 1,ll tl = 1,ll tr = n){
    if (tl == tr){
        st[node] = 1;
        return;
    }
    ll tm = (tl+tr) >> 1;
    build(left); build(right);
    st[node] = st[node << 1] + st[node << 1 | 1];
}
void get(ll id,ll node = 1,ll tl = 1,ll tr = n){
    if (tl == tr){
        // root
        pos = tl;
        return;
    }
    ll tm = (tl+tr) >> 1;
    if (st[node << 1] >= id) get(id,left);
    else get(id - st[node << 1],right);
}
void upd(ll id,ll node = 1,ll tl = 1,ll tr = n){
    if (tl > pos || tr < pos) return;
    if (tl == tr){
        st[node] = 0;
        return;
    }
    ll tm = (tl+tr) >> 1;
    upd(id,left); upd(id,right);
    st[node] = st[node << 1] + st[node << 1 | 1];
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    build();
    for (int i = 1 ; i <= n ; i++){
        ll idx; cin >> idx;
        get(idx); upd(pos);
        cout << a[pos] << " ";
    }
}