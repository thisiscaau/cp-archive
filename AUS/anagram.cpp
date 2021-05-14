#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
typedef pair<ll,ll> ii;
typedef vector<ii> vii;
/* constants */
ll const inf = 1e9 + 7, MAXN = 2e5 + 5;
/* declaration */
ll n,m,tc;
map<string,vector<string>> mp;
/* workspace */
signed main(){
    ifstream w; ofstream f;
    f.open("anagout.txt");
    w.open("words.txt");
    string tmp;
    while (getline(w,tmp)){
        if (tmp == "#") break;
        string cur = "";
        for (int i = 0 ; i < tmp.size() ; i++){
            if (tmp[i] != ' '){
                cur += tmp[i];
            }
        }
        string ori = cur;
        sort(cur.begin(),cur.end());
        mp[cur].pb(ori);
    }
    w.close();
    w.open("anagin.txt");
    while (getline(w,tmp)){
        if (tmp == "#") break;
        string cur = "";
        for (int i = 0 ; i < tmp.size() ; i++){
            if (tmp[i] != ' '){
                cur += tmp[i];
            }
        }
        sort(cur.begin(),cur.end());
        if (mp[cur].size() == 0) f << "No anagram found" << '\n';
        else {
            for (string s : mp[cur]){
                f << s << " ";
            }
            f << '\n';
        }
    }
    f.close();
}