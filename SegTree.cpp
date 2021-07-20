int a[200005];
ll t[800005];
 
void build(int v,int tl,int tr){
    if(tl==tr){
        t[v]=a[tl];
    }
    else{
        int tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
 
void update(int v,int tl,int tr,int pos,int val){
    if(tl==tr){
        t[v]=val;
    }
    else{
        int tm=(tl+tr)/2;
        if(tm>=pos){
            update(2*v,tl,tm,pos,val);
        }
        else{
            update(2*v+1,tm+1,tr,pos,val);
        }
        t[v]=min(t[2*v],t[2*v+1]);
    }
}
 
ll query(int v,int tl,int tr,int l,int r){
    if(l>r)return INF;
    if(tl==l && tr==r){
        return t[v];
    }
    int tm=(tl+tr)/2;
    return min(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
}
 
