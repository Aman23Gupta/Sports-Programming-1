vector<int> dsu; // the i'th index stores the parent of i if v[i] is positive, if v[i] is negative then i is its own parent...

int fin(int a){
    vector<int> store;
    while(dsu[a]>0){
        store.push_back(a);
        a=dsu[a];
    }
    for(int i=0;i<store.size();i++){
        dsu[store[i]]=a;
    }
    return a;
}

void unio(int a,int b){
    a=fin(a);
    b=fin(b);
    if(a!=b){
        dsu[a]+=dsu[b];
        dsu[b]=a;
    }
}

int main(){
    dsu.resize(n+1,-1);
    dsu[0]=0;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        unio(a,b);
    }    
}
