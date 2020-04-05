const int mx=505;
int man_choice[mx][mx];
int woman_choice[mx][mx];
int ranks[mx][mx];
int next_woman[mx];
int matches[mx];
int main()
{
    int t;
    scanf("%d",&t);
    Case(t)
    {
        int n;
        sf("%d",&n);
        for(int it=1;it<=n;it++)
        {
            int i;
            sf("%d",&i);
            for(int j=1;j<=n;j++)
            {
                sf("%d",&woman_choice[i][j]);
            }
        }
        for(int it=1;it<=n;it++)
        {
            int i;
            sf("%d",&i);
            for(int j=1;j<=n;j++)
            {
                sf("%d",&man_choice[i][j]);
            }
        }        
	for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                ranks[i][woman_choice[i][j]]=j;
            }
        }
        mem(matches,0);
        queue<int>q;
        for(int i=1;i<=n;i++)
            q.push(i),next_woman[i]=1;
        while(!q.empty())
        {
            int cur_man=q.front();
            int cur_woman = man_choice[cur_man][next_woman[cur_man]];
            if(matches[cur_woman]==0)
            {
                matches[cur_woman]= cur_man;
                q.pop();
            }
            else if(ranks[cur_woman][cur_man]<ranks[cur_woman][matches[cur_woman]])
            {
                int ex= matches[cur_woman];
                matches[cur_woman]=cur_man;
                q.pop();
                q.push(ex);
            }
            next_woman[cur_man]++;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%d %d\n",matches[i],i);
        }
    }

}
