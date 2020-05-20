//CONTENTS
// 1) vanilla DFS
// 2) SSSP in a tree and number of child  DFS
// 3) checking if graph is Bipartite
// 4) cycle detection in undirected graph
// 5) in-out timer
// 6) valnilla BFS SSSP for unweighted graph
// 7) Bridges
// 8) Kruskal's Algorithm MST
// 9) LCA

vector<int> v[10000];
bool visited[10000];

//basic/classic dfs
void dfs(int node){
    visited[node]=true;
    for(auto child:v[node]){
        if(visited[child])continue;
        dfs(child);
    }
}

//DFS can also be used to find SSSP in case of a tree... you require another array for storing distance and another arguement that
//stores the distance to assigned right after we mark that node true... 
void dfs1(int node){
    visited[node]=true;
    if(v[node].size()==1)noc[node]=0;
    for(auto u:v[node]){
        if(visited[u])continue;
        dis[u]=1+dis[node];
        dfs1(u);
        noc[node]+=1+noc[u];
 
    }
}// here noc=> no of child, dis=> distance from root.

//checking if given graph is Bipartite
bool dfs(int node,int col){
    visited[node]=true;
    co[node]=col;
    for(auto child:v[node]){
        if(!visited[child]){
            if(dfs(child,(col^1))==false)return false;
        }
        else{
            if(co[node]==co[child])return false;
        }
    }
    return true;
}

//cycle detection
bool dfs(int node,int par){
    visited[node]=true;
    for(auto child:v[node]){
        if(!visited[child]){
            if(dfs(child,node))return true;
        }
        else{
            if(child!=par)return true;
        }
    }
    return false;
}

//inout helps in flattening of tree... after which MO's algorithm can be applied for processing queries on tree.
//it can be used to efficiently solve queries given two node find if one occurs it other's subtree.
//if n1 is in the subtree of p1 then in[p1]<in[n1] and out[n1]<out[p1]
int in[1000];
int out[1000];
int timer=1;

void dfs(int node){
    visited[node]=true;
    in[node]=timer++;
    for(auto child:v[node]){
        if(!visited[child])dfs(child);
    }
    out[node]=timer++;
}


// calculating diameter of a tree. It requires two run of DFS.
// firstly you run a DFS from root node and find node farthest from root node.
// then you run a DFS from that node... the max distance obtained is the diameter.

//BFS
// as DFS can be used to find SSSP for unweighted tree, BFS can be used to find SSSP for unweighted graph.
void bfs(int node){
    visited[node]=true;
    d[node]=0;
    q.push(node);
    while(!q.empty()){
        int s=q.front();
        q.pop();
        for(auto u:v[s]){
            if(visited[u])continue;
            visited[u]=true;
            d[u]=d[s]+1;
            q.push(u);
        }
    }
}

//finding bridges
//the code is based on in and low times
// in time when dfs reaches the node
// low it is the lowest time when dfs reaches node or its ancestors(nodes it is directly connected with).

void dfs(int node,int par){
    visited[node]=true;
    in[node]=timer;
    low[node]=timer;
    timer++;
    for(auto child:v[node]){
        if(child==par)continue;
        else if(visited[child]){    // this is the case of back edge... a back edge can never be a bridge
            low[node]=min(in[child],low[node]);
        }
        else{
            dfs(child,node);
            if(in[node]<low[child]){
                cout<<"bridge from "<<node<<" to "<<child<<endl;
            }
            low[node]=min(low[node],low[child]);
        }
    }
}

//relation beteween bridge and articulation point
// the end of the bridge can be articulation point if their degree is more than 1.
// it is possible to have articulation point even when no bridge exists in the graph


//Kruskal's Algorithm(Minimum spanning Tree using DSU)
long kruskal(pair<int,pair<int,int>> p[],long m){//p is an array of pairs... first element is weight, and second element is a pair describing edge.
    long cost=0;                                 // 'm' denotes number of edges
    for(long i=0;i<m;i++){
        int x=p[i].second.first;
        int y=p[i].second.second;
        int fx,fy;
        fx=fin(x);
        fy=fin(y);
        if(fx==fy)continue;
        cost+=p[i].first;
        unio(x,y);
        
    }
    return cost;
    
}

//naive implementation of LCA, time comp => O(N)
int lca(int a,int b){
    if(dis[a]>dis[b])swap(a,b);
    
    int d=dis[b]-dis[a];
    
    while(d>0){
        b=par[b];
        d--;
    }
    
    if(a==b)return a;
    
    while(par[a]!=par[b]){
        a=par[a];
        b=par[b];
    }
    return par[a];
}

//log(N) LCA
const int N=10000;
const int maxN=(int)log2(N)+1;
int lca[N+1][maxN+1]; //This table stores for every N node, their ancestors at a distance of powers of two.
vector<int> v[N];
int dis[N];

void dfs(int node,int par){
    lca[node][0]=par;
    for(auto child:v[node]){
        if(child==par)continue;
        dis[child]=dis[node]+1;
        dfs(child,node);
    }
}


void init(){
    memset(lca, -1, sizeof(lca));
    dfs(1,-1); //dfs call to fill the immediate parents of each node
    rep(j,1,maxN+1){
        rep(i,1,N+1){
            if(lca[i][j-1]!=-1){
                int par=lca[i][j-1];
                lca[i][j]=lca[par][j-1];
            }
        }
    }
}

int LCA(int a,int b){
    if(dis[a]>dis[b])swap(a,b);
    int d=dis[b]-dis[a];
    while(d>0){
        int i=(int)log2(d);
        b=lca[b][i];
        d-=(1<<i);
    }

    if(a==b)return a;

    rem(i,maxN,-1){
        if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i]){
            a=lca[a][i];
            b=lca[b][i];
        }
    }

    return lca[a][0];
}

//distance between two nodes in log(N) time.
//preprocess lca and dis arrays
// distance between a and b = dis[a]+dis[b]-2*dis[LCA(a,b)];
//lca[i][j] represents 2^j th parent of i
