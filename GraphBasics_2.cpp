// single sources shortest path for weghted directed/undirected graphs
vector<pair<int,int>> v[100005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
vector<int> dis(100005,mod);

void djkstra(int node,int d){
    pq.push({d,node});
    dis[node]=d;
    while(!pq.empty()){
        int s=pq.top().ss;
        int sd=pq.top().ff;
        pq.pop();
        for(auto u:v[s]){
            if(dis[u.ff]>u.ss+sd){
                dis[u.ff]=u.ss+sd;
                pq.push({dis[u.ff],u.ff});
            }
        }
    }

}
void solve(){
    int n,m,a,b,w;
    cin>>n>>m;
    rep(i,0,m){
        cin>>a>>b>>w;
        v[a].pb({b,w});
        v[b].pb({a,w});
    }
    djkstra(1,0);
    rep(i,1,n+1){
        cout<<dis[i]<<" ";
    }
}

// algortihm to find articulation points
void dfs(int node,int par){
    visited[node]=true;
    in[node]=lo[node]=timer++;
    int children=0;
    for(auto child:v[node]){
        if(child==par)continue;
        if(visited[child]){
            lo[node]=min(lo[node],in[child]);
        }
        else{
            children++;
            dfs(child,node);
            lo[node]=min(lo[node],lo[child]);
            if(lo[child]>=in[node] && par!=-1){
                    ap.insert(node);
            }
        }
    }
    if(par==-1 && children>1){
        ap.insert(node);
    }

}
