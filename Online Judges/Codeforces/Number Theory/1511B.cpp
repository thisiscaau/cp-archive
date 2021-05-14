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
ll a[MAXN];
bool connect[MAXN];
/* workspace */
void solve(){
    cin >> n >> m;
    ll ans = 0;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        connect[i] = false;
    }
    // true if there is edge between ai and ai+1 (i >= 1 && i < n)
    vector<ii> vi;
    for (int i = 1 ; i <= n ; i++){
        vi.pb(mp(a[i],i));
    }
    sort(vi.begin(),vi.end());
    for (ii cur : vi){
        ll num = cur.fi , idx = cur.se;
        if (num >= m) break;
        // go back and forth
        // supposing the current number to be the smallest number in range
        // expanding rightward and leftward
        while (idx - 1 >= 1){
            if (connect[idx-1]) break;
            if (a[idx-1] % num == 0){
                connect[idx-1] = true;
                ans += num;
                idx--;
            }
            else break;
        }
        idx = cur.se;
        while (idx + 1 <= n){
            if (connect[idx]) break;
            if (a[idx+1] % num == 0){
                connect[idx] = true;
                ans += num;
                idx++;
            }
            else break;
        }
    }
    for (int i = 1 ; i < n ; i++){
        if (!connect[i]){
            ans += m;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> tc;
    while (tc--){
        solve();
    }
}