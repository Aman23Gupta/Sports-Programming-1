/*
CONTENTS
1) Handshaking Theorem
2) Euler Path and Euler Ckt


Handshaking Theorem - In every graph, the sum of the degrees of all vertices equals twice the number of edges.

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
