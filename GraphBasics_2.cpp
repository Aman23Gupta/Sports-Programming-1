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

// finding the total number of spanning trees in a graph
// if graph is complete with n nodes then we have caley's formula giving n^(n-2) spanning trees.
// otherwise the general idea is to use  Kirchhoff’s Theorem implemented below.
//https://www.geeksforgeeks.org/total-number-spanning-trees-graph/
//NOTE: include Determinant.cpp
int mat[10][10];
void solve(){
    int n,m;cin>>n>>m;
    int a,b;
    rep(i,0,m){
        cin>>a>>b;
        mat[a][b]=1;
        mat[b][a]=1;
    }
    rep(i,1,n+1){
        int su=0;
        rep(j,1,n+1){
            su+=mat[i][j];
        }
        mat[i][i]=su;
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(i==j || mat[i][j]==0)continue;
            mat[i][j]=-1;
        }
    }

    vvd(n-1,n-1,v);
    rep(i,2,n+1){
        rep(j,2,n+1){
            v[i-2][j-2]=mat[i][j];
        }
    }
    deter(v,n-1);
}


//0-1 BFS
//Given a graph with edges having weight equal to 0 or 1. Find SSSP in O(E+V)
//This problem can be easily handled in O(E+VlogV) using Djkstra

// Lemma: During the execution of BFS, the queue holding the vertices onl contains elements from at
// max two successive levels of the BFS tree.
//https://cp-algorithms.com/graph/01_bfs.html#toc-tgt-1

// in case of small range of weights a general version "Dial's Algorithm" can be used in O(V*W), W is max weight of any edge.
// https://www.geeksforgeeks.org/dials-algorithm-optimized-dijkstra-for-small-range-weights/
bfs01(int node){
    dis[node] = 0;
    deque<int> q;
    q.push_front(node);
    while (!q.empty()) {
        int s = q.front();
        q.pop_front();
        for (auto child : v[s]) {
            int u = child.ff;
            int w = child.ss;
            if (d[s] + w < d[u]) {
                d[u] = d[v] + w;
                if (w == 1)
                    q.push_back(u);
                else
                    q.push_front(u);
            }
        }
    }
}

// kosaraju's formula to find the strongest connected components
// in a directed graph those SCC are components in which we can a point from any other point.
// or you may say that SCC are component where there is route for every node from itself to itself.
// there are 3 steps in kosaraju's algorithm

//1- sorting nodes acc. to finish time of their DFS

void dfs(int node,stack<int> &s){
    visited[node]=true;
    for(auto u:v[node]){
        if(visited[u])continue;
        dfs(u,s);
    }
    s.push(node);
}

//2- obtaining a transverse graph... i.e a graph formed by reversing the edges of orginal graph
// this is implemented inside main

//3- in this step we finally obtain connected components by call DFS on transversed graph in the order 
// of node present in stack
// remember to clear visited
void revdfs(int node){
    visited[node]=true;
    cout<<node<<" ";
    for(auto u:rv[node]){
        if(visited[u])continue;
        revdfs(u);
    }
}

int main(){
    //take input for graph
    stack<int> s;
    rep(i,1,n+1)if(!visited[i])dfs(i,s);
    //step-1 completed
    
    //step-2
    vector<int> rv[N];
    rep(i,1,n+1)for(auto u:v[i])rv[u].pb(i);
    
    //step-3
    rep(i,1,n+1)visited[i]=false;
    while(!s.empty()){
        int node=s.top();
        s.pop();
        if(!visited[node]){
            cout<<"SCC: ";
            revdfs(node);
            cout<<endl;
        }
    }
}

