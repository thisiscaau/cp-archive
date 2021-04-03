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
ll mat[1005][1005];
/* workspace */
bool can(ii a,ii b){
    ll h1 = abs(mat[a.fi][a.se]), h2 = abs(mat[b.fi][b.se]);
    ll d1 = max(n-a.fi,m-a.se), d2 = max(n-b.fi,m-b.se);
    return (d1 == 0 || h1*d2 < d1*h2);
}
ll count(ll ni,ll nj){
    ll res = 0, mi = n, mj = m;
    ll i = n - ni , j = m - nj;
    while (i >= 1 && j >= 1){
        if (can(mp(mi,mj),mp(i,j))){
            res++;
            mi = i , mj = j;
        }
        mat[i][j] *= -1; 
        i -= ni; j -= nj;
    }
    return res;
}
void solve1(){
    cout << count(1,0) + count(0,1);
}
void solve2(){
    ll res = 0;
    for (int i = n ; i >= 1 ; i--){
        for (int j = m ; j >= 1 ; j--){
            if (mat[i][j] >= 0 && (i != n || j != m)){
                res += count(n-i,m-j);
            }
        }
    }
    cout << res;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("ACA.inp","r",stdin);
    freopen("ACA.out","w",stdout);
    cin >> tc;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> mat[i][j];
        }
    }
    if (tc == 1) solve1();
    else solve2();
}