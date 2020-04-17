vector<int> v; // the i'th index stores the parent of i if v[i] is positive, if v[i] is negative then i has is its own parent...

int fin(int a){
    vector<int> store;
    while(v[a]>0){
        store.push_back(a);
        a=v[a];
    }
    for(int i=0;i<store.size();i++){
        v[store[i]]=a;
    }
    return a;
}

void unio(int a,int b){
    a=fin(a);
    b=fin(b);
    if(a!=b){
        v[a]+=v[b];
        v[b]=a;
    }
}

int main(){
    v.resize(n+1,-1);
    v[0]=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        unio(a,b);
    }    
}
