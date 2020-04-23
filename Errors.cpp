// when multipying two long numbers such that the result can be of longlong type then making the LHS equal to long long wouldn't be enough
// individual operands on RHS should also be made long long

// if there is no chance of working with negatives then you should use unsigned for extra range...

//if question used one based indexing then you too, use one based indexing to avoid confusion.

// whenever you use for(auto u:v) and u can be some container like vector, set, etc. use ampersand i.e. for(auto &u:v)

// it is always efficient to declare global variable and clear them for every test case than redeclaring for each test case.

// handling structures of int is faster than handling long long so if you are tight on time constraints and int would suffice then stick to
// int
