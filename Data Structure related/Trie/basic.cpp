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
ll const inf = 1e9 + 7, MAXN = 1e6 + 5;
/* declaration */
ll n,m,tc;
struct node{
    ll finish;
    ll child[27];
};
node trie[MAXN];
/* workspace */
void gen(ll id){
    memset(trie[id].child,-1,sizeof(trie[id].child));
    trie[id].finish = 0;
}
ll triesize = 0;
void push(string s){
    ll p = 0;
    for (int i = 0 ; i < s.size() ; i++){
        if (trie[p].child[s[i] - 'a'] == -1){
            gen(++triesize);
            trie[p].child[s[i] - 'a'] = triesize;
        }
        p = trie[p].child[s[i] - 'a'];
    }
    trie[p].finish++;
}
void dfs(ll u,string s){
    if (trie[u].finish){
        cout << s << " " << trie[u].finish << endl;
    }
    for (int i = 0 ; i < 26 ; i++){
        if (trie[u].child[i] != -1){
            dfs(trie[u].child[i],s+(char)('a' + i));
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    gen(0);
    for (int i = 1 ; i <= n ; i++){
        string s; cin >> s;
        push(s);
    }
    dfs(0,"");
}