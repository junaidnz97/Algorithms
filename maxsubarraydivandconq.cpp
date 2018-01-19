#include<iostream>
#include<limits.h>
using namespace std;

int max(int a,int b )
{
	if(a>b)return a;
	
	else return b;
}

int max(int a,int b,int c)
{
	
	return max(max(a,b),c);
}

int maxcross(int a[100],int low,int mid,int high)
{
	
	int i;
	
	int leftsum=INT_MIN,sum=0;
	for(i=mid;i>=low;i--)
	{
		sum=sum+a[i];
		
		if(sum>leftsum) leftsum=sum;
	}
	
	sum=0;
	int rightsum=INT_MIN;
	
	for(i=mid+1;i<=high;i++)
	{
		sum=sum+a[i];
		
		if(sum>rightsum) rightsum=sum;
	}
	
	return leftsum+rightsum;
	
	
}

int maxsubarray(int a[100],int low,int high)
{
	if(low==high)return a[low];
	
	if(low<=high)
	{
		int mid=(low+high)/2;
		
		max(maxsubarray(a,low,mid),maxsubarray(a,mid+1,high),maxcross(a,low,mid,high));
	}
}


int main()
{
	int n;
	cin>>n;
	
	int i,a[100];
	
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	cout<<maxsubarray(a,0,n-1);
	
}
