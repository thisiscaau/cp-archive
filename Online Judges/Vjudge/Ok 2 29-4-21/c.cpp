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
ll a[MAXN],b[MAXN];
ll pos[MAXN];
/* workspace */
void solve(){
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        pos[a[i]] = i;
    }
    ll tot = 0,mx = -1;
    for (int i = 0 ; i < m ; i++){
        ll cur; cin >> cur;
        if (pos[cur] > mx){
            tot += (pos[cur] - i)*2 + 1;
            mx = pos[cur];
        }
        else tot++;
    }
    cout << tot << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--){
        solve();
    }
}