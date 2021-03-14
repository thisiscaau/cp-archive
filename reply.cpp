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
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e4 + 5;
/* declaration */
ll n,t,tc = 0;
/* workspace */
void solve(){
    tc++;
    cin >> n; ll sum = 0;
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a;
        sum = max(sum+a,sum);
    }
    cout << "Case #" << tc << ": " << sum << endl; 
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> t;
    while (t--){
        solve();
    }
}