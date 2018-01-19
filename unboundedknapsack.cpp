#include<iostream>
#include<string.h>
using namespace std;



int  unboundedKnapsack(int w,int n,int val[],int wt[])
{
	int i,j;

	int dp[w+1];

	memset(dp,0,sizeof(dp));

	for(i=0;i<=w;i++)
	{
		for(j=0;j<n;j++)
		{
			
			if(i>=wt[j])
			dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
		cout<<dp[i]<<endl;

		}
	}

	for(i=0;i<=w;i++)
		cout<<dp[i]<<" ";


}

int main()
{
    int W = 5;
    int val[] = {6, 10,12 };
    int wt[] = {1,2,3};
    int n = 3;
 
     unboundedKnapsack(W, n, val, wt);
 
    return 0;
}