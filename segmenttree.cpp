#include<iostream>
#include<vector>
#include<math.h>
#include<string.h>
using namespace std;

int n;

void addsegtree(vector <int> &dp,int low,int high,int i,int val,int flag)
{

    int mid=(low+high)/2;

    dp[flag]+=val;

    if(low==high)
    {

    	return;
    	

    }

    if(mid>i)
    {
    	addsegtree(dp,low,mid,i,val,2*flag+1);
    	
    }
    else
    {
        
        addsegtree(dp,mid+1,high,i,val,2*flag+2);
    }
}

long long int getsum(vector <int> &dp,int low,int high,int node1,int node2,int flag)
{

   

   if(node1<=low && node2>=high)
   {
   	return dp[flag];
   }

   

   if(node1>high || node2<low)
   {
   	return 0;
   }

   int mid=(low+high)/2;

   return getsum(dp,low,mid,node1,node2,2*flag+1)+getsum(dp,mid+1,high,node1,node2,2*flag+2);


}

int main()
{
	int i,j;
    int q;
	cin>>n>>q;
	    int size=4*n;

	vector <int> dp(size,0);

    for(i=0;i<q;i++)
    {
	

	

	
       
    int uppos,upvalue;
    char c[10];
    cin>>c>>uppos>>upvalue;
    if(strcmp(c,"add")==0)
	addsegtree(dp,0,n-1,uppos-1,upvalue,0);

	
    else
	cout<<getsum(dp,0,n-1,uppos-1,upvalue-1,0)<<endl;

    for(j=0;j<size;j++)
    	cout<<dp[j]<<" ";
    cout<<endl;
    }
	 

}
