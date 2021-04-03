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
ll const inf = 1e9 + 7, MAXN = 1e5 + 5;
/* declaration */
ll n,m,tc;
ll a[MAXN];
ll ans[MAXN],cnt[MAXN];
/* workspace */
void solve1(){
    ll idx = 1,ok = 0,sz = 1,mx = 1;
    while (idx < n && ok < 2){
        if (a[idx] > a[idx-1]){
            sz++;
        }
        else {
            mx = max(mx,sz);
            sz = 1;
        }
        idx++;
        if (idx == n){
            if (a[0] > a[idx-1]){
                sz++;
                idx = 1;
            }
            ok++;   
        }
    }
    cout << mx;
}
void solve2(){
    sort(a,a+n);
    ll cw = 0,ccw = n-1;
    ans[cw++] = a[0];
    for (int i = 1 ; i < n ; i++){
        if (ans[(ccw+1) % n] < ans[cw-1]){
            ans[ccw--] = a[i];
        }
        else {
            ans[cw++] = a[i];
        }
    }
    for (int i = 0 ; i < n ; i++){
        cout << ans[i] << " ";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("ROBOT9.inp","r",stdin);
    freopen("ROBOT9.out","w",stdout);
    cin >> tc >> n;
    for (int i = 0 ; i < n ; i++){
        cin >> a[i];
    }
    if (tc == 1) solve1();
    else solve2();
}