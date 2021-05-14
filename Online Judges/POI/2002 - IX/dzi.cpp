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
ll d[2005],d1[2005],d2[2005];
stack<ll> st;
/* workspace */
char mat[2005][2005];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n; m = n;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            cin >> mat[i][j];
        }
    }
    ll ans = 0; 
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (mat[i][j] == '1'){
                d[j] = i;
            }
        }
        for (int j = 1 ; j <= n ; j++){
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d1[j] = st.empty() ? 0 : st.top();
            st.push(j); 
        }
        while (!st.empty()) st.pop();
        for (int j = m ; j >= 1 ; j--){
            while (!st.empty() && d[st.top()] <= d[j]){
                st.pop();
            }
            d2[j] = st.empty() ? n + 1 : st.top();
            st.push(j);
        }
        while (!st.empty()) st.pop();
        for (int j = 1 ; j <= m ; j++){
            ans = max(ans,(i-d[j])*(d2[j]-d1[j]-1));
        }
    }
    cout << ans;
}