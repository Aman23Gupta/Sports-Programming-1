/*
1) we have a recurrence relation.
2) we want to express it interms of base terms
3) we try to represent it as sum of products.
4) this allows to convert it into vector/matix multiplication.
5)(my understanding as of now) one of these matrix would have constants, and other the base terms of recurrence relation.
6) now you have a matrix multiplication yeilding value for one term of reccurence relation.
7) if the matrix of constants is a sqaure matrix then we'll be able to multiply them... with each other.
8) inorder to make the matrix of constants square try calculating someother terms of recurrence relation simultaneously.
9) like in fibonacci we calculate fib(n) and fib(n-1). This makes Mat. of Const. square.
10) We can multiply n Mat. of Const. in log(n) time using binary exponentiation.

Where is it used?
We have many DP problems, which can be boiled down to recurrence realtions. We can use this technique to solve those recurrence in log(N).
*/

void matmul(ll m1[10][10],ll m2[10][10],int k){ // 	function for multiplying two sqaure matrices of size k X k. 
    ll res[10][10];
    rep(i,0,k){
        rep(j,0,k){
            res[i][j]=0;
            rep(l,0,k){
                res[i][j]+=mul(m1[i][l],m2[l][j]);
                res[i][j]%=mod;
            }

        }

    }
    rep(i,0,10){ //		after computing result are stored back into matrix m1.	
        rep(j,0,10){
            m1[i][j]=res[i][j];
        }
    }


}

// a fucntion that performs binary exponentiation for matrices.
void matexp(ll mat[10][10],ll cpy[10][10],ll k,ll n){ // As the calculation happens in place results are stored into mat, cpy is to store initial value of mat, n-> exponent, k->dimenstion of sq. matrix
    if(n==0 || n==1)return;
    matexp(mat,cpy,k,n/2);
    matmul(mat,mat,k);
    if(n%2)matmul(mat,cpy,k);
    return;
}
