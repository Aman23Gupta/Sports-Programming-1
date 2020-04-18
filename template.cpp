#include <bits/stdc++.h>
using namespace std;
vector<string>vec_splitter(string s){s+=',';vector<string>res;while(!s.empty()){res.push_back(s.substr(0,s.find(',')));s=s.substr(s.find(',')+1);}
return res;}
void debug_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,__attribute__((unused))int LINE_NUM){cerr<<endl;}
template<typename Head,typename...Tail>void debug_out(vector<string>args,int idx,int LINE_NUM,Head H,Tail...T){if(idx>0)cerr<<", ";else cerr<<"Line("<<LINE_NUM<<") ";stringstream ss;ss<<H;cerr<<args[idx]<<" = "<<ss.str();debug_out(args,idx+1,LINE_NUM,T...);}
#define XOX
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif
#define ll          long long
#define ld          long double
#define ull         unsigned long long
#define pb          push_back
#define pii         pair<int,int>
#define pll         pair<long,long>
#define vi          vector<int>
#define vll         vector<ll>
#define vii         vector<pii>
#define Mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define rall(a)      (a).rbegin(),(a).rend()
#define ff           first
#define ss           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define mod        1000000007
//#define mod        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define rem(i,a,b)  for(int i=a;i>b;i--)
#define mp(a,b)     make_pair(a,b)
#define INF         numeric_limits<ll>::max();
#define NINF        numeric_limits<ll>::min();
#define vvi(a,b,name)    vector<vector<int>> name(a,vector<int>(b,-1))
//const ld pi=3.14159265359;
inline ll add(ll a,ll b,ll m){
    if((a+b)>=m)return (a+b)%m;
    return a+b;
}
inline ll mul(ll a,ll b,ll m){
    if((a*b)<m)return a*b;
    return (a*b)%m;
}

void solve(){


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
