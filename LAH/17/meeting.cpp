/*                 thisiscaau's  code              
        What’s happened happened. Which is an expression of faith 
    in the mechanics of the world. It’s not an excuse to do nothing.
*/
// aurelion sol phu ho pls
// gura
/* shortcuts */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll opt,n,m,sz;
string w;
char mat[65][65];
/* workspace */
// OPERATION 2
ll d[20][20][3605]; // dijkstra
struct edge{
    ll i,j,idx;
    // substring range & index of cell
    // dijkstra compare
    bool operator > (const edge& other) const {
        return d[i][j][idx] > d[other.i][other.j][other.idx];
    }
};
priority_queue<edge,vector<edge>,greater<edge>> pq;
// pq for dijkstra
deque<ii> dq;
// positions that we can go into
ll pos[500];
ll id[65][65]; // id of cell
ll dx[] = {-1,0,1,0}; // directions
ll dy[] = {0,1,0,-1}; // directions
bool check(ll i, ll j){ 
    // check if inside
    if (i < 1 || i > n || j < 1 || j > m) return false;
    if (mat[i][j] == '#') return false;
    return true;
}
bool comp(ii a,ii b){
    // sort by pos
    return pos[mat[a.fi][a.se]-'A'] < pos[mat[b.fi][b.se]-'A'];
}
void bfs(ll i,ll j){
    while (!pq.empty()){
        auto e = pq.top(); pq.pop();
        ll cur_idx = e.idx; ll cur_i = dq[cur_idx].fi;
        ll cur_j = dq[cur_idx].se; // get pos of cell
        for (int go = 0 ; go < 4 ; go++){
            ll ni = cur_i + dx[go];
            ll nj = cur_j + dy[go];
            ll new_idx = id[ni][nj];
            if (check(ni,nj) && d[e.i][e.j][new_idx] > d[e.i][e.j][cur_idx] + 1){
                d[e.i][e.j][new_idx] = d[e.i][e.j][cur_idx] + 1;
                edge upd;
                upd.i = e.i; upd.j = e.j; upd.idx = new_idx;
                pq.push(upd);
            } 
        }
    }
}
void solve(){
    for (int i = 0 ; i < w.size() ; i++){
        pos[w[i]-'A'] = i;
    }
    sort(dq.begin(),dq.begin() + sz,comp);
    for (int i = 0 ; i < dq.size() ; i++){
        // marking index
        id[dq[i].fi][dq[i].se] = i;
    }
    for (int i = 0 ; i < sz ; i++){
        for (int j = 0 ; j < sz ; j++){
            for (int idx = 0 ; idx < dq.size() ; idx++){
                d[i][j][idx] = inf;
            }
        }
        d[i][i][i] = 0; // single letter
        edge ori; ori.i = i; ori.j = i; ori.idx = i;
        pq.push(ori);
        bfs(i,i);
    }
    for (int len = 2 ; len <= sz ; len++){
        for (int i = 0 ; i + len - 1 < sz; i++){
            ll j = i + len - 1;
            for (int idx = 0; idx < dq.size() ; idx++){
                ll mi = d[i][j][idx];
                for (int cut = i ; cut < j ; cut++){
                    mi = min(mi,(d[i][cut][idx] + d[cut+1][j][idx]));
                }
                if (mi < d[i][j][idx]){
                    d[i][j][idx] = mi;
                    edge upd; upd.i = i; upd.j = j; upd.idx = idx;
                    pq.push(upd);
                }
            }
            bfs(i,j);
        }
    }
    ll ans = inf;
    for (int i = 0 ; i < dq.size() ; i++){
        ans = min(ans,d[0][sz-1][i]);
    }
    if (ans >= inf){
        cout << "-1";
    }
    else {
        cout << ans;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("MEETING.inp","r",stdin);
    freopen("MEETING.out","w",stdout);
    cin >> opt;
    cin >> n >> m;
    cin >> w; sz = w.size();
    ll mx = 0,my = 0,mix = n,miy = m;
    for (int i = 1 ; i <= n ; i++){
        for (int j = 1; j <= m ; j++){
            cin >> mat[i][j];
            ll ni = i, nj = j;
            if (isupper(mat[i][j])){
                mx = max(mx,ni); my = max(my,nj);
                mix = min(mix,ni); miy = min(miy,nj);
                dq.push_front(mp(i,j));
            }
            else if (mat[i][j] != '#'){
                dq.push_back(mp(i,j));
            }
        }
    }
    if (opt == 1){
        cout << (mx - mix + 1) * (my - miy + 1);
    }
    else solve();
}