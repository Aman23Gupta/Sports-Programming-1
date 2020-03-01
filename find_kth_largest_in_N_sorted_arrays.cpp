// this file contains the implementation of concepts of these video  https://www.youtube.com/watch?v=Q3JUfHpffIg
//url to code   https://ideone.com/ntm2oR
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
//NMax 100
int st[100],en[100],mid[100];
vector<vi> arr;
int n,k;
int getmaxind()
{
  int mx=INT_MIN,ind=-1;
  for(int i=0;i<n;i++)
  {
    if((en[i]-st[i])>mx)
    {
      mx=(en[i]-st[i]);
      ind=i;
    }
  }
  assert(ind>-1);
  return ind;
}
int binarysearch(int lo,int hi,int ele,int ind)
{
  int mid;
  while(lo<=hi)
  {
    mid=lo+(hi-lo)/2;
    if(arr[ind][mid]==ele)  return mid;
    else  if (arr[ind][mid]<ele)  lo=mid+1;
    else    hi=mid-1;
  }
  return lo;
}
int cnt=0;
int Kth()
{
  int lte=0,mxind,ele;
  while(lte!=k)
  {
    lte=0;
    mxind=getmaxind();
    mid[mxind]=(st[mxind]+en[mxind])/2;
    ele=arr[mxind][mid[mxind]];
    for(int i=0;i<n;i++)
    {
      mid[i]=binarysearch(st[i],en[i],ele,i);
      lte+=mid[i];
    }
    lte++;
    if(lte==k)  return ele;
    else if(lte<k)
    {
      mid[mxind]+=1;
      for(int i=0;i<n;i++)  st[i]=mid[i];

    }
    else
    {
      mid[mxind]-=1;
      for(int i=0;i<n;i++)  en[i]=mid[i];
    }
  }
}
int main()
{
  int x;
  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    st[i]=0;
    vi inp(x);
    for(int j=0;j<x;j++)  cin>>inp[j];
    arr.push_back(inp);
    en[i]=inp.size()-1;
  }
  cout<<Kth()<<"\n";
	return 0;
}
