// given array and number x find maximum value X xor A[i]
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
ll const inf = 1e9 + 7, MAXN = 1e6 + 5;
/* declaration */
ll n,m,tc;
/* workspace */
struct node {
    ll child[3]; // for binary
};
node trie[MAXN];
ll triesize = 0;
void gen(ll u){
    memset(trie[u].child,-1,sizeof(trie[u].child));
}
void push(ll a){
    ll p = 0;
    for (int i = 30 ; i >= 0 ; i--){
        ll bit;
        if(a & (1 << i)) bit = 1;
        else bit = 0;
        if (trie[p].child[bit] == -1){
            gen(++triesize);
            trie[p].child[bit] = triesize;
        }
        p = trie[p].child[bit];
    }
}
ll dfs(ll u,ll pos,ll val){
    ll bit;
    if (val & (1 << pos)) bit = 0;
    else bit = 1; // flipped bit because of XOR operation
    if (trie[u].child[bit] != -1){
        return dfs(trie[u].child[bit],pos-1,val) + (1ll << pos);
    }
    else {
        return dfs(trie[u].child[!bit],pos-1,val);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    gen(0);
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        ll a; cin >> a; push(a);
    }
    cin >> m;
    for (int i = 1 ; i <= m ; i++){
        // queries
        ll x; cin >> x;
        cout << dfs(0,30,x) << endl;
    }
}