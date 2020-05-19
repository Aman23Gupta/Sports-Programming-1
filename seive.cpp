//CONTENTS
//1) seive of Eratosthenes
//2) finding prime factorization in sqrt(n)
//3) Modulo Inverse
//4) SPF - finding prime factorization in log(n) after precomputation.
vector<bool> p(5000005,true);

void seive(){
    p[0]=false;
    p[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!p[i])continue;
        for(int j=i*i;j<n;j+=i){
            p[j]=false;
        }
    }
}
---------------------------------------------------------------------------------
    
// function for prime factorization
void primeFactors(int n) 
{ 
    // Print the number of 2s that divide n 
    while (n%2 == 0) 
    { 
        printf("%d ", 2); 
        n = n/2; 
    } 
  
    // n must be odd at this point.  So we can skip  
    // one element (Note i = i +2) 
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        // While i divides n, print i and divide n 
        while (n%i == 0) 
        { 
            printf("%d ", i); 
            n = n/i; 
        } 
    } 
  
    // This condition is to handle the case when n  
    // is a prime number greater than 2 
    if (n > 2) 
        printf ("%d ", n); 
}
---------------------------------------------------------------------------------
    
//to find modulo inverse of numbers till N
const int mod=998244353;
int inv[N];
inv[1] = 1;
for(int i = 2; i < N; ++i)
    inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
---------------------------------------------------------------------------------
//smallest prime factor
vector<int> spf(10000005,0);
void SPF(int n) {   
	spf[1] = 1; 
    for (int i = 2; i <= n; i++){ 
        if (spf[i] == 0){ 
            spf[i] = i;  
            for (int j = 2*i; j <= n; j += i) 
                if (spf[j] == 0) 
                   spf[j] = i; 
        } 
    }
} 
