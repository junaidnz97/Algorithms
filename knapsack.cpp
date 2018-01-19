#include<iostream>
#include<string.h>
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }

int recknapsack(int val[],int wt[],int w,int n)
{

  if(n==0 || w==0)return 0;

  if(wt[n-1]>w)return recknapsack(val,wt,w,n-1);

  else
  {
  	return max(val[n-1]+recknapsack(val,wt,w-wt[n-1],n-1),recknapsack(val,wt,w,n-1));
  }

}


int dpknapsack(int val[],int wt[],int w,int n)
{

	int dp[w+1][n+1];

	memset(dp,0,sizeof(dp));

	int i,j;

	for(i=1;i<=w;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i>=wt[j-1])
			{
				dp[i][j]=max(val[j-1]+dp[i-wt[j-1]][j-1],dp[i][j-1]);
			}
			else
			{
				dp[i][j]=dp[i][j-1];
			}
		}
	}

	//cout<<"0 1 2 3 4 5"<<endl<<endl;

	for (int i = 0; i <=w; ++i)
	{   
        //cout<<i<<" ";
		for (int j= 0; j <=n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[w][n]<<endl;
}

int main()
{


	int val[3]={6,10,12};
	int wt[] = {1, 2, 3};
    int  w = 5;
int n=3;
    cout<<recknapsack(val,wt,w,n)<<endl;
    dpknapsack(val,wt,w,n);
}