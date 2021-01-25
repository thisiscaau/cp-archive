#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
ll n,m;
const ll MAXN = 1e5 + 5;
string s;
bool vis[30];
ll prefix[MAXN],suffix[MAXN];
char mi[MAXN],prefix_min[MAXN];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = "." + s;
    // prefix
    memset(vis,false,sizeof(vis));
    for (int i = 1 ; i <= n ; i++){
        prefix[i] = prefix[i-1];
        if (s[i]>s[i-1]){
            prefix[i]++;
            vis[s[i]-'A'] = true;
        }
        else if (s[i]<s[i-1]){
            if (!vis[s[i]-'A']){
                prefix[i]++;
                vis[s[i]-'A'] = true;
            }
        }
    }
    // suffix
    s = s + ".";
    memset(vis,false,sizeof(vis));
    for (int i = n ; i >= 1;i--){
        suffix[i] = suffix[i+1];
        if (s[i]>s[i+1]){
            suffix[i]++;
            vis[s[i]-'A'] = true;
        }
        else if (s[i]<s[i+1]){
            if (!vis[s[i]-'A']){
                suffix[i]++;
                vis[s[i]-'A'] = true;
            }
        }
    }
    for (int i = 1 ; i <= m ; i++){
        ll l,r;
        cin >> l >> r;
        cout << prefix[l-1] + suffix[r+1] << endl;
    }
}