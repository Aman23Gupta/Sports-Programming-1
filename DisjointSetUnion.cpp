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

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class DSU{
private:
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
    }
    void setParent(int ind,int val){
        parent[ind]=val;
    }
    int findFunc(int ind){
        if(ind!=parent[ind]){
            parent[ind]=findFunc(parent[ind]);
        }
        return parent[ind];
    }
    bool unionFunc(int ind1, int ind2){
        int parentInd1=findFunc(ind1);
        int parentInd2=findFunc(ind2);
        if(parentInd1==parentInd2){
            return false;
        }
        
        parent[parentInd1]=parentInd2;
        return true;
    }
};

