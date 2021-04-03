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
#define prev cu
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 1e6 + 5;
/* declaration */
ll n,k,r;
ll a[MAXN];
ll prev[MAXN];
ll dp[MAXN],prefix[MAXN];
set<ll> st;
map<ll,ll> cur; 
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i = 1 ; i <= n ; i++) cin >> a[i];
    ll l = n+1;
    for (int r = n ; r >= 1 ; r--){
        while (l >= 2 && st.size() != k){
            st.insert(a[l-1]);
            l--;
            cur[a[l]]++;
        }
        if (st.size() != k){
            prev[r] = -1;
        }
        else {
            prev[r] = l;
        }
        cur[a[r]]--;
        if (cur[a[r]] <= 0){
            st.erase(a[r]);
        }
    }
    prefix[0] = 1;
    for (int i = 1 ; i <= n ; i++){
        if (prev[i] == -1){
            dp[i] = 0;
        }
        else {
            dp[i] = prefix[prev[i]-1];
        }
        prefix[i] = prefix[i-1] + dp[i];
        if (prefix[i] > inf) prefix[i] -= inf;
    }
    cout << dp[n];
}