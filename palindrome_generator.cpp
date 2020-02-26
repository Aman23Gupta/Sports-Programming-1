vector<ll> v;

ll create(long n){
    long temp=n;
    if(temp%2==1)temp/10;
    while(temp!=0){ 
        n=n*10+temp%10;
        temp/=10; 
    }
    return n;
}

void pal(ll limit){ 
    ll num;
    long i=1;
    while((num=create(i))<limit){ 
        v.pb(num);
        i++;
    }
}
