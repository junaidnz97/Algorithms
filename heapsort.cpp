#include<iostream>
using namespace std;

int swap(int a[100],int f1,int f2)
{
	
	int temp=a[f1];
	a[f1]=a[f2];
	a[f2]=temp;
}

int heapify(int a[100],int i,int n)
{
	
	int left=2*i+1;
	int right=2*i+2;
	
	int largest=i;
	
	if(left<n && a[left]>a[i])
	{
		largest=left;
	}
	
	if(right<n && a[right]>a[largest])
	{
		largest=right;
	}
	
	if(largest!=i)
	{
		swap(a,largest,i);
		
		heapify(a,largest,n);
	}
	
}

int heapsort(int a[100],int n)
{
	
	
	int i;
	
	for(i=n-1/2;i>=0;i--)
	{
		heapify(a,i,n);
	}
	
	
	for(i=n-1;i>=0;i--)
	{
		swap(a,0,i);
		
		
		heapify(a,0,i);
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
	
	
	heapsort(a,n);
	
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	
}
