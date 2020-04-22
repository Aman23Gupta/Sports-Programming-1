// flattening of tree
// remember to take FT of size 2*N
// suppose you wanted to find which nodes exist in subtree of node 3, you can do so with the help of FT as all such nodes would lie between
// two 3 i.e FT=[...3,elements in subtree of node 3,3...];

int in[10000];
int FT[20000];
int out[10000];
int timer=1;

void dfs(int node,int par){
	in[node]=timer;
	FT[timer]=node;
	timer++;
	for(auto u:v[node]){
		if(u==par)continue;
		dfs(u,node);
	}
	out[node]=timer;
	FT[timer]=node;
	timer++;
}

