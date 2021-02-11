/* Do what u love, love what u do */
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)
long double pi = 3.14159265359;
ll dp[21][5][5][11][11];
ll n,t;
signed main(){
    freopen("01.inp","r",stdin);
    freopen("01.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> t;
    ForE(l1,1,4){
        ForE(l2,1,4){
            dp[2][l1][l2][0][0] = 1;
        }
    }
    ForE(i,3,n){
        ForE(l0,1,4){
            ForE(l1,1,4){
                ForE(h,0,t){
                    ForE(v,0,t){
                        ForE(l2,1,4){
                            if (l2==l1||l0==l1) continue;
                            if (l1<l2&&l1<l0&&v){
                                dp[i][l1][l2][h][v] += dp[i-1][l0][l1][h][v-1];
                                continue;
                            }
                            if (l1>l2&&l1>l0&&h){
                                dp[i][l1][l2][h][v] += dp[i-1][l0][l1][h-1][v];
                                continue;
                            }
                            if (l0<l1&&l1<l2){
                                dp[i][l1][l2][h][v] += dp[i-1][l0][l1][h][v];
                                continue;
                            }
                            if (l0>l1&&l1>l2){
                                dp[i][l1][l2][h][v] += dp[i-1][l0][l1][h][v];
                                continue;
                            }
                        }
                    }
                }
            }
        }
    }
    ll res = 0;
    ForE(l1,1,4){
        ForE(l2,1,4){
            if (l1==l2) continue;
            res += dp[n][l1][l2][t][t-1];
        }
    }
    cout << res;
}