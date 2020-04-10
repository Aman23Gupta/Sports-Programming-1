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
            low[node]=min(low[child],low[node]);
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
