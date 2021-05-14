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
#define ll int
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
ii glass[MAXN];
ll block[401][MAXN];
ll tot[MAXN];
/* workspace */
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        cin >> glass[i].fi >> glass[i].se;
        if (glass[i].se <= 400){
            block[glass[i].se][glass[i].fi]++;
        }
        else {
            // <= sqrt(n)
            for (int j = glass[i].fi ; j <= m ; j += glass[i].se){
                tot[j]++;
            } 
        }
    }
    for (int i = 1 ; i <= m ; i++){
        for (int j = 1 ; j <= 400 ; j++){
            if (i >= j){
                block[j][i] += block[j][i - j];
            }
            tot[i] += block[j][i];
        }
    }
    for (int i = 1 ; i <= m ; i++){
        cout << tot[i] << " ";
    }
}