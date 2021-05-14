/*
thisiscaau's code
trying my best for a better future
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;
ll n,m;
bool vis[101][101];
char mat[101][101];
ll msk[101][101];
queue<pair<ll,ll>> q;
pair<ll,ll> st,ed,path[101][101];

bool bfs(){
    // reset
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            vis[i][j] = false;
        }
    }
    bool row[n+1],col[m+1];
    memset(row,false,sizeof(row)); memset(col,false,sizeof(col));
    vis[st.fi][st.se] = true;
    q.push(st); path[st.fi][st.se] = mp(-1,-1);
    while (!st.empty()){
        pair<ll,ll> nw = q.front(); q.pop();
        if (!row[nw.fi]){
            row[nw.fi] = true;
            for (int i = 1 ; i <= m ; i++){
                if (!vis[nw.fi][i] && mat[nw.fi][i] == 'o'){
                    vis[nw.fi][i] = true;
                    q.push(mp(nw.fi,i));
                    path[nw.fi][i] = nw;
                }
            }
        }
    }
    if (!vis[ed.fi][ed.se]){
        return true;
    }
    pair<ll,ll> pos = ed;
    while (pos != st){
        mat[pos.fi][pos.se] = '.';
        pos = path[pos.fi][pos.se];
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> mat[i][j];
            if (mat[i][j] == 'S') st = mp(i,j);
            else if (mat[i][j] == 'T') ed = mp(i,j);
        }
    }
    ll ans = inf;
    for (int del = 0 ; del < 200 ; del++){
        if (bfs()){
            break;
        }
    }
    if (ans == inf){
        cout << "-1";
    }
    else {
        cout << ans;
    }
}