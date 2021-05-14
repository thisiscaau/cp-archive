#include<bits/stdc++.h>
using namespace std;
#define left node*2,tl,tm
#define right node*2+1,tm+1,tr
const int MAXN = 5e5 + 5;
struct seg{
    int id,mx,suf,pre,lazy = -1;
    seg() {}
    seg(int a,int b,int c,int d) : pre(a),suf(a),mx(c),id(d) {}
};
seg st[4*MAXN];
int n,m,ans;
seg merger(const seg& a,const seg& b,int tl,int tr){
    seg nw;
    int tm = (tl+tr) / 2;
    int a_sz = tm - tl + 1;
    int b_sz = tr - tm;
    nw.pre = a.pre == a_sz ? a_sz + b.pre : a.pre;
    nw.suf = b.suf == b_sz ? a.suf + b_sz : b.suf;
    nw.id = a.id; nw.mx = a.mx;
    if (a.suf + b.pre > nw.mx){
        nw.mx = a.suf + b.pre;
        nw.id = tm - a.suf + 1;
    }
    if (b.mx > nw.mx){
        nw.mx = b.mx;
        nw.id = b.id;
    }
    return nw;
}
void build(int node = 1,int tl = 1,int tr = n){
    if (tl == tr){
        st[node] = seg(1,1,1,tl);
        return;
    }
    int tm = (tl+tr) / 2;
    build(left); build(right);
    st[node] = merger(st[node*2],st[node*2 + 1],tl,tr);
}
void push(int node,int tl,int tr){
    if (st[node].lazy != -1){
        int nw = st[node].lazy ? 0 : (tr - tl + 1);
        st[node].pre = st[node].suf = st[node].mx = nw;
        if (tl != tr){
            st[node*2].lazy = st[node].lazy;
            st[node*2+1].lazy = st[node].lazy;
        }
        st[node].lazy = -1;
    }
}
void upd(int l,int r,bool op,int node = 1,int tl = 1,int tr = n){
    push(node,tl,tr);
    if (l > tr || r < tl || l > r) return;
    if (l <= tl && tr <= r){
        int nw = op ? 0 : (tr - tl + 1);
        st[node].pre = st[node].suf = st[node].mx = nw;
        if (tl != tr){
            st[node * 2].lazy = op;
            st[node * 2 + 1].lazy = op;
        }
        return;
    }
    int tm = (tl+tr) / 2;
    upd(l,r,op,left); upd(l,r,op,right);
    st[node] = merger(st[node * 2],st[node * 2 + 1],tl,tr);
}
void occupy(int sz,int node = 1,int tl = 1,int tr = n){
    push(node,tl,tr);
    if (tl == tr){
        upd(tl,tl,1);
        return;
    }
    int tm = (tl+tr) / 2;
    if (st[node*2].mx >= sz){
        occupy(sz,left);
        return;
    }
    if (st[node*2].suf + st[node*2+1].pre >= sz){
        int nw = tm - st[node*2].suf + 1;
        upd(nw,nw+sz-1,1);
        return;
    }
    occupy(sz,right);
}
signed main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    freopen("seating.in","r",stdin);
    freopen("seating.out","w",stdout);
    cin >> n >> m;
    build();
    while (m--){
        char op; cin >> op;
        if (op == 'A'){
            int sz; cin >> sz;
            if (st[1].mx >= sz){
                occupy(sz);
            }
            else {
                ans++;
            }
        }
        else {
            int l,r; cin >> l >> r;
            upd(l,r,0);
        }
    }
    cout << ans << endl;
}