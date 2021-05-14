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
ll const inf = 1e9 + 7, MAXN = 5e5 + 5;
/* declaration */
ll n,m,tc,q;
ll st[4*MAXN];
bool lazy[4*MAXN];
void push (ll node){
    if (lazy[node]){
        lazy[node << 1] = true;
        lazy[node << 1 | 1] = true;
    }
    lazy[node] = true;
}
void build(ll node = 1,ll tl = 1,ll tr = n){
    if (tl == tr){
        st[node] = 1;
        return;
    }
    ll tm = (tl+tr) >> 1;
    build(left); build(right);
    st[node] = st[node << 1] + st[node << 1 | 1];
}
void upd(ll l,ll r,ll node = 1,ll tl = 1,ll tr = n){
    if (l > tr || tl > r || l > r) return;

}
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> q;
    build();
}