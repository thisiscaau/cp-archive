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
ll n;
ll pw[15];
char mat[26][26][4];
bool vis[26][26][20000];
ii ori;
set<ll> ans;
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};
/* workspace */
bool win(ll mask){
    ll tmp[4][4];
    for (int i = 1 ; i <= 3 ; i++){
        for (int j = 1 ; j <= 3 ; j++){
            tmp[i][j] = mask % 3;
            mask /= 3;
        }
    }
    for (int i = 1 ; i <= 3 ; i++){
        if (tmp[i][1] == 1 && tmp[i][2] == 2 && tmp[i][3] == 2) return true;
        if (tmp[i][1] == 2 && tmp[i][2] == 2 && tmp[i][3] == 1) return true;
    }
    for (int j = 1 ; j <= 3 ; j++){
        if (tmp[1][j] == 1 && tmp[2][j] == 2 && tmp[3][j] == 2) return true;
        if (tmp[1][j] == 2 && tmp[2][j] == 2 && tmp[3][j] == 1) return true;
    }
    if (tmp[1][1] == 1 && tmp[2][2] == 2 && tmp[3][3] == 2) return true;
    if (tmp[1][1] == 2 && tmp[2][2] == 2 && tmp[3][3] == 1) return true;
    if (tmp[3][1] == 1 && tmp[2][2] == 2 && tmp[1][3] == 2) return true;
    if (tmp[3][1] == 2 && tmp[2][2] == 2 && tmp[1][3] == 1) return true;
    return false;
}
void dfs(ll i,ll j,ll mask){
    if (vis[i][j][mask]) return;
    vis[i][j][mask] = true;
    if (mat[i][j][1] == 'M' || mat[i][j][1] == 'O'){
        ll r = mat[i][j][2] - '1', c = mat[i][j][3] - '1';
        ll pos = 3*r + c;
        ll cur_char = (mask / pw[pos]) % 3;
        if (cur_char == 0){
            // hasnt been filled yet
            ll nw_char = (mat[i][j][1] == 'M') ? 1 : 2;
            // update mask
            mask = (mask % pw[pos]) + nw_char*pw[pos] + (mask - mask % pw[pos+1]);
            // ternary base stuffs
            if (!vis[i][j][mask] && win(mask)){
                ans.insert(mask);
                return;
            }
            vis[i][j][mask] = true;
        }
    }
    if (mat[i-1][j][1] != '#') dfs(i-1,j,mask);
    if (mat[i+1][j][1] != '#') dfs(i+1,j,mask);
    if (mat[i][j-1][1] != '#') dfs(i,j-1,mask);
    if (mat[i][j+1][1] != '#') dfs(i,j+1,mask);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n; pw[0] = 1;
    for (int i = 1 ; i <= 9 ; i++) pw[i] = pw[i-1]*3;
    for (int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            cin >> mat[i][j][1] >> mat[i][j][2] >> mat[i][j][3];
            if (mat[i][j][1] == 'B') ori = mp(i,j);
        }
    }
    dfs(ori.fi,ori.se,0);
    cout << ans.size();
}