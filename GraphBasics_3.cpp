/*
CONTENTS
1) Handshaking Theorem
2) Euler Path and Euler Ckt
3) Bellman Ford
4) Floyd Warshall

2nCn/(n+1)= distinct BSTs can be constructed with n distinct keys.
The number of unique BSTs with 'n' nodes is equal to nth catalan number.
Handshaking Theorem - In every graph, the sum of the degrees of all vertices equals twice the number of edges.
total number of undirected graph that can be formed from 'n' vertices is 2^((n*(n-1))/2)

Euler Path and Euler Ckt.
A path is a sequence of vertices with the property that each vertex in the sequence is adjacent to the vertex next to it. 
A path that does not repeat vertices is called a simple path. 
A circuit is path that begins and ends at the same vertex. A circuit that doesn't repeat vertices is called a cycle.
An Euler path is a path that uses every edge of a graph exactly once.
An Euler circuit/cycle is a circuit that uses every edge of a graph exactly once
It appears that Euler Path is different from Euler circuit you'll call a sequence a Eluer path only when the point of start and end are different.

criteria for existence of a Euler path
1) all vertices other that the starting and ending vertices must be of even degree.
2) the starting and ending vertex should be of odd degree.
If a graph G has an Euler path, then it must have exactly two odd vertices

criteria for existence of a Euler ckt.
1) all the vertices should be of even degree.
If a graph G has an Euler circuit, then all of its vertices must be even vertices.

note that the aforementioned criteria's only gives you answers on the lines of "NO" or "May be, May not be".

# odd vertices   Euler path? Euler circuit?
    0                 No          Yes*
    2                 Yes*        No
4, 6, 8, . . .        No          No
1, 3, 5,           No such graphs exist

* provided the graph is connected..





Necessary and sufficient conditions
An undirected graph has a closed Euler tour iff it is connected and each vertex has an even degree.

An undirected graph has an open Euler tour (Euler path) if it is connected, and each vertex, except for exactly two vertices, has an even degree.
The two vertices of odd degree have to be the endpoints of the tour.

A directed graph has a closed Euler tour iff it is strongly connected and the in-degree of each vertex is equal to its out-degree.

Similarly, a directed graph has an open Euler tour (Euler path) iff for each vertex the difference between its in-degree and out-degree is 0, except for two vertices,
where one has difference +1 (the start of the tour) and the other has difference -1 (the end of the tour) and, if you add an edge from the end to the start, 
the graph is strongly connected.
*/

//below is the implementation of Hierholzer's Algorithm for UNdirected graph
//al in the adjacency list implemented as array of sets.
//before calling check for aforementioned conditions.
//if given graph meets the condition for Euler Ckt, then it can be called from any arbitrary vertex;
//if give graph meets the condition for Euler Graph then it should be only called from odd degree vertices.
//the final sequence of vertex can be obtained by rem(i,fsz-1,-1)cout<<final_path[i]<<" "; 
    
set<int> al[100000];
int temp_path[400002], final_path[400005], tsz, fsz;
 
void euler_dfs(int v){
	temp_path[tsz++] = v;
	while((int)al[v].size()!=0){
		int vv=*al[v].begin();
		al[v].erase(vv);
		al[vv].erase(v);
		euler_dfs(vv);
	}
	final_path[fsz++] = temp_path[--tsz];
}

//below is the implementation of Hierholzer's Algorithm for DIrected graph
//adj refers to adjacency matrix of graph.
//before calling check for aforementioned conditions.
//if given graph meets the condition for Euler Ckt, then it can be called from any arbitrary vertex;
//if give graph meets the condition for Euler Graph then it should be only called from vertex having outdeg>indeg.
//the final sequence of vertex can be obtained by rem(i,fsz-1,-1)cout<<final_path[i]<<" "; 

int temp_path[400002], final_path[400005], tsz, fsz;
void euler_dfs(int v){
	temp_path[tsz++] = v;
	while(!adj[v].empty()){
		int vv = adj[v].back();
		adj[v].pop_back();
		euler_dfs(vv);
	}
	final_path[fsz++] = temp_path[--tsz];
}
//BELLMAN FORD
// we can use dfs for finding SSSP in case of tree.
// we can use bfs for finding SSSP in case of unweighted graph.
// we can use djkstra finding SSSP in case of weighted graphs with non - negative edges. (Elog(v))
// The algorithm can process all kinds of graphs, provided that the graph does not contain a cycle with negative length.
// If the graph contains a negative cycle, the algorithm can detect this.
// just run BF one more time if there is a change in any distance then -ve cycle exists.
struct Edge {
    int a, b, w;
};
void BF(int n,int m){
    vector<int> d (n, INF);
    d[v] = 0;
    rep(i,0,n-1) {
        bool any = false;
		rep(j,0,m)
            if (d[e[j].a] < INF)// e is the edge list of the type struct Edge;
                if (d[e[j].b] > d[e[j].a] + e[j].w){
                    d[e[j].b] = d[e[j].a] + e[j].w;
                    any = true;
                }

        if (!any) break;
    }
    // display d, for example, on the screen
}



//FLOYD WARSHALL
// used to find shortest distance between any two vertices.
// This algorithm can also be used to detect the presence of negative cycles.
// The graph has a negative cycle if at the end of the algorithm, the distance from a vertex v to itself is negative.
int d[N][N]; // should be initialized with INF;

void FW(int n){
	rep(i,1,n+1){
		d[i][i]=0;
	}
	// when you input the graph, if i and j are connected by edge with weight w make d[i][j]=w;
	// this should be done after memset(d,INF,sizeof(d));
	rep(k,1,n+1){
	    rep(i,1,n+1){
			rep(j,1,n+1){
				if (d[i][k] < INF && d[k][j] < INF)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]); 
			}
	    }
	}
}

// NOTE: for both floyd warshall and bellman ford, it is easy to reproduce the shortest path and not just its length all it would take is
// a parent array that holds the last vertex which managed to shorten the path for current node. it would be called parent of current node and saved in par.

//DJKSTRA
// if you want to list all the nodes that belong shortest path between src and dest... 
// the find sssp from src and from dest
// all nodes i such that dsrc[i]+ddest[i]=dsrc[dest] belong to some shortest path in graph.

// if you want to list all the edges that belong to some shortest path firstly find all nodes as stated above ...
// secondly perform modified djkstra in which you create a adjaceny list.
// if the edge from s to u shortens dis[u] aur even if its equal to previous value of dis[u] we add s to adj[u]
