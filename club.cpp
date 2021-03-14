/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e6 + 5;
/* declaration */
ll n,m,ans = 0;
map<ll,ll> mp;
/* workspace */
void solve(){
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a;
        mp[a]++;
        if (mp[a] == a){
            mp[a] = 0;
            ans++;
        }
    }
    cout << ans;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}