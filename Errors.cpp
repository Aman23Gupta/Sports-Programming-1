// when multipying two long numbers such that the result can be of longlong type then making the LHS equal to long long wouldn't be enough
// individual operands on RHS should also be made long long

// if there is no chance of working with negatives then you should use unsigned for extra range...

//if question used one based indexing then you too, use one based indexing to avoid confusion.

// whenever you use for(auto u:v) and u can be some container like vector, set, etc. use ampersand i.e. for(auto &u:v)

// it is always efficient to declare global variable and clear them for every test case than redeclaring for each test case.

// handling structures of int is faster than handling long long so if you are tight on time constraints and int would suffice then stick to
// int

/* I've noticed that for many problems having a greedy solution sometimes we have two options... both of which seem to be correct like:-
1) in problems of maximizing activites done given the period of time they would take... whether is should be sorted on the basis of 
    starting time or ending time...
2) in SPOJ MDOLLS problem i went forward with finding the just smaller doll in all the remaining doll but the other way and the correct one
    was to find the just greater doll in the answer list for every doll remaining in the input list.
3) https://discuss.codechef.com/t/rrdag-editorial/6427 in this problem as well as depicted by author in end of the editorial that instead
    of beginning with 0 in-deg and then making edges with all others the correct way is to begin with largest 0 out-deg and make edges from 
    all the remaining vertices to this vertex.
Whenever a greedy solution strikes and two possible ways show up try proving and comming up with counter-examples.
*/
