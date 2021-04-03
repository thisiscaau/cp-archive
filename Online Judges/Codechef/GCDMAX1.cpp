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
ll const inf = 1e9 + 7, MAXN = 5e5 + 5;
/* declaration */
ll n,m;
ll a[MAXN];
ll lg[MAXN];
ll st[MAXN][21];
/* workspace */
ll gcd(ll a,ll b){
    while (b){
        a %= b;
        swap(a,b);
    }
    return a;
}
void sparse(){
    lg[0] = -1;
    for (int i = 1 ; i <= n ; i++){
        lg[i] = lg[i/2] + 1;
        st[i][0] = a[i];
    }
    for (int j = 1 ; j <= 19 ; j++){
        for (int i = 1 ; i + (1 << j) - 1 <= n ; i++){
            st[i][j] = gcd(st[i][j-1],st[i + (1 << (j - 1))][j-1]);
        }
    }
}
ll get(ll l,ll r){
    ll j = lg[r-l+1];
    ll g = gcd(st[l][j], st[r - (1 << j) + 1][j]);
    return g;
}
bool check(ll val){
    for (int i = 1 ; i + val - 1 <= n ; i++){
        ll cur = get(i,i+val-1);
        if (cur >= m) return true;
    }
    return false;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    sparse();
    ll l = 1 , r = n; ll ans = 0;
    while (l <= r){
        ll mid = (l+r) >> 1;
        if (check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
}