//ETF
// phi(p)=p-1 where p is a prime.
// phi(n), it is a function that returns the number of positive integers lesser than 'n', which are also co-prime to it.
// phi(p^x)=p^x - all numbers from 1 tp p^x that are not co-prime with p^x;
// we know that the answer to the second part would be all multiples of p, hence phi(p^x)=p^x-(p^x)/p=p^x-p^(x-1);

//CRT
// We can use CRT to find 'X' such that we are given a list of pairwise co-primes p1,p2,p3...pn and the remainder that we obtain when X is
// divided by  each of them as r1,r2,r3...rn.

// X=( r1*P1*x1 + r2*P2*x2 + r3*P3*x3 + ...... rn*Pn*xn )mod P 
// where ri => are the given remainders
// Pi=P/pi where P=p1*p2*p3...*pn
// and xi is modulo inverse of Pi. i.e xi*Pi=1mod(pi)


//Algorithm for checking if a list of integers is pairwise coprime
//https://cs.stackexchange.com/questions/93030/algorithm-for-checking-if-a-list-of-integers-is-pairwise-coprime
bool pairwisePrime(vector<ll> &v, int n){
    ll lcm=v[0];
    ll prod=v[0];
    rep(i,1,n){
        lcm=(lcm*v[i])/__gcd(lcm,v[i]);
        prod*=v[i];
    }
    if(lcm==prod)return true;
    else return false;
}
