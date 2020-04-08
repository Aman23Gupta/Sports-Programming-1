vector<int> v[10000];
bool visited[10000];

void dfs(int node){
    visited[node]=true;
    for(auto child:v[node]){
        if(visited[child])continue;
        dfs(child);
    }
}
