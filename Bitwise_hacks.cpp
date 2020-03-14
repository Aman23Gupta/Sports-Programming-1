//x&~(x-1) isolates the lowest set bit
//example
//if x is 100100 the expression would return 000100


//x&(x-1) changes the lowest set bit two zero
//example
//if x is 100100 the expression would return 100000

//to isolate the Most significant set bit the most stable way would be to create a vector containing powers of 2 from 0 to 64.
// then binary search in it.
