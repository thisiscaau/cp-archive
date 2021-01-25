#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define mp make_pair
ll n,res = 0;
bool vis[25];
ll a[25],b[25],ans[25];
void gen(ll idx){
    if (idx==n+1){
        res++;
        return;
    }
    else {
        for (int i = 1 ; i <= n ; i++){
            if (!vis[i]&&a[i]<=b[idx]){
                ans[idx] = a[i];
                vis[i] = true;
                gen(idx+1);
                vis[i] = false;
            }
        }
    }
}
signed main(){
    cin >> n;
    memset(vis,false,sizeof(vis));
    for (int i = 1 ; i <= n ; i++){
        cin >> a[i];
    }
    for (int i = 1 ; i <= n ; i++){
        cin >> b[i];
    }
    gen(1);
    cout << res;
}