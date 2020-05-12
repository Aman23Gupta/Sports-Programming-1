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
An Euler circuit is a circuit that uses every edge of a graph exactly once
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
*/
