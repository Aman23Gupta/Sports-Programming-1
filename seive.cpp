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
