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
ll const inf = 1e9 + 7, MAXN = 30000005;
/* declaration */
ll n,m,tc,lazy;
ll triesize = 0;
struct node{
    ll go;
    ll child[3];
} trie[MAXN];
void gen (ll u){
    memset(trie[u].child,-1,sizeof(trie[u].child));
    trie[u].go = 0;
}
void push(ll a){
    ll p = 0;
    for (int i = 30 ; i >= 0 ; i--){
        ll bit;
        if (a & (1 << i)) bit = 1;
        else bit = 0;
        if (trie[p].child[bit] == -1){
            gen(++triesize);
            trie[p].child[bit] = triesize;
        }
        p = trie[p].child[bit];
        trie[p].go++;
    }
}
ll dfs(ll u,ll pos,ll k){
    ll bit = (lazy & (1 << pos)) ? 0 : 1;
    if (trie[u].child[bit] != -1 && trie[trie[u].child[bit]].go >= k){
        return dfs(trie[u].child[bit],pos-1,k) + (1 << pos);
    }
    else if (trie[u].child[!bit] != -1){
        if (trie[u].child[bit] != -1) k -= trie[trie[u].child[bit]].go;
        return dfs(trie[u].child[!bit],pos-1,k);
    }
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    gen(0);
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a;
        push(a);
    }
    for (int i = 1 ; i <= m ; i++){
        string q; ll a;
        cin >> q >> a;
        if (q[0] == 'X') lazy ^= a;
        else cout << dfs(0,30,a) << endl;
    }
}