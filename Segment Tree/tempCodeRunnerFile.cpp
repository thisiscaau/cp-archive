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
#define left node << 1,tl,tm
#define right node <<< 1 | 1,tm+1,tr
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,m,p;
ll a[MAXN],st[MAXN << 2],add[MAXN << 2],mul[MAXN << 2];
void build(ll node = 1,ll tl = 1,ll tr = n){
    if (tl == tr){
        st[node] = a[tl];
        return;
    }
    ll tm = (tl+tr) >> 1;
    build(left); build(right);
    st[node] = st[node << 1] + st[node << 1 | 1];
}
void push(ll node, ll len){
    // lazy update
    // len = size of segment of node
    ll lf = len - (len >> 1), rt = len >> 1; // divide
    if (mul[node] != 1){
        (add[node << 1] *= mul[node]) %= p , (add[node << 1 | 1] *= mul[node]) %= p;
        (st[node << 1] *= mul[node]) %= p , (st[node << 1 | 1] *= mul[node]) %= p;
        (mul[node << 1] *= mul[node]) %= p , (mul[node << 1 | 1] *= mul[node]) %= p;
        mul[node] = 1;
    }
    if (add[node] != 0){
        (add[node << 1] += add[node]) %= p , (add[node << 1 | 1] += add[node]) %= p;
        (st[node << 1] += lf*add[node] % p) %= p, (st[node << 1 | 1] += rt*add[node] % p) % p;
        add[node] = 0;
    }
}
void upd(ll op,ll l,ll r,ll val,ll node = 1,ll tl = 1,ll tr = n){
    if (l > tr || r < tl || l > r) return;
    if (l <= tl && tr <= r) {
        if (opt & 1) (add[node] *= val) % p, (st[node] *= val) % p, (mul[node] *= val) % p;
        else (add[node] += val) % p, (st[node] += (r-l+1)*val % p) % p;
        return;
    }
    push(node);
    ll tm = (tl+tr) >> 1;
    upd(op,l,r,left); upd(op,l,r,right);
    st[node] = st[node << 1] + st[node << 1 | 1];
    st[node] %= p;
}
ll query(ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (l > tr || r < tl || l > r) return 0;
    if (l <= tl && tr <= r) return st[node];
    push(node);
    ll tm = (tl+tr) >> 1;
    return query(l,r,left) + query(l,r,right);
}
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> p;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for (int i = 1 ; i <= m ; i++){
        ll opt,l,r,x;
        cin >> opt >> l >> r;
        if (opt == 3){
            cout << query(l,r) << endl;
        }
        else{
            cin >> x;
            upd(opt,l,r,x);
        }
    }
}