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
/* workspace */
ll a[MAXN];
ll dp[5005][5005];
ll mx[5005][5005];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
        dp[i][i] = mx[i][i] = a[i];
    }
    for (int l = n ; l >= 1; l--){
        for (int r = l ; r <= n ; r++){
            if (l == r){
                dp[l][r] = a[l];
                mx[l][r] = max(mx[l][r],dp[l][r]);
            }
            else {
                dp[l][r] = dp[l+1][r] ^ dp[l][r-1];
                mx[l][r] = max({dp[l][r],mx[l+1][r],mx[l][r-1]});
            }
        }
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        cout << mx[l][r] << endl;
    }
}