#include <bits/stdc++.h>
using namespace std;

int constructtree(vector<int>&dp,int arr[],int low,int high,int flag)
{
	//cout<<"hello";
   if(low==high)
   {
   	 dp[flag]=arr[low];
   	 return dp[flag];

   }

   int mid=low+(high-low)/2;
   dp[flag]=min(constructtree(dp,arr,low,mid,2*flag+1),constructtree(dp,arr,mid+1,high,2*flag+2));

   return dp[flag];

}

int findmin(vector<int>&dp,int node1,int node2,int low,int high,int flag)
{
      if(node1>high || node2<low )
      	return INT_MAX;

      if(node1<=low && node2>=high)
      	return dp[flag];

      int mid=low+(high-low)/2;

      return min(findmin(dp,node1,node2,low,mid,2*flag+1),findmin(dp,node1,node2,mid+1,high,2*flag+2));

}

int main()
{
	int arr[] = {1, 3, 2, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    int size=4*n;
    vector<int> dp(size,INT_MAX);

    constructtree(dp,arr,0,5,0);

    for(i=0;i<size;i++)
    {
    	
    	cout<<dp[i]<<" ";
    }
    cout<<endl;

    int node1=0,node2=5;

    cout<<findmin(dp,node1,node2,0,5,0)<<endl;
}