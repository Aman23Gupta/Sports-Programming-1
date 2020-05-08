// We are given the natural numbers n and k. All natural numbers from 1 to n are written in a circle.
// First, count the k-th number starting from the first one and delete it. Then k numbers are counted starting from 
// the next one and the k-th one is removed again, and so on. The process stops when one number remains. 
// It is required to find the last number.

// The recurrence relation for this is J{n,k}=(J{(n−1),k}+k−1) modn+1 , with base condition that J{1,k}=1;

// Now if we number n people from 0 to n-1 then this formula simiplifies to J{n,k}=(J{(n−1),k}+k) modn, with base condition that J{1,k}=1;

int josephus(int n,int k) {
    int res=0;
    for(int i=1;i<=n;i++)
      res = (res + k) % i;
    return res + 1; // if you want answers in zero-based indexing then remove this +1
}

// analytical solution for k=2;
// J{n,2}=1+2(n−2^(⌊log2n⌋)) // it is log n base 2 and not log of 2n;

//another implementaion with complexity of O(klogn)
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    if (k == 1)
        return n-1;
    if (k > n)
        return (josephus(n-1, k) + k) % n;
    int cnt = n / k;
    int res = josephus(n - cnt, k);
    res -= n % k;
    if (res < 0)
        res += n;
    else
        res += res / (k - 1);
    return res;
}
