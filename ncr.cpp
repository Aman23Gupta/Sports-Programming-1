const int mod=998244353;
const int N=200005;
ll fac[N];
ll inv[N];

ll pw(ll x, ll p){
    if(!p)return 1;
    ll z=pw(x,p/2);
    z*=z;
    z%=mod;
    if(p%2==0)return z;
    z*=x;
    z%=mod;
    return z;
}

ll ncr(ll x,ll y){
    ll res=fac[x]*inv[y];
    res%=mod;
    res*=inv[x-y];
    res%=mod;
    return res;
}

void solve(){
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    fac[0]=inv[0]=1;
    rep(i,1,N){
        fac[i]=fac[i-1]*i;
        fac[i]%=mod;
        inv[i]=pw(fac[i],mod-2);
    }
    while(t--){
        solve();
    }
    return 0;
}
