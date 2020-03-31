void lps(string t,int l[]);

int KMP(string s,string t){
    int n,m;
    n=s.length();
    m=t.length();
    int l[m]={0};
    lps(t,l);
    int i=0,j=0;
    int ans=0;
    while(i<n){
        if(s[i]==t[j]){
            i++;
            j++;
        }
        if(j==m){
            ans++;
            j=l[j-1];
        }
        else if(i<n && s[i]!=t[j]){
            if(j==0){
                i++;
            }
            else{
                j=l[j-1];
            }
        }
    }
    return ans;

}

void lps(string t,int l[]){
    int m=t.length();
    l[0]=0;
    int len=0;
    int i=1;
    while(i<m){
        if(t[i]==t[len]){
            len++;
            l[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len=l[len-1];
            }
            else{
                l[i]=0;
                i++;
            }
        }
    }
}
