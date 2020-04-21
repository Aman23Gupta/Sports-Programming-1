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
/*First, two facts about coprime integers:
Iff a and b are coprime, then ab=lcm(a,b)
Iff a is coprime to both b and c, then a is coprime to bc
It follows from this that a set of distinct integers {a,b,⋯z} is pairwise coprime if its product is equal to its least common multiple.

You can compute the least common multiple by using the following identity:
lcm(a,b,c)=lcm(a,lcm(b,c))
Assuming you have n numbers with k digits each, and multiplying/dividing/modding two numbers is O(1) (which may or may not be a good assumption depending on your model), then:

Calculating the product of your set takes O(n)
Calculating the gcd of two numbers takes O(k)
Calculating the lcm of two numbers thus also takes O(k), by reduction to gcd
So calculating the lcm of your entire set takes O(nk)
Thus, the time complexity of the entire algorithm is O(nk).*/
