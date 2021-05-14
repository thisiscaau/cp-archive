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
string mx(string a,string b){
    if (a.size() > b.size()) return a;
    else if (b.size() > a.size()) return b;
    return max(a,b);
}
string a,b;
string dp[3][1005];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> a >> b;
    n = a.size(); m = b.size();
    a = ' ' + a; b = ' ' + b;
    // we only need to keep track of 2 state at a time -> optimize
    for (int i = 1; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            if (a[i] == b[j]){
                if (dp[(i-1) % 2][j-1] != "0"){
                    dp[i % 2][j] = dp[(i-1) % 2][j-1] + a[i];
                }
                else dp[i % 2][j] = a[i];
            }
            else {
                dp[i % 2][j] = mx(dp[(i-1) % 2][j],dp[i % 2][j - 1]);
            }
        }
    }
    cout << dp[n % 2][m].size() << endl;
    cout << "LCS MAX NUMBER is ";
    if (dp[n%2][m].size() == 0) cout << "NULL";
    else cout << dp[n % 2][m];
}