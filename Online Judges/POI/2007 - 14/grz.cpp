/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
/* shortcuts */
/*#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")*/
// for emergency cases
// POI GRZ
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
/* declaration */
ll n,m,mx,mi;
const ll inf = 1e9 + 7;
int mat[1001][1001];
bool vis[1001][1001];
ll dx[] = {-1,-1,0,1,1,1,0,-1};
ll dy[] = {0,1,1,1,0,-1,-1,-1};
/* workspace */
void dfs(int i,int j){
    if (vis[i][j]) return;
    vis[i][j] = true;
    for (int go = 0 ; go < 8 ; go++){
        int ni = i + dx[go], nj = j + dy[go];
        if (ni < 1 || nj < 1 || ni > n || nj > n) continue;
        if (mat[ni][nj] != mat[i][j]){
            mi = min(mi,mat[ni][nj]);
            mx = max(mx,mat[ni][nj]);
        }
        else {
            dfs(ni,nj);
        }
    }
}
int valley = 0,ridge = 0;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            cin >> mat[i][j];
        }
    }
    bool done = true;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (mat[i][j] != mat[1][1]){
                done = false;
                break;
            }
        }
    }
    if (done){
        cout << 1 << " " << 1;
        return 0;
    }
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= n ; j++){
            if (!vis[i][j]){
                mi = inf, mx = -1;
                dfs(i,j);
                //cout << i << " " << j << " ";
                if (mat[i][j] < mx && mat[i][j] > mi){
                    // do nothing
                    continue;
                }
                else if (mat[i][j] < mx){
                    valley++;
                    //cout << "V";
                }
                else {
                    ridge++;
                    //cout << "R";
                }
                //cout << endl;
            }
        }
    }
    cout << ridge << " " << valley;
}