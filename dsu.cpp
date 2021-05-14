struct dsu{
    vector<ll> data;
    ll cc = 0;
    /* 
    data[x] < 0 => x is root
    -data[x] => its tree size
    data[x] >= 0 => data[x] is x's parent
    */
    dsu(ll n = -1){
        if (n >= 0) init(n);
    }

    void init(ll sz){
        cc = sz;
        data.assign(sz+1,-1);
    }

    ll find (ll u){
        return data[x] < 0 ? x : find(data[x]);
    }

    ll get_size (ll u){
        return -data[find(u)];
    }

    bool join (ll u,ll v){
        u = find(u); v = find(v);
        if (u == v) return false;
        if (-data[u] < -data[v]) swap(u,v);
        data[u] += data[v];
        data[v] = x;
        cc--;
        return true;
    }
};