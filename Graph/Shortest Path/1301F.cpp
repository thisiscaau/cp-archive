/*
thisiscaau's code
trying my best for a better future
*/
#include<bits/stdc++.h>
using namespace std;
#define ll int
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
ll const mod = 1e9 + 7, MAXN = 2e5 + 5,oo = 3e18;
ll mat[1001][1001];
bool vis[41];
ll d[41][1001][1001]; // minimum cost to travel to (i,j) from some color
vector<ii> g[41];
ll n,m,k,que;
ll dx[] = {-1,0,1,0};
ll dy[] = {0,1,0,-1};


void bfs (ll color){
    memset(vis,false,sizeof(vis));
    queue<ii> q; vis[color] = true;
    for (ii pos : g[color]){
        d[color][pos.fi][pos.se] = 0;
        q.push(pos);
    }
    while (!q.empty()){
        ii nw = q.front(); q.pop();
        ll dist = d[color][nw.fi][nw.se],nw_col = mat[nw.fi][nw.se];
        if (!vis[nw_col]){
            vis[nw_col] = true;
            for (ii to : g[nw_col]){
                if (d[color][to.fi][to.se] != -1) continue;
                d[color][to.fi][to.se] = dist + 1;
                q.push(to);
            }
        }
        for (int go = 0 ; go < 4 ; go++){
            ii to = mp(nw.fi + dx[go],nw.se + dy[go]);
            if (to.fi < 1 || to.se < 1 || to.fi > n || to.se > m) continue;
            if (d[color][to.fi][to.se] != -1) continue;
            d[color][to.fi][to.se] = dist + 1;
            q.push(to);
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <= m ; j++){
            cin >> mat[i][j];
            g[mat[i][j]].pb(mp(i,j));
        }
    }
    memset(d,-1,sizeof(d));
    for (int i = 1 ; i <= k ; i++){
        bfs(i);
    }
    cin >> que;
    for (int i = 1 ; i <= que ; i++){
        ll r1,r2,c1,c2; cin >> r1 >> c1 >> r2 >> c2;
        ll ans = abs(r1 - r2) + abs(c1 - c2);
        if (r1 == r2 && c1 == c2){
            cout << "0" << endl;
        }
        else if (mat[r1][c1] == mat[r2][c2]){
            cout << 1 << endl;
        }
        else {
            for (int j = 1 ; j <= k ; j++){
                ll dist = d[j][r1][c1] + d[j][r2][c2] + 1;
                ans = min(ans,dist);
            }
            cout << ans << endl;
        }
    }
}